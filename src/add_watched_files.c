#define _XOPEN_SOURCE 500
#include <ftw.h>
#include "livereload.h"

int global_inotify_fd;

static int callback(const char *fpath,
		    __attribute__((unused)) const struct stat *sb,
		    int tflag,
		    __attribute__((unused)) struct FTW *ftwbuf)
{
	if (tflag == FTW_D)
		inotify_add_watch(global_inotify_fd, fpath, WATCH_MASK);
	return 0;
}

void add_watched_files(int inotify_fd, char **source_path)
{
	struct stat file;

	global_inotify_fd = inotify_fd;
	for (size_t i = 0; source_path[i] != NULL; i++) {
		if (stat(source_path[i], &file) == -1)
			fprintf(stderr, BAD_SOURCE, source_path[i]);
		else if (S_ISDIR(file.st_mode))
			nftw(source_path[i], callback, 20, 0);
		else
			inotify_add_watch(inotify_fd, source_path[i], WATCH_MASK);
	}
}
