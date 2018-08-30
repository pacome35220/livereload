# c_livereload

c_livereload is a tool that helps C/C++ developpement by automatically compile and run program when file changes detected.

### Based on inotify

The inotify API provides a mechanism for monitoring filesystem events. Inotify can be used to monitor individual files, or to monitor directories. When a directory is monitored, inotify will return events for the directory itself, and for files inside the directory (from `man 7 inotify`).
You can read some good documentation on :
- https://en.wikipedia.org/wiki/Inotify
- https://www.thegeekstuff.com/2010/04/inotify-c-program-example/
- https://www.linuxjournal.com/article/8478

Thanks to [John McCutchan](http://johnmccutchan.com/) for this API.
