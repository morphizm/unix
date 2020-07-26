#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#define BUFSZ 256

// get name of symlink
main(int argc, char *argv[]) {
  char buf[BUFSZ + 1];
  int nread, fd;
  printf("read symbolic link\n");
  nread = readlink(argv[1], buf, BUFSZ);
  if (nread < 0) {
    perror("readlink");
    exit(1);
  }
  buf[nread] = '\0';
  printf("symbolic link:\n %s\n", buf);
  printf("read a target file");
  fd = open(argv[1], O_RDONLY);
  if (fd < 0) {
    perror("open");
    exit(2);
  }
  nread = read(fd, buf, BUFSZ);
  if (nread < 0) {
    perror("read");
    exit(3);
  }
  buf[nread] = '\0';
  printf("Target file:\n %s\n", buf);
  close(fd);
  exit(0);
}
