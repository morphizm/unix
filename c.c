#include <string.h>
#include <errno.h>
#include <stdio.h>

// char *strerror(int errnum);
// void perror(const char *s);

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int create(const char *path, mode_t mode);

#include <assert.h> // assert
#include <cpio.h> // cpio
#include <ctype.h> // definitions symbol types; isascii; isprint; isdigit;
#include <dirent.h> // opendir; readdir;
#include <errno.h> // CODE ERRORS
#include <fcntl.h> // fcntl; open; creat;
#include <features.h> // def of CONSTANTS
#include <ftw.h> // scan tree ftw; nftw;
#include <grp.h> // getgrnam; getgrent; getgrgrid;
#include <langinfo.h> // langinfo
#include <limits.h> //
#include <locale.h> // setlocale
#include <math.h>
#include <nl_types.h> // catopen; catclose;
#include <pwd.h> // structure of /etc/passwd; getpwnam; getpwent; getpwuid
#include <regex.h> // regcomp; regexec;
#include <search.h> // hsearch; hcreate; hdestroy;
#include <setjmp.h> // setjmp; sigsetjmp; longjmp; siglongjmp;
#include <signal.h> // sigsetops; sigemptyset; sigaddset;
#include <stddef.h> // size_t
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // string; strcasecmp; strcat; strcpy;
#include <tar.h> // tar
#include <termios.h>
#include <time.h> // time; ctime; localtime; tzset; getitimer; setitimer;
#include <ulimit.h> // ulimit
#include <unistd.h>
#include <utime.h> // utime
#include <sys/ipc.h> // IPC - межпроцессорное взаимодействие
#include <sys/msg.h>
#include <sys/resource.h> // getrlimit; setrlimit
#include <sys/sem.h> // semaphors...
#include <sys/shm.h> // разделяемая память
#include <sys/stat.h> // stat; lstat; fstat; meta data of files
#include <sys/times.h> // times
#include <sys/types.h>
#include <sys/utsname.h> // uname
#include <sys/wait.h> // wait; waitpid;


int main() {
  printf("!!!!");
  // printf(strerror(1));
  return 0; // returning code
}

#include <unistd.h>
void exit(int status);

#include <stdlib.h>
int atexit(void (*func)(void)); // exit controllers registed with atexit; max 32 controllers


#include <fcntl.h>
int open(const char *path, int oflag, mode_t mode);

/*
oflag:
O_RDONLY
O_WRONLY
O_RDWR
O_APPEND
O_CREAT
O_EXCL
O_NOCTTY
O_SYNC
O_TRUNC
O_NONBLOCK
O_NOFOLLOW
O_DIRECTORY
O_LARGEFILE - let open a file bigger than 31 byte

*/

#include <fcntl.h>
int creat(const char *path, mode_t mode);
// IS EQUAL == open(path, O_WRONLY | O_CREAT | O_TRUNC, mode);

#include <unistd.h>
int close(int fildes);

int dup(int fildes);
int dup2(int fildes, int fildes2);


#include <unistd.h>
off_t lseek(int fildes, off_t offset, int whence);
/*
whence:
SEEK_CUR - from current location
SEEK_END - from end of file
SEEK_SET - equal offset
*/

#include <unistd.h>
ssize_t read(int fildes, void *buf, size_t nbyte);
#include <sys/types.h>
#include <sys/uio.h>
ssize_t readv(int fildes, struct iovec *iov, int iovcnt);

struct {
  void *iov_base; // pointer on start buffer
  size_t iov_len; // buffer size
} iovec;


// WHAT BUFFER MEAN?
// scatter-gather

#include <unistd.h>
ssize_t write(int fildes, void *buf, size_t nbyte);
#include <sys/types.h>
#include <sys/uio.h>
ssize_t writev(int fildes, struct iovec *iov, int iovcnt);

#include <unistd.h>
int pipe(int fildes[2]);
// fildes[0] - read data from channel
// fildes[1] - write to channel
// ONLY CHILD AND PARENT CAN ACCESS TO CHANNEL

#include <fcntl.h>
int fcntl(int fildes, int cmd); // Possible have 3 args
/*
2 and 3 arg can be:
F_DUPFD
F_GETFD - close on exec
F_SETFD - set close on exec
F_GETFL
oflags = fcntl(fd, F_GETFL, 0);
accbits = oflags & O_ACCMODE;
if (accbits == O_RDONLY)
  printf("FIle open only for read")
else if (acccbits == O_WRONLY)
  printf("FIle open only for write")
else if (acccbits == O_RDWR)
  printf("FIle open only for read and write")
----------
F_SETFL
F_GETLK
F_SETLK
F_SETLKW
F_GETOWN
F_SETOWN
F_GETSIG
F_SETSIG
*/

