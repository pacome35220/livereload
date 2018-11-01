#include <unistd.h>
#include <wait.h>
#include "livereload.h"

static void print_exec_log(char **exec_command)
{
	color_log(GREEN, "executing : `");
	for (int i = 0; exec_command[i] != NULL; i++) {
		if (exec_command[i + 1] != NULL)
			printf("%s ", exec_command[i]);
		else
			printf("%s", exec_command[i]);
	}
	printf("`\n");
	color_reset();
	fflush(stdout);
}

int execute(char **exec_command)
{
	pid_t pid;
	int status;

	print_exec_log(exec_command);
	pid = fork();
	if (pid == -1)
		return 1;
	else if (pid == 0)
		execvp(exec_command[0], exec_command);
	else
		wait(&status);
	return status;
}
