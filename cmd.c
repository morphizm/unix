#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
extern char ** environ;
#define CMDSIZE 80

#define CD 1
#define ECHO 2
#define EXEC 3
#define PROGRAM 1000

// int parse_command(char *cmdbuf, char *path, char **arguments);

int main() {
  char cmd[CMDSIZE];
  int command;
  int stat_loc;
  char **args;
  // char cmdpath[MAXPATH];
  char cmdpath[200];
  while (1) {
    write(1, "$ ", 2);
    char cmdsize = read(0, cmd, CMDSIZE);
    cmd[cmdsize-1] = '\0';
    // command = parse_command(cmd, cmdpath, args);
    command = 1;
    switch (command) {
      case (CD): chdir(args[0]); break;
      case (ECHO):
        write(1, args[0], strlen(args[0]));
        break;
      case(EXEC):
        // execve(path, args, environ);
        write(2, "shell: cannot execute", 21);
        break;
      // case(PROGRAM):
      //   int pid = fork();
      //   if (pid < 0) {
      //     write(2, "shell: cannot fork", 18);
      //   } else if (pid == 0) {
      //     // execve(path, args, environ);
      //     write(2, "shell: cannot execute", 21);
      //   } else {
      //     wait(&stat_loc);
      //     break;
      //   }
    }
  }
}
