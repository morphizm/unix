#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

void (*mysignal (int signo, void (*hndlr)(int)))(int) {
  struct sigaction act, oact;
  // set signal mask
  act.sa_handler = hndlr;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  if (signo != SIGALRM) {
    act.sa_flags |= SA_RESTART;
  }
  // set disposition
  if (sigaction(signo, &act, &oact) < 0) {
    return(SIG_ERR);
  }
  return(oact.sa_handler);
}

static void sig_hndlr(int signo) {
  /* this is not needed
  mysignal(SIGINT, sig_hndlr);
  */
 printf("RECEVE SIGNAL __ SIGINT\n");
}

int main() {
  // set disposition
  mysignal(SIGINT, sig_hndlr);
  mysignal(SIGUSR1, SIG_DFL);
  mysignal(SIGUSR2, SIG_IGN);
  while(1) {
    pause();
  }
}


/*

a.out &
kill -SIGINT <id>
kill -SIGUSR2 <id>
kill -SIGUSR1 <id>

*/

#include <sys/types.h>
#include <unistd.h>
pid_t getpgrp(void);
pid_t getpgid(pid_t pid);
int setpgid(pid_t pid, pid_t pgid);
pid_t getsid(pid_t pid);
pid_t setsid(void);

#include <sys/time.h>
#include <sys/resource.h>
int getrlimit(int resource, struct rlimit *rlp);
int setrlimit(int resource, const struct rlimit *rlp);
// struct rlimit
// rlim_t rlim_cur;
// rlim_t rlim_max;
// resource:
/*
RLIMIT_CORE - create core file, set limit
RLIMIT_CPU - max time to use cpu, when increase sends SIGXCPU
RLIMIT_DATA - max offset break-address, after limit brk(2) calls completes with ENOMEM
RLIMIT_FSIZE - max file size to create; SIGXFSZ; EFBIG;
RLIMIT_NOFILE - max file descriptors count; EMFILE
RLIMIT_STACK - max process stack size; SIGSEGV
RLIMIT_VMEM - max memory in bytes; brk(2), nmap(2) - ENOMEM
RLIMIT_NPROC - max processes can be exec; fork(2) - EAGAIN
RLIMIT_RSS - max size in bytes for RSS - Resident Set Sizel
RLIMIT_MEMLOCK - max physis volume in bytes, that process can block with mlock(2); mlock(2) - EAGAIN
*/