#include <stdio.h>
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;
/*
fopen - open a file and return file_pointer(descriptor?)
fclose - close a thread
fflush - clean buf thread, opened on record
getc - read a symbol from thread
putc - write symbol to thread
puts - write string to thread
fread - read bytes
fwrite - write bytes
fseek - positioning a pointer in thread
printf - out
scanf - in
fileno - return a file_descriptor current thread
*/

main() {
  write(1, "Hello\n", 6);
  printf("Hello\n");
}

#include <stdio.h>
void setbuf(FILE *stream, char *buf);
int setvbuf(FILE *stream, char *buf, int type, size_t size);
// type - _IOFBF; _IOLBF; _IONBF;

#include <unistd.h>
int link(const char *existing, const char *new);
// ln; existing - index_descriptor
#include <unistd.h>
int unlink(const char *path);
// rm
#include <unistd.h>
int symlink(const char *name, const char *symname);
// ln -s
#include <unistd.h>
int readlink(const char *path, void *buf, size_t bufsiz);


#include <sys/types.h>
#include <sys/mman.h>
// caddr_t nmap(caddr_t addr, size_t len, int prot, int flags, int fildes, off_t off);
// munmap; msync
/*
prot
PROT_READ
PROT_WRITE
PROT_EXEC
PROT_NONE

flags:
MAP_SHARED
MAP_PRIVATE
MAP_FIXED
MAP_NORESERVE
*/


#include <unistd.h>
#include <sys/types.h>
int chown(const char *path, uid_t owner, gid_t group);
int fchown(int fildes, uid_t owner, gid_t group);
int lchown(const char *path, uid_t owner, gid_t group);


#include <sys/types.h>
#include <sys/stat.h>
int chmod(const char *path, mode_t mode);
int fchmod(int fildes, mode_t mode);

/*
mode:
Flag      Bytes   Means
S_ISUID   0400  - set SUID
S_ISGID   020#0 - set SGID if # = 7, 5, 3, 1; set block file if # = 6,4,2,0;
S_ISVTX   01000 - set sticky bit
S_IRWXU   00700   set rwx for owner
S_IRUSR   00400   set r for owner
S_IWUSR   00200   set w for owner
S_IXUSR   00100   set x for owner
S_IRWXG   00070   ---- group
S_IRGRP   00040
S_IWGRP   00020
S_IXGRP   00010
S_IRWXO   00007   ---- other
S_IROTH   00004
S_IWOTH   00002
S_IXOTH   00001
*/

#include <unistd.h>
int chroot(const char *path);
int fchroot(int fildes);
int chdir(const char *path);
int fchdir(int fildes);

#include <sys/types.h>
#include <sys/stat.h>
int stat(const char *path, struct stat *buf);
int lstat(const char *path, struct stat *buf);
int fstat(int fildes, struct stat *buf);

#include <sys/types.h>
#include <unistd.h>
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);
int setuid(uid_t uid);
int setegid(gid_t egid);
int seteuid(uid_t euid);
int setgid(gid_t gid);

// For work with /etc/passwd - struct passwd, <pwd.h>
// struct passwd:
// char *pw_name - name user
// char *pw_passwd - passsword encrypted
// uid_t pw_uid - uid user
// gid_t pw_gid - gid
// char *pw_gecos - comment
// char *pw_dir - home directory user
// char *pw_shell - cmd

// change break-address
#include <unistd.h>
int brk(void *endds);
void *sbrk(int incr);

#include <stdlib.h>
void *malloc(size_t size); // выделяет указанное количество байт памяти
void *calloc(size_t nelem, size_t elsize); // выделяет память для nelem числа объетов, размер которых = elsize. Выделянная память инициализируется нулями
void *realloc(void *ptr, size_t size); // изменяет размер предварительно выделенной области памяти
void free(void *ptr); // освобождает память, указатель на которую передается черех аргумент ptr
// Возвращаемый указатель этих функций выровнен

#include <sys/types.h>
#include <unistd.h>
pid_t fork(void);

#include <unistd.h>
int execve(const char *path, char *const argv[], char *const envp[]);
extern char **environ;
// int execl(const char *path, const char *arg, ...);
// int execv(const char *path, char *const argv[]);
// int execke(const char *path, char const *arg, ..., char *const envp[]);
// int execlp(const char *file, const char *arg, ...);
// int execvp(const char *file, char *const argv[]);

#include <sys/types.h>
#include <sys/wait.h>
pid_t wait(int *stat_loc);
pid_t waitpid(pid_t pid, int *stat_loc, int options);

// analyze stat_loc:
// WIFEXITED(status) - true if process completed normally
// WEXITSTATUS(status) - if WIFEXITED != 0 then determine returning code from process (arg func - exit)
// WIFSIGNALED(status) - true if process completed at signal
// WTERMSIG(status) - if WIFSIGNALED(status) != 0 then determine signal num executed process
// WIFSTOPPED(status) - true if child process stoped ; only signal WUNTRACED

