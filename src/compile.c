#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include "flags.h"

void print_compile_log(struct flag_option *flags)
{
	printf("Change file are detected !\n");
	printf("Recompiling with : `");
	for (int i = 0; flags->compile_command[i] != NULL; i++) {
		if (flags->compile_command[i + 1] != NULL)
			printf("%s ", flags->compile_command[i]);
		else
			printf("%s", flags->compile_command[i]);
	}
	printf("`\n");
}

int compile(struct flag_option *flags)
{
	pid_t pid;
	int status;

	print_compile_log(flags);
	pid = fork();
	if (pid == -1)
		return 1;
	else if (pid == 0)
		execvp(flags->compile_command[0], flags->compile_command);
	else
		wait(&status);
	return status;
}
