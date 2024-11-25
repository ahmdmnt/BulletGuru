# Assignment 01: 
## **Title:** Linux Processes Commands Exercises

**Beginner Level**
1. List all running processes
Use the `ps` command to list all processes running on your system.
```bash
$ ps -ef
    UID        PID  PPID  C STIME TTY          TIME CMD
    root         1     0  0 09:57 ?        00:00:00 /init
    root        53     1  0 09:59 ?        00:00:00 /init
    root        54    53  0 09:59 ?        00:00:00 /init
    ahmedmo+    55    54  0 09:59 pts/1    00:00:00 -bash
    ahmedmo+    73    55  0 10:08 pts/1    00:00:00 ps -ef
```


2. Monitor system processes in real-time
Run the `top` or `htop` command and identify the most CPU-intensive process.
```bash
$ top
    top - 10:08:56 up 11 min,  0 users,  load average: 0.00, 0.04, 0.05
    Tasks:   5 total,   1 running,   4 sleeping,   0 stopped,   0 zombie
    %Cpu(s):  0.5 us,  0.0 sy,  0.0 ni, 99.5 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    MiB Mem :  12524.2 total,  12391.8 free,     99.9 used,     32.5 buff/cache
    MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.  12260.6 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
        1 root      20   0     908    536    472 S   0.0   0.0   0:00.05 init
    53 root      20   0     908     84     20 S   0.0   0.0   0:00.00 init
    54 root      20   0     908     84     20 S   0.0   0.0   0:00.09 init
    55 ahmedmo+  20   0    6204   5088   3368 S   0.0   0.0   0:00.13 bash
    74 ahmedmo+  20   0    7788   3504   2896 R   0.0   0.0   0:00.00 top
```


3. Start a background process
Launch a command like `sleep 30` in the background using `&`.
    - Verify it is running using `jobs` or `ps`.
```bash
$ sleep 30 &
    [1] 80

$ ps -ef
    UID        PID  PPID  C STIME TTY          TIME CMD
    root         1     0  0 09:57 ?        00:00:00 /init
    root        53     1  0 09:59 ?        00:00:00 /init
    root        54    53  0 09:59 ?        00:00:00 /init
    ahmedmo+    55    54  0 09:59 pts/1    00:00:00 -bash
    ahmedmo+    80    55  0 10:10 pts/1    00:00:00 sleep 30
    ahmedmo+    81    55  0 10:10 pts/1    00:00:00 ps -ef

$ jobs
    [1]+  Running                 sleep 30 &
```


4. Bring a background process to the foreground
Use `fg` to bring the background process back to the foreground.
```bash
$ fg %1
    sleep 30
```


5. Suspend and resume a process
    - Start a long-running process (e.g., `ping google.com`).
    - Suspend it using `Ctrl+Z` and resume it with `fg` or `bg`.
```bash
$ ping localhost
    PING localhost (127.0.0.1) 56(84) bytes of data.
    64 bytes from localhost (127.0.0.1): icmp_seq=1 ttl=64 time=0.078 ms
    64 bytes from localhost (127.0.0.1): icmp_seq=2 ttl=64 time=0.029 ms
^Z
[1]+  Stopped                 ping localhost

$ fg %1
    ping localhost
    64 bytes from localhost (127.0.0.1): icmp_seq=5 ttl=64 time=0.118 ms
    64 bytes from localhost (127.0.0.1): icmp_seq=6 ttl=64 time=0.102 ms
    64 bytes from localhost (127.0.0.1): icmp_seq=7 ttl=64 time=0.101 ms
^Z
[1]+  Stopped                 ping localhost

$ bg %1
    [1]+ ping localhost &
    64 bytes from localhost (127.0.0.1): icmp_seq=12 ttl=64 time=0.047 ms
    64 bytes from localhost (127.0.0.1): icmp_seq=13 ttl=64 time=0.076 ms
```


**Intermediate Level**
6. Kill a process by PID
    - Start a process (e.g., `sleep 300`).
    - Find its Process ID (PID) using `ps` or `pgrep`.
    - Kill it using the `kill` command.
