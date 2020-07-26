
main() {
  write(1, "$- ", 3);
  char inputbuf;
  get_input(inputbuf);
  parse_input(inputbuf, cmd, arg);
  
  int pid = fork();
  if (pid == 0) {
    execvp(cmd, arg);
    pexit(cmd);
  } else {
    wait(&status);
  }
}