// waitpid:
// < -1 -- any those gid == abs pid
// -1 - any child process
// 0 - any child those gid == current process
// > 1 - child those id == pid

// options:
// WNOHANG - immediatily return
// WUNTRACED

#include <sys/time.h>
#include <sys/resource.h>
pid_t wait3(int *status, int options, struct rusage *rusage);
pid_t wait4(pid_t wpid, int *status, int options, struct rusage *rusage);
// rusage contain info about system resources


#include <sys/types.h>
#include <signal.h>
int kill(pid_t pid, int sig);

#include <signal.h>
void (*signal (int sig, void (*disp)(int)))(int);
// SIG_DFL, SIG_IGN

#include <signal.h>
int sigemptyset(sigset_t *set);
int sigfillset(sigset_t *set);
int sigaddset(sigset_t *set, int signo);
int sigdelset(sigset_t *set, int signo);
int sigismember(sigset_t *set, int signo);
int sigaction(int sig, const struct sigaction *act, struct sigaction *cact);
// Структура sigaction
void (*sa_handler)(int);
void (*sa_sigaction)(int, siginfo_t *, void *);
sigset_t sa_mask;
int sa_flags;
// sa_flags:
// SA_ONSTACK - change stack
// SA_RESETHAND - if func-interupteded define then disp will change on SGI_DFL and signal will not block
// SA_NODEFER
// SA_RESTART
// SIG_SIGINFO
// SA_NOCLDWAIT*
// SA_NOCLDSTOP

// struct siginfo_t - <siginfo.h>
// int si_signo - sig num
// int si_errno - err num;
// int si_code - reason send sig
// if si_code <=0 => sig sends by applied +:
// pid_t si_pid
// uid_t si_uid
void handler(int, siginfo_t *info, void *context);

#include <signal.h>
int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);
// SIG_BLOCK
// SIG_UNBLOCK
// SIG_SETMASK
int sigpending(sigset_t *set);
int sigsuspend(const sigset_t *mask);

#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
int getrusage(int who, struct rusage *usage);
// who == RUSAGE_SELF or RUSAGE_CHILDREN
struct rusage (
  struct timeval ru_utime;
  struct timeval ru_stime;
  long ru_maxrss;
  long ru_ixrss;
  long ru_idrss;
  long ru_isrss;
  long ru_minflt;
  long ru_majflt;
  long ru_nswap;
  long ru_inblock;
  long ru_oublock;
  long ru_msgsnd;
  long ru_msgrcv;
  long ru_nsignals;
  long ru_nvcsw;
  long ru_nivcsw;
);

#include <syslog.h>
void syslog(int priority, char *logstring, int *params);
/*
priority:
LOG_EMERG - panic
LOG_ALERT - unnormal state
LOG_CRIT - critical event
LOG_ERR - some errors
LOG_WARNING - ..
LOG_NOTICE
LOG_INFO
LOG_DEBUG
*/
void openlog(char *ident, int logopt, int facility);
// logopt: LOG_PID, LOG_CONS,
// facility LOG_KERN, LOG_USER, LOG_MAIL, LOG_DAEMON, LOG_NEWS, LOG_CRON
void closelog(void);


#include <sched.h>
int clone (*fn) (void *), void *child_stack, int flags, void *arg);
/*
CLONE_PARENT
CLONE_FS
CLONE_FILES
CLONE_SIGHAND
CLONE_VM
CLONE_PID
*/

#include <unistd.h>
int pipe(int *fildes);

int mknod(char *pathname, int mode, int dev);

#include <sys/types.h>
#include <sys/ipc.h>
key_t ftok(const char *pathnam, int id);


// msget(3/2); Messages
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
int msgget(key_t key, int msgflg);
int msgsnd(int msqid, void *msgp, size_t msgsz, int msgflg);
int msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
// msgid - descriptor of object
// long msgtype - type of message
// char msgtext[] - message data

// Semaphors
#include <sys/sem.h>
int semget(key_t key, int nsems, int flag);
// IPC_CREAT, IPC_EXCL
int semop(int semid, struct sembuf array[], unsigned nops);
struct sembuf {
  u_short sem_num; // number of semaphir in group
  shor sem_op; // operation
  short sem_flg; // operation flags
}

#include <machine/param.h>
#include <sys/types.h>
#include <sys/ipc.h>
#inlcude <sys/shm.h>
int shmget(key_y key, int size, int flag);
void *shmat(int shmid, void *addr, int flag);
int shmdt(void *addr);


// Socket
#include <sys/types.h>
#include <sys/socket.h>
int socket(int domain, int type, int protocol);
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

