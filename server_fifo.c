#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define FIFO "fifo.ll"
#define MAXBUFF 80

void main() {
  int readfd, n;
  char buff[MAXBUFF]; // buffer for reading from FIFO

  if (mknod(FIFO, S_IFIFO | 0666, 0) < 0) {
    printf("Cant create FIFO\n");
    exit(1);
  }
  if ((readfd = open(FIFO, O_RDONLY) < 0)) {
    printf("Cant open FIFI\n");
    exit(1);
  }

  while ((n = read(readfd, buff, MAXBUFF)) > 0) {
    printf(n);
    if (write(1, buff, n) != n) {
      printf("Erro output\n");
      exit(1);
    }
  }
  printf("After cycle");
  close(readfd);
  exit(0);
}
