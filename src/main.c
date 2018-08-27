#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

#define ARRAY_SIZE(x)       (sizeof(x) / sizeof((x)[0]))

char **my_str_to_word_array(char *str, const char *delim);

const char *help[] = {
	"-h, --help				Display this information.",
	"-s, --source-path PATH(,PATH2...)	If PATH is a directory,",
	"					all files inside it will",
	"					be concerned.",
	"-b, --binary-name			binary name to execute",
	"-c, --compile-command			command to compile",
};

const char *optstring = "hc:b:s:";
const struct option longopts[] = {
	{"help",		no_argument,		NULL, 'h'},
	{"compile-command",	required_argument,	NULL, 'c'},
	{"binary-name",		required_argument,	NULL, 'b'},
	{"source-path",	required_argument,	NULL, 's'},
	{NULL, 0, 0, '\0'}
};

struct flag_option {
	char	**source_path;
	char	*binary_name;
	char	*compile_command;
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

int parse_options(int argc, char **argv, struct flag_option *flags)
{
	int opt = 0;

	while (opt != -1) {
		opt = getopt_long(argc, argv, optstring, longopts, NULL);
		if (opt == '?' || opt == 'h')
			return -1;
		if (opt == 's') {
			flags->source_path = my_str_to_word_array(optarg, ",");
			if (!flags->source_path)
				return -1;
		} else if (opt == 'b') {
			flags->binary_name = strdup(optarg);
			if (!flags->binary_name)
				return -1;
		} else if (opt == 'c') {
			flags->compile_command = strdup(optarg);
			if (!flags->compile_command)
				return -1;
		}
	}
	return -(flags->source_path == NULL || flags->binary_name == NULL ||
		 flags->compile_command == NULL);
}

int main(int argc, char **argv)
{
	struct flag_option flags = {
		.source_path = NULL,
		.binary_name = NULL,
		.compile_command = NULL
	};

	if (parse_options(argc, argv, &flags) == -1)
		return usage(argv);
	printf("compile_command: %s\n", flags.compile_command);
	printf("binary_name: %s\n", flags.binary_name);
	printf("source_path:\n");
	for (int i = 0; flags.source_path[i] != NULL; i++)
		printf("%s | ", flags.source_path[i]);
	puts("");
	return EXIT_SUCCESS;
}
