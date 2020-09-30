#include <linux/config.h>
#include <linux/wrapper.h>
#include <sched.h>
#include <fcntl.h>

int fd;
int change() {
  close(fd);
  _exit(0);
}

int main(int argc, char *argv[]) {
  void **child_stack;
  char tmp;
  fd = open("file.data", O_CREAT);
  child_stack = (void **) malloc(16384);
  clone(change, &child_stack, CLONE_FILES, **);
  sleep(1);
  if (read(fd, &tmp, 1) < 1) {
    perror("FILE read error");
    exit(1);
  }
  printf("Read successful from the title \n");
  return 0;
}
