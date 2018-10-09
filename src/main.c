#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include "flags.h"
#include "livereload.h"

static void destroy_flags(struct flag_option *flags)
{
	free(flags->source_path);
	free(flags->exec_command);
	free(flags->compile_command);
}

int main(int argc, char **argv)
{
	destructor(destroy_flags) struct flag_option flags = {
		.source_path = NULL,
		.exec_command = NULL,
		.compile_command = NULL
	};
	int inotify_fd;

	if (parse_options(argc, argv, &flags) == -1)
		return usage(argv);
	inotify_fd = inotify_init();
	if (inotify_fd == -1)
		return EXIT_FAILURE;
	add_watched_files(inotify_fd, flags.source_path);
	run_livereload(inotify_fd, &flags);
	return EXIT_SUCCESS;
}
