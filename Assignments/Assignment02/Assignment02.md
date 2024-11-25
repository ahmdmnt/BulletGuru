# Assignment 02: 
## **Title:** Assignment two for kernel module:

1. Check how many cores do you have using top command.
```
$ top
    top - 12:23:36 up  2:26,  0 users,  load average: 0.08, 0.03, 0.01
    Tasks:  10 total,   1 running,   7 sleeping,   2 stopped,   0 zombie
    %Cpu0  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu1  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu2  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu3  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu4  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu5  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu6  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu7  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu8  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu9  :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu10 :  0.0 us,  0.3 sy,  0.0 ni, 99.7 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    %Cpu11 :  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    MiB Mem :  12524.2 total,  12310.8 free,    120.1 used,     93.2 buff/cache
    MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.  12210.2 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
        1 root      20   0     908    536    472 S   0.0   0.0   0:00.05 init
    54 root      20   0     908     84     20 S   0.0   0.0   0:01.13 init
    291 root      20   0    8912   5600   4728 S   0.0   0.0   0:00.02 sudo
    292 root      20   0    8912    880      0 S   0.0   0.0   0:00.00 sudo
    293 root      20   0   24740  19464  14808 T   0.0   0.2   0:00.13 apt
    325 _apt      20   0   19004   9168   8200 T   0.0   0.1   0:00.01 http
    576 root      20   0     908     84     20 S   0.0   0.0   0:00.00 init
    577 root      20   0     908     84     20 S   0.0   0.0   0:00.03 init
    578 ahmedmo+  20   0    6824   5976   3584 S   0.0   0.0   0:00.18 bash
    610 ahmedmo+  20   0    7788   3716   3120 R   0.0   0.0   0:00.00 top
```


2. Create number of cores + 2 processes dd if=/dev/zero of=/dev/null run in background.
```
$ dd if=/dev/zero of=/dev/null &
    [1] 621
$ dd if=/dev/zero of=/dev/null &
    [2] 622

$top
    top - 12:28:23 up  2:31,  0 users,  load average: 0.14, 0.07, 0.01
    Tasks:  12 total,   3 running,   7 sleeping,   2 stopped,   0 zombie
    %Cpu(s):  5.5 us, 12.6 sy,  0.0 ni, 82.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    MiB Mem :  12524.2 total,  12310.5 free,    120.4 used,     93.2 buff/cache
    MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.  12209.9 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
    621 ahmedmo+  20   0    3240   1044    952 R 100.0   0.0   0:01.66 dd
    622 ahmedmo+  20   0    3240   1012    924 R 100.0   0.0   0:01.20 dd
```


3. Change priority for them:
    -20, -10, 0, .. , 19
```
```


4. Monitor them using top command, did you notice any change ?
```
$top
    top - 12:28:23 up  2:31,  0 users,  load average: 0.14, 0.07, 0.01
    Tasks:  12 total,   3 running,   7 sleeping,   2 stopped,   0 zombie
    %Cpu(s):  5.5 us, 12.6 sy,  0.0 ni, 82.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
    MiB Mem :  12524.2 total,  12310.5 free,    120.4 used,     93.2 buff/cache
    MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.  12209.9 avail Mem

    PID USER      PR  NI    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
    621 ahmedmo+  20   0    3240   1044    952 R 100.0   0.0   0:01.66 dd
    622 ahmedmo+  20   0    3240   1012    924 R 100.0   0.0   0:01.20 dd
```


5. Kill them all using killall command.
```
```