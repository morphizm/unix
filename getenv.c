#include <stdlib.h>
// char *getenv(const char *string);
// int putenv(const char *string);
#include <stddef.h>
#include <stdio.h>
main(int argc, char *argv[]) {
  char *term;
  char buf[200], var[200];
  if ((term = getenv("TERM") == NULL)) {
    printf("TERM is not defined, enter a value: ");
    gets(buf);
    sprintf(var, "TERM=%s", buf);
    putenv(var);
    printf("%s\n", var);
  } else {
    printf("TERM=%s. Change? [N]", getenv("TERM"));
    gets(buf);
    if (buf[0] == 'Y' || buf[0] == 'y') {
      printf("TERM=");
      gets(buf);
      sprintf(var, "TERM=%s", buf);
      putenv(var);
      printf("new %s\n", var);
    }
  }
}
