#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE(x)       (sizeof(x) / sizeof((x)[0]))

const char *help[] = {
	"-h, --help				Display this information.",
	"-s, --source-location PATH(,PATH2...)	If PATH is a directory,",
	"					all files inside it will",
	"					be concerned.",
	"-b, --binary-name			binary name to execute",
	"-c, --compile-command			command to compile",
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

int main(int argc, char **argv)
{
	if (argc < 2 || strcmp(argv[1], "--help") || strcmp(argv[1], "-h"))
		return usage(argv);
	return EXIT_SUCCESS;
}
