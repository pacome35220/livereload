#include "livereload.h"

void add_watched_files(int inotify_fd, char **source_path)
{
	int tmp;

	for (size_t i = 0; source_path[i] != NULL; i++) {
		tmp = inotify_add_watch(inotify_fd, source_path[i], WATCH_MASK);
		if (tmp == -1)
			fprintf(stderr, BAD_SOURCE, source_path[i]);
	}
}
