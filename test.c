#include <stdio.h>
#include <unistd.h>

main() {
  // fd, string, bytes
  write(1, "Hello\n", 6);
  printf("Hello\n");
}
