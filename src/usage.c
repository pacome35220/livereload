#include <stdlib.h>
#include "livereload.h"

const char *help[] = {
	"-h, --help				Display this information.",
	"-s, --source-path PATH(,PATH2...)	If PATH is a directory,",
	"					all files inside it will",
	"					be concerned.",
	"-e, --execute				command to execute",
	"-c, --compile				command to compile (optional)",
};

int usage(char **argv)
{
	fprintf(stderr, "USAGE:\n");
	fprintf(stderr, "\t%s [OPTIONS]\n\n", argv[0]);
	fprintf(stderr, "OPTIONS:\n");
	for (size_t i = 0; i < ARRAY_SIZE(help); i++)
		fprintf(stderr, "\t%s\n", help[i]);
	return EXIT_FAILURE;
}
