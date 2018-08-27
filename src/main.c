#include <stdio.h>
#include <string.h>

#define ARRAY_SIZE(x)       (sizeof(x) / sizeof((x)[0]))

const char *help[] = {
	"-h, --help				Display this information.",
	"-c, --compile-command			command to compile",
	"-b, --binary-name			binary name to execute",
	"-s, --source-location PATH(,PATH2...)	If PATH is a directory,\n\
						all files inside it will\n\
						be concerned."
};

int usage(char **argv)
{
	fprintf(stderr, "%s [OPTIONS]\n\n", argv[0]);
	fprintf(stderr, "OPTIONS:\n");
	for (size_t i = 0; i < ARRAY_SIZE(help); i++)
		fprintf(stderr, "\t%s\n\n", help[i]);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2 || strcmp(argv[1], "--help") || strcmp(argv[1], "-h"))
		return usage(argv);
	return 0;
}