```bash
$ sleep 300 &
    [1] 165

$ ps -ef | grep sleep
    ahmedmo+   165    55  0 11:11 pts/1    00:00:00 sleep 300
    ahmedmo+   167    55  0 11:11 pts/1    00:00:00 grep --color=auto sleep

$ kill -9 165

$ ps -ef | grep sleep
    ahmedmo+   169    55  0 11:12 pts/1    00:00:00 grep --color=auto sleep
    [1]+  Killed                  sleep 300
```

7. Terminate multiple processes
    - Start multiple processes (e.g., `sleep 100`, `sleep 200`).
    - Use `pkill` to terminate all processes with a specific name.
```bash
$ sleep 300 &
    [1] 196

$ sleep 200 &
    [2] 197

$ pkill sleep
    [1]-  Terminated              sleep 300
    [2]+  Terminated              sleep 200

$ ps -ef | grep sleep
    ahmedmo+   200    55  0 11:14 pts/1    00:00:00 grep --color=auto sleep
```


8. Niceness levels
    - Start a command with a low priority using `nice` (e.g., `nice -n 10 sleep 100`).
    - Check its priority using `ps -o pid,ni,comm`.
    - Change its niceness using `renice`.
```bash
$ nice -n 10 sleep 100 &
    [1] 204

$ ps -o pid,ni,comm
  PID  NI COMMAND
   55   0 bash
  204  10 sleep
  205   0 ps

$ sudo renice -n 0 204
    204 (process ID) old priority 10, new priority 0

$ ps -o pid,ni,comm
  PID  NI COMMAND
   55   0 bash
  204   0 sleep
  210   0 ps
```

9. View process hierarchy
Use the `pstree` command to view the parent-child relationships of processes.
```bash
$ pstree
init─┬─init───init───bash───pstree
     ├─init───init───bash
     └─{init}
```

10. Redirect process output
Run `ping google.com` and redirect its output to a file using `>` or `>>`.
```bash
$ touch logOutput.txt

$ cat logOutput.txt

$ ping localhost > logOutput.txt
^C

$ cat logOutput.txt
    PING localhost (127.0.0.1) 56(84) bytes of data.
    64 bytes from localhost (127.0.0.1): icmp_seq=1 ttl=64 time=0.031 ms
    64 bytes from localhost (127.0.0.1): icmp_seq=2 ttl=64 time=0.047 ms

    --- localhost ping statistics ---
    4 packets transmitted, 4 received, 0% packet loss, time 3120ms
    rtt min/avg/max/mdev = 0.031/0.065/0.137/0.041 ms

$ ping localhost >> logOutput.txt
^C

$ cat logOutput.txt
    PING localhost (127.0.0.1) 56(84) bytes of data.
    64 bytes from localhost (127.0.0.1): icmp_seq=1 ttl=64 time=0.031 ms
    64 bytes from localhost (127.0.0.1): icmp_seq=2 ttl=64 time=0.047 ms

    --- localhost ping statistics ---
    4 packets transmitted, 4 received, 0% packet loss, time 3120ms
    rtt min/avg/max/mdev = 0.031/0.065/0.137/0.041 ms
    PING localhost (127.0.0.1) 56(84) bytes of data.
    64 bytes from localhost (127.0.0.1): icmp_seq=1 ttl=64 time=0.040 ms
    64 bytes from localhost (127.0.0.1): icmp_seq=2 ttl=64 time=0.071 ms
    64 bytes from localhost (127.0.0.1): icmp_seq=3 ttl=64 time=0.084 ms

    --- localhost ping statistics ---
    3 packets transmitted, 3 received, 0% packet loss, time 2057ms
    rtt min/avg/max/mdev = 0.040/0.065/0.084/0.018 ms
```


**Advanced Level**
11. Track system calls of a process
Use `strace` to trace system calls of a command like `ls`.
    Example: `strace ls`.
