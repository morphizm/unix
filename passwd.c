#include <pwd.h>
struct passwd *getpwnam(const char *name);

struct passwd *pw;
char logname[MAXNAME];
char *arg[MAXARG];
char *envir[MAXENV];
pw = getpwnam(logname);
if (pw == 0) retry();
else {
  setuid(pw->pw_uid);
  setgid(pw->pw_gid);
  execve(pw->pw_shell, arg, envir);

}

