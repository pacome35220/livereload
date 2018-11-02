#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <sys/inotify.h>
#include <unistd.h>
#include "livereload.h"

#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

void full_start_app(struct flag_option *flags)
{
	if (compile(flags->compile_command) == EXIT_SUCCESS)
		if (execute(flags->exec_command) == EXIT_SUCCESS)
			color_log(GREEN, CLEAN_EXIT);
		else
			color_log(RED, CRASH_EXIT);
	else
		color_log(RED, CRASH_COMPILE);
	color_reset();
	fflush(stdout);
}

static void check_file(struct inotify_event *i, struct flag_option *flags)
{
	i->name[i->len] = '\0';
	if (i->mask & IN_CLOSE_WRITE) {
		if (!strstr(i->name, ".o")) {
			color_log(GREEN, RESTART);
			full_start_app(flags);
		}
	}
}

void run_livereload(int inotify_fd, struct flag_option *flags)
{
	ssize_t nread;
	char buf[BUF_LEN];
	struct inotify_event *event;

	for (;;) {
		nread = read(inotify_fd, buf, sizeof(buf));
		if (nread < 0)
			continue;
		for (char *tmp = buf; tmp < buf + nread; ) {
			event = (struct inotify_event *) tmp;
			check_file(event, flags);
			tmp += sizeof(struct inotify_event) + event->len;
		}
	}
}