```bash
$ strace ls
    execve("/usr/bin/ls", ["ls"], 0x7ffc1d10ec80 /* 20 vars */) = 0
    brk(NULL)                               = 0x558e92e7f000
    arch_prctl(0x3001 /* ARCH_??? */, 0x7ffc4bc78800) = -1 EINVAL (Invalid argument)
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f0727d09000
    access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
    openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
    newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=14311, ...}, AT_EMPTY_PATH) = 0
    mmap(NULL, 14311, PROT_READ, MAP_PRIVATE, 3, 0) = 0x7f0727d05000
    close(3)                                = 0
    openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libselinux.so.1", O_RDONLY|O_CLOEXEC) = 3
    read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
    newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=166280, ...}, AT_EMPTY_PATH) = 0
    mmap(NULL, 177672, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x7f0727cd9000
    mprotect(0x7f0727cdf000, 139264, PROT_NONE) = 0
    mmap(0x7f0727cdf000, 106496, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x6000) = 0x7f0727cdf000
    mmap(0x7f0727cf9000, 28672, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x20000) = 0x7f0727cf9000
    mmap(0x7f0727d01000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x27000) = 0x7f0727d01000
    mmap(0x7f0727d03000, 5640, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x7f0727d03000
    close(3)                                = 0
    openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
    ... <CROPPED> 
```

12. Monitor file descriptors
    - Start a process like `cat`.
    - Use `lsof -p <PID>` to check the file descriptors in use by the process.
```bash
$ sleep 300 &
    [1] 244

$ lsof -p 244
    COMMAND PID      USER   FD   TYPE DEVICE SIZE/OFF NODE NAME
    sleep   244 ahmedmont  cwd    DIR   8,16     4096  473 /home/ahmedmont
    sleep   244 ahmedmont  rtd    DIR   8,16     4096    2 /
    sleep   244 ahmedmont  txt    REG   8,16    35328 1786 /usr/bin/sleep
    .... <CROPPED>
    sleep   244 ahmedmont    0u   CHR  136,1      0t0    4 /dev/pts/1
    sleep   244 ahmedmont    1u   CHR  136,1      0t0    4 /dev/pts/1
    sleep   244 ahmedmont    2u   CHR  136,1      0t0    4 /dev/pts/1
```

13. Process scheduling policies
    - Start a process with `chrt` to set a real-time scheduling policy.
        Example: `chrt -f 10 sleep 100`.
    - Check its policy using `ps`.
```bash
$ sudo chrt -f 10 sleep 100 &
    [1] 256

$ ps -ef
    UID        PID  PPID  C STIME TTY          TIME CMD
    root         1     0  0 09:57 ?        00:00:00 /init
    root       256    55  0 11:27 pts/1    00:00:00 sudo chrt -f 10 sleep 100
    root       257   256  0 11:27 pts/2    00:00:00 sudo chrt -f 10 sleep 100
    root       258   257  0 11:27 pts/2    00:00:00 sleep 100
```

14. Create and terminate a zombie process
    - Write a simple C program that forks but doesn't call `wait`.
    - Observe the zombie process using `ps` and terminate its parent.
**C Code Example to create Zombie Process**
```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if(pid < 0) {
        perror("Fork Failed!");
        exit(1);
    }
    else if(pid == 0) {
        printf("Child Process Created. PID %d\n\n", getppid(), getpid());
        exit(0);
    }
    else {
        printf("Parent Process Created. PPID:%d - PID:%d", getppid(), getpid());
        sleep(100);
    }

    return 0;
}
```

```bash
$ gcc -o zombie zombie.c

$ ./zombie

$ ps -ef | grep zombie

$ kill <PID>

```

15. Limit resource usage
    - Use `ulimit` to limit the CPU time or memory for a process.
    Example: `ulimit -t 5` followed by a CPU-intensive command like `dd if=/dev/zero of=/dev/null`.
```bash
$ ulimit -t 5

$ dd if=/dev/zero of=/dev/null
    Killed
```
