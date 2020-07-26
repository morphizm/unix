#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

main() {
  int fd;
  fd = creat("my_life", S_IRUSR|S_IWUSR|S_IXUSR);
  system("ls -l my_life");
  fchmod(fd, S_IRWXU|S_ISUID);
  system("ls -l my_life");
  fchmod(fd, S_IRWXU|S_IXOTH|S_ISVTX);
  system("ls -l my_life");
  fchmod(fd, S_IRWXU|S_ISGID|S_IXGRP);
  system("ls -l my_life");
}
