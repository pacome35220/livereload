#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <sys/inotify.h>
#include <unistd.h>
#include "flags.h"

#define BUF_LEN (10 * (sizeof(struct inotify_event) + NAME_MAX + 1))

static void displayInotifyEvent(struct inotify_event *i)
{
	if (i->mask & IN_OPEN)
		printf("mask = IN_OPEN ");
	if (i->mask & IN_CREATE)
		printf("mask = IN_CREATE ");
	if (i->mask & IN_MODIFY)
		printf("mask = IN_MODIFY ");
	if (i->mask & IN_DELETE)
		printf("mask = IN_DELETE ");
	if (i->mask & IN_CLOSE_WRITE)
		printf("mask = IN_CLOSE_WRITE ");
	printf("\n");
	if (i->len > 0)
		printf("        name = %s\n", i->name);
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
			displayInotifyEvent(event);
			tmp += sizeof(struct inotify_event) + event->len;
		}
	}

}
