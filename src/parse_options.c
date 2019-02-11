#include <getopt.h>
#include <string.h>
#include "livereload.h"

const char *optstring = "hc:e:s:";
const struct option longopts[] = {
	{"help",		no_argument,		NULL, 'h'},
	{"compile-command",	required_argument,	NULL, 'c'},
	{"exec-command",	required_argument,	NULL, 'e'},
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
			flags->source_path = explode(optarg, ",");
			if (!flags->source_path)
				return -1;
		} else if (opt == 'e') {
			flags->execute = explode(optarg, " \t");
			if (!flags->execute || !*flags->execute)
				return -1;
		} else if (opt == 'c') {
			flags->compile = explode(optarg, " \t");
			if (!flags->compile || !*flags->compile)
				return -1;
		}
	}
	return flags->source_path && flags->execute ? 0 : -1;
}
