#include <fcntl.h>

main() {
  close(1);
  int fd = open("log", O_WRONLY | O_CREAT | O_TRUNC);
  dup2(fd, 2);
}
