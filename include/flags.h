#pragma once

struct flag_option {
	char    **source_path;
	char    **exec_command;
	char    **compile_command;
};

int parse_options(int argc, char **argv, struct flag_option *flags);
