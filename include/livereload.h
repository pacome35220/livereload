#pragma once

#include "flags.h"

#define ARRAY_SIZE(x)		(sizeof(x) / sizeof((x)[0]))
#define destructor(destructor)	__attribute__((cleanup(destructor)))

#define WATCH_MASK		IN_OPEN | IN_CREATE | IN_MODIFY |	\
				IN_DELETE | IN_CLOSE_WRITE

int	usage(char **argv);
void	add_watched_files(int inotify_fd, char **source_path);
void	run_livereload(int inotify_fd, struct flag_option *flags);
