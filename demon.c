#include <stdio.h>
#include <syslog.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/resource.h>

int main(int argc, char **argv) {
  int fd;
  struct rlimit flim;
  /*
If parent = init, not worry about terminal signals.
Need ignore - SIGTTOU, SIGTTIN, SIGTSTP
  */
  if (getppid() != 1) {
    signal(SIGTTOU, SIG_IGN);
    signal(SIGTTIN, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
  }

  if (fork() != 0) {
    exit(0);
  }
  setsid();

  getrlimit(RLIMIT_NOFILE, &flim);
  for (fd = 0; fd < flim.rlim_max; fd += 1) {
    close(fd);
  }
  chdir("/");

  openlog("Demon", LOG_PID | LOG_CONS, LOG_DAEMON);
  syslog(LOG_INFO, "DEMON START!!!");
  closelog();
  // ...code...
  // /etc/syslog.conf
}
