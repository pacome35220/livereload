#include <stdio.h>
#include <string.h>

const char *help[] =
{
	"-c, --compile-command			command to compile",
	"-b, --binary-name			binary name to execute",
	"-s, --source-location PATH(,PATH2...)	sources location to watch,\n\
						If PATH is a directory,	\n\
						all files inside it will \n\
						be concerned."
};

#define SIZEOF(x)       (sizeof(x) / sizeof(x[0]))

int usage(char **argv)
{
	fprintf(stderr, "%s [OPTIONS]\n\n", argv[0]);
	fprintf(stderr, "OPTIONS:\n");
	for (size_t i = 0; i < SIZEOF(help); i++)
		fprintf(stderr, "\t%s\n", help[i]);
	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2 || strcmp(argv[1], "--help") || strcmp(argv[1], "-h"))
		return usage(argv);
	return 0;
}
