#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define FIFO "fifo.ll"

main() {
  int writefd, n;
  if ((writefd = open(FIFO, O_WRONLY)) < 0) {
    printf("Cant open FIFO\n");
    exit(1);
  }
  if (write(writefd, "Hello\n", 6) != 6) {
    printf("Error input\n");
    exit(1);
  }
  close(writefd);
  if (unlink(FIFO) < 0) {
    printf("Cant remove FIFO\n");
    exit(1);
  }
  exit(0);
}
