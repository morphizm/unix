#include <errno.h>
#include <stdio.h>
void main(int argc, char *argv[]) {
  // printf(strerror(ENOENT));
  printf(stderr, "ENOMEM: %s\n", strerror(ENOMEM));
  errno = ENOEXEC;

  perror(argv[0]);
}
