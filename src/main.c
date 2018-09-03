#include <stdio.h>
#include <stdlib.h>
#include "flags.h"
#include "livereload.h"

void destroy_flags(struct flag_option *flags)
{
	free(flags->source_path);
	free(flags->binary_name);
	free(flags->compile_command);
}

int main(int argc, char **argv)
{
	destructor(destroy_flags) struct flag_option flags = {
		.source_path = NULL,
		.binary_name = NULL,
		.compile_command = NULL
	};

	if (parse_options(argc, argv, &flags) == -1)
		return usage(argv);
	return EXIT_SUCCESS;
}
