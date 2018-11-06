#include <stdlib.h>
#include <unistd.h>
#include "livereload.h"

static void destroy_flags(struct flag_option *flags)
{
	free(flags->source_path);
	free(flags->execute);
	free(flags->compile);
}

int main(int argc, char **argv)
{
	destructor(destroy_flags) struct flag_option flags = {
		.source_path = NULL,
		.execute = NULL,
		.compile = NULL
	};
	int inotify_fd;

	if (parse_options(argc, argv, &flags) == -1)
		return usage(argv);
	inotify_fd = inotify_init();
	if (inotify_fd == -1)
		return EXIT_FAILURE;
	add_watched_files(inotify_fd, flags.source_path);
	color_log(YELLOW, "Starting livereload\n");
	full_start_app(&flags);
	run_livereload(inotify_fd, &flags);
	return EXIT_SUCCESS;
}
