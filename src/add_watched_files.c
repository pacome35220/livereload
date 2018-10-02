#include <assert.h>
#include <stddef.h>
#include <sys/inotify.h>
#include "livereload.h"

void add_watched_files(int inotify_fd, char **source_path)
{
	int tmp;

	assert(source_path != NULL);
	assert(*source_path != NULL);
	for (size_t i = 0; source_path[i] != NULL; i++) {
		tmp = inotify_add_watch(inotify_fd, source_path[i], WATCH_MASK);
		assert(tmp != -1);
	}
}
