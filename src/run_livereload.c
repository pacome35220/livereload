#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <sys/inotify.h>
#include <unistd.h>
#include "flags.h"

#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

static void displayInotifyEvent(struct inotify_event *i, struct flag_option *flags)
{
	if (i->len > 0 && !strstr(i->name, ".o")) {
		if (i->mask & IN_CLOSE_WRITE)
			compile(flags);
		printf("\n");
	}
}

void run_livereload(int inotify_fd, struct flag_option *flags)
{
	char buf[BUF_LEN];
	ssize_t nread;
	struct inotify_event *event;

	for (;;) {
		nread = read(inotify_fd, buf, sizeof(buf));
		assert(nread > 0);
		for (char *tmp = buf; tmp < buf + nread; ) {
			event = (struct inotify_event *) tmp;
			displayInotifyEvent(event, flags);
			tmp += sizeof(struct inotify_event) + event->len;
		}
	}
}
