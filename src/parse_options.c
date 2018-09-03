#include <getopt.h>
#include <string.h>
#include "flags.h"
#include "my.h"

const char *optstring = "hc:b:s:";
const struct option longopts[] = {
	{"help",		no_argument,		NULL, 'h'},
	{"compile-command",	required_argument,	NULL, 'c'},
	{"binary-name",		required_argument,	NULL, 'b'},
	{"source-path",		required_argument,	NULL, 's'},
	{NULL, 0, 0, '\0'}
};

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
	return flags->source_path &&
		flags->binary_name && flags->compile_command;
}
