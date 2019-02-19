#pragma once

#include <limits.h>
#include <stdio.h>
#include <sys/inotify.h>
#include "flags.h"

#define WATCH_MASK		(IN_CLOSE_WRITE)
#define DEFAULT			("\e[00m")
#define RED			("\e[31m")
#define GREEN			("\e[32m")
#define YELLOW			("\e[33m")
#define RESTART			("restarting due to changes...\n")
#define CLEAN_EXIT		("clean exit - waiting for changes\n")
#define CRASH_EXIT		("app crashed - waiting for file changes...\n")
#define CRASH_COMPILE		("compilation failed - can't execute...\n")
#define BAD_SOURCE		("'%s': No such file or directory\n")
#define NB_EVENT		(10)
#define BUF_LEN			(NB_EVENT * (sizeof(struct inotify_event) + \
					     NAME_MAX + 1))

#define color_log(color, str)	(printf("%s[livereload] %s", color, str))
#define color_reset()		(printf(DEFAULT))
#define ARRAY_SIZE(arr)		(sizeof(arr) / sizeof((arr)[0]))
#define destructor(destructor)	__attribute__((cleanup(destructor)))

char	**explode(char *str, const char *delim);
int	usage(char **argv);
void	add_watched_files(int inotify_fd, char **source_path);
void	run_livereload(int inotify_fd, struct flag_option *flags);
int	exec_command(char *exec_command, void (*func)(char *));
void	print_compile_log(char *compile_command);
void	print_exec_log(char *exec_command);
void	full_start_app(struct flag_option *flags);
