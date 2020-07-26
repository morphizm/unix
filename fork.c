main() {
  int pid = fork();
  if (pid == -1) {
    perror("fork");
    exit(1);
  }
  if (pid == 0) {
    printf("CHILD\n");
  } else {
    printf("Parent\n");
  }
}
