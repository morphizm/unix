Scripts .profile; .bash_profile; .login - when first login to system;
Scripts .bashrc - every launch

$? - returning code


standart input - 0
standart output - 1
standart error - 2
logger >> file.log; == logger 1>> file.log
run 2> /dev/null

. <file>
source <file>
alias a=b
exec <cmd>; in current interpretator
export <variables>
hash [-r] <cmds..>
jobs
times
trap cmd sig1 sig2 ...
type name
ulimit; umask [nnn]; unalias
unset var...
wait pid
mknod - create FIFO

%jobid
stop %jobid
bg %jobid
fg %jobid
jobs

diff; cmp - difference between 2 files
cp - copy
mv - move
rm - remove
ln source target - make hard link name source with target(-s - symbolic link)
grep "cent[er][er]" file
cat; pg; more; head; tail;
sort -d file > sorted_file
sort -M +1 file
cut -f5 -d - filter string of file
wc file - count strings, words, symbols;
find / -name sh -print 2> /dev/nullgrep "cent[er][er]" file
cat; pg; more; head; tail;
sort -d file > sorted_file
sort -M +1 file
cut -f5 -d - filter string of file
wc file - count strings, words, symbols;
find / -name sh -print 2> /dev/null
find / -name core -atime +30 -print
chown user file
chgrp group file
chmod mode file
file * - define type of file (/etc/magic)

nice -[[-]n] command - exec cmd with relative priority
nice -10 big_program - запуск с большим nice чем больше nice тем меньший проритет имеет процесc
nice - -10 job1
renice new_nice pid

ps
  F - process status
  S - state process(O - executing, S - sleep, R - ready, I - making, Z - zombie)
  UID
  PID
  PPID
  PRI - dynamic priority
  NI - nice number
  TTY - управляющий терминал процесса(? - отсутствие)
  TIME - sum of executing
  STIME - created at
  COMMAND - name of command

kill [signo] pids...
  send signal number to processes
  kill -l
  1) SIGHUP 2) SIGINT 3) SIGQUIT 4) SIGKILL 5) SIGTRAP 6) SIGIOT 7) SIGEMT
  8) SIGFPE 9) SIGKILL 10) SIGBUS 11) SIGSEGV 12) SIGSYS 13) SIGPIPE 14) SIGALRM
  15) SIGTERM 16) SIGUSR1

at - для выполнение чего-то в будущем





-----------
ERRORS
ENOENT; EACCESS;

Where show?
/usr/include/asm/errno.h

functions: strerror; perror;

header files -- /usr/include ; /usr/include/sys
<> - standart library
""- absolute or relative path
types: <sys/types.h>;

gcc; cc; ld;

$ cc -c file1.c file2.c
$ cc -o prog file1.o file2.o -lnsl

Executing format files: ELF - Executable and Linking Format
(page 127)
COFF

main(int argc, char *argv[], char *envp[]);
argc - count arguments
argv - arguments
envp - index on env variables

IOE - terminal server set this values with file_desctiptors;
terminal server - getty

#C _start() -> main()

WORK WITH FILES:
open - returned fd
creat
close - close fd
dup - returned dup of fd
dup2
lseek - set index(pointer) on specific place
read - read specific count of bytes
readv
write - write bytes
writev
pipe - create communication chanel and return 2 fd
fcntl - give interface to control open file

standart library - <stdio.h> (libc.so, libc.a)
We have a FILE(thread) not file_desctiptor
extern FILE *stdin;
extern FILE *stdout;
extern FILE *stderr;

fd  thread(pointer)
0   stdin
1   stdout
2   stderr

Bufferization:
_IOFBF - FULL Bufferization
_IOLBF - LINE Bufferization
_IONBF - NO Bufferization

PAGE 154!! ABOUT STRUCTURE DATA THREAD

metadata store a links about file, when = 0 - mean deleted file

What func follow and not symlinks:
access +
chdir +
chmod +
chown +
lchown -
creat +
exec +
link +
mkdir +
mknod -
open
readlink -
rename -
stat +
lstat -
unlink -

nmap - процесс имеет возможность отобразить участки файла в собственное адресное пространство

При обращении к участку памяти лежащему за пределами файла
  ядро отправит процессу сигнал SIGBUS

