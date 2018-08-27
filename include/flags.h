#pragma once

struct flag_option {
	char    **source_path;
	char    *binary_name;
	char    *compile_command;
};

int parse_options(int argc, char **argv, struct flag_option *flags);
