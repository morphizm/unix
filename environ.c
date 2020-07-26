#include <stddef.h>
extern char **environ;

main(int argc, char *argv[]) {
  int i;
  printf("Numbers of arguments send to programm %s, equal %d\n", argv[0], argc);
  for (i = 1; i < argc; i++) {
    printf("argv[%d] = %s\n", i, argv[i]);
  }
  for (i = 0; i < 8; i++) {
    if (environ[i] != NULL) {
      printf("environ[%d] : %s\n", i, environ[i]);
    }
  }
}
