#include <signal.h>
#include <stdio.h>

static void sig_handler(int signo) {
  signal(SIGINT, sig_handler);
  printf("RECEVE SIGNAL -- SIGINT\n");
}

int main() {
  signal(SIGINT, sig_handler);
  signal(SIGUSR1, SIG_DFL);
  signal(SIGUSR2, SIG_IGN);
  while(1) {
    pause();
  }
}
