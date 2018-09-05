#include <assert.h>
#include <sys/inotify.h>
#include "livereload.h"

void add_watched_file(int inotify_fd, char *source_path)
{
	int watched_fd;

	watched_fd = inotify_add_watch(inotify_fd, source_path, WATCH_MASK);
	assert(watched_fd != -1);
}