Metadata store in index descriptor
mode_t, st_mode - type and access rights
ino_t, st_ino - number index_descriptor
dev_t, st_dev - number device where file located
dev_t, st_rdev
Nlink_t, st_nlink - hard links count
uid_t, st_uid
gid_t, st_gid
off_t, st_size - size in bytes
time_t, st_atime - last time access
time_t, st_mtime - last time modification
time_t, st_ctime - last metadata modification
long, st_blksize - optimal size block for io
long, st_block - number of block stored

<sys/stat.h> include macrodefinition:
S_ISFIFO(mode) - FIFO
S_ISCHR(mode) - special file sym device
S_ISDIR(mode) - directory
S_ISBLK(mode) - special file block device
S_ISREG(mode) - simple file
S_ISLINK(mode) - symbolic link
S_ISSOCK(mode) - socket

4 способа выделения памяти
1) variable,
  char ptype = "Unknown file type";
  строка ptype - размещается в сегменте инициализированных данных исполняемого файла и для нее выделяется соответствующая память при создании процесса.
2) Значение известно на этапе компиляции
  char ptype[32];
  Место в исполняемом файле для ptype не резервируется, но при создании процесса для данной переменной выделяется необходимое количество памяти, заполненной нулями, в сегменте BSS.
3) Переменные автоматического класса хранения, используемые в функциях программы, используют стек. Память для них выделяется при вызове функции и освобождается при возврате.
4) Выделение памяти явно запрашивается некоторомы системными вызовами или библиотечными функциями.

Дополнительная память выделяется из кучи. Следующий за сегментом данных адрес называется разделительным или брейк-адресом.

brk(2) - set break-address value equall endds, depends on it memory single out or free out

Programm execute with system calls
1) create process -- fork
2) execute new programm
child process inherit all properties from parent: uid;
gid;
env_vars;
signal disposition and signals;
restriction, on process;
current and / dir;
mask creating files;
files descriptor and file pointers;

After returning from fork CHILD and PARENT processes will execute same instructions!

execve - запустить бинарный файл, но с заменой текущего процесса.

SIGNALS:
  ctrl+c = SIGINT
  ctrl+\ = SIGQUIT

process can choose 1 of 3 actions:
  1) ignore
  2) intercept and process
  3) let default

SIGKILL, SIGSTOP can't be intercepted

NAME------NUMBER----DEFAULT ACTION--------meaning
SIGHUP    1         complete              signal send the leader of seans binds with tty
SIGINT    2         complete              signal send all processes current group(ctrl+c, del)
SIGQUIT   3         complete+core         -//- (ctrl+\)
SIGILL    4         complete+core         -//- if process try exec unpermission operation
SIGABRT   6         complete+core         -//- if system call == abort(2)
SIGFPE    8         complete+core         divide by zero, overflow with float nums
SIGKILL   9         complete              process completes
SIGSEGV   11        complete+core         info about try to get access address or memory unpermission
SIGPIPE   13        complete              send when try write to socket/chanel, recever end execution(end fd)
SIGALRM   14        complete              when alarm(2)
SIGTERM   15        complete              warning about that your process will destroy, u must prepare(kill - default send this signal)
SIGUSR1   10        complete              need for applied programs, to IPC(INTER-process communication)
SIGUSR2   12        complete              ==10
SIGCHLD   17        ignore                send to parent when child is died
SIGCONT   18        rerun execution
SIGSTOP   19        stop                  -//- stopping(ctrl+z)
SIGTSTP   20        stop                  -//-(ctrl+Q)
SIGTTIN   21        stop                  when try read from tty
SIGTTOU   22        stop                  when try write to tty
SIGBUS    7         complete+core         when apply to virtual memory, but virtual has not physical page
SIGPOLL   22        complete
SIGPROF   27        complete
SIGSYS    12        complete+core         when unpermission call
SIGTRAP   5         complete+core         when process cross point of interrupt
SIGURG    23        ignore                when urgent event in socket arose
SIGVTALRM 26        complete              setitimer(2)
SIGXCPU   24        complete+core         limit procession time
SIGXFSZ   25        complete+core         limit on size file


signal(2) - установить диспозицию сигнала, таким образом можно повесить обработчик для сигнала
POSIX.1 - sigaction(2) - установить диспозицию сигнала, узнать ее текущее значение
Структура sigaction
void (*sa_handler)(int) - обработчик сигнала sig;
void (*sa_sigaction)(int, siginfo_t *, void *) - -//- when flag SA_SIGINFO is set
sigset_t sa_mask - signal mask
int sa_flags - flags


-----------
LIMITS
soft limit
hard limit
increase - only root;


-----
Demons - a some work process, no belongs to any user, group.
init, cron, inetd, sendmail
