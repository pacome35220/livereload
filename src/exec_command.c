#include <stdlib.h>
#include "livereload.h"

void print_exec_log(char *exec_command)
{
	color_log(GREEN, "executing : `");
	printf("%s", exec_command);
	printf("`\n");
	color_reset();
	fflush(stdout);
}

void print_compile_log(char *compile_command)
{
	color_log(GREEN, "compiling with : `");
	printf("%s", compile_command);
	printf("`\n");
	color_reset();
	fflush(stdout);
}

int exec_command(char *exec_command, void (*func)(char *))
{
	char *buf;
	int size;
	int ret;

	func(exec_command);
	size = snprintf(NULL, 0, "bash -c \"%s\"", exec_command);
	if (size < 0)
		return 1;
	buf = malloc(sizeof(char) * (size + 1));
	if (!buf)
		return 1;
	if (snprintf(buf, size + 1, "bash -c \"%s\"", exec_command) < 0)
		return 1;
	ret = system(buf);
	free(buf);
	return ret;
}
