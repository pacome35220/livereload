#pragma once

struct flag_option {
	char    **source_path;
	char    **execute;
	char    **compile;
};

int parse_options(int argc, char **argv, struct flag_option *flags);
