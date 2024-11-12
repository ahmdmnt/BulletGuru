# Assignment 01


## Performance Analysis

## 1. `ls vs. find`
### 1.1. `ls`
#### Time Measurement:
Total Execution Time = 0m0.002s

#### System Interaction Identification &  syscall Time Breakdown:
```
$ strace -c ls 
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    56.06    0.000037          18         2           getdents64
    21.21    0.000014           1         9           close
    15.15    0.000010          10         1           write
    7.58    0.000005           0         8           newfstatat
    0.00    0.000000           0         5           read
    0.00    0.000000           0        18           mmap
    0.00    0.000000           0         7           mprotect
    0.00    0.000000           0         1           munmap
    0.00    0.000000           0         3           brk
    0.00    0.000000           0         2           ioctl
    0.00    0.000000           0         4           pread64
    0.00    0.000000           0         2         2 access
    0.00    0.000000           0         1           execve
    0.00    0.000000           0         2         2 statfs
    0.00    0.000000           0         2         1 arch_prctl
    0.00    0.000000           0         1           set_tid_address
    0.00    0.000000           0         7           openat
    0.00    0.000000           0         1           set_robust_list
    0.00    0.000000           0         1           prlimit64
    0.00    0.000000           0         1           getrandom
    0.00    0.000000           0         1           rseq
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000066           0        79         5 total
```

### 1.2. `find`
#### Time Measurement:
Total Execution Time = 0m0.003s

#### System Interaction Identification & syscall Time Breakdown:
```
$ strace -c find . -name "Buggy*"
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    25.57    0.000223          11        19           mmap
    18.81    0.000164           7        22        12 openat
    9.98    0.000087          12         7           mprotect
    7.00    0.000061           4        14           close
    6.88    0.000060           8         7           read
    6.65    0.000058           4        12           newfstatat
    4.13    0.000036          12         3           write
    2.98    0.000026          13         2           getdents64
    2.41    0.000021          21         1           munmap
    2.41    0.000021           5         4           pread64
    2.41    0.000021          10         2         2 statfs
    1.72    0.000015           3         4           fcntl
    1.49    0.000013           4         3           brk
    1.03    0.000009           4         2           ioctl
    0.80    0.000007           7         1           fstatfs
    0.69    0.000006           3         2         2 access
    0.69    0.000006           6         1           gettimeofday
    0.57    0.000005           5         1           uname
    0.57    0.000005           5         1           fchdir
    0.46    0.000004           2         2         1 arch_prctl
    0.46    0.000004           4         1           futex
    0.46    0.000004           4         1           set_tid_address
    0.46    0.000004           4         1           set_robust_list
    0.46    0.000004           4         1           prlimit64
    0.46    0.000004           4         1           getrandom
    0.46    0.000004           4         1           rseq
    0.00    0.000000           0         1           execve
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000872           7       117        17 total
```

### Performance Evaluation:
From the above data it is shown that `ls` command has better performance than `find`
- Better execution time and less syscalls

---

## 2. `cp vs. rsync`
### 2.1. `cp`
#### Time Measurement:
```
$ time cp BuggyApp.cpp BuggyApp1.cpp
    real    0m0.003s
    user    0m0.001s
    sys     0m0.002s
```

#### System Interaction Identification &  syscall Time Breakdown:
```
$ strace -c cp BuggyApp.cpp BuggyApp1.cpp
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    77.46    0.000110           8        13           close
    18.31    0.000026          13         2           munmap
    4.23    0.000006           6         1         1 lseek
    0.00    0.000000           0         9           read
    0.00    0.000000           0         1           write
    0.00    0.000000           0        27           mmap
    0.00    0.000000           0        10           mprotect
    0.00    0.000000           0         3           brk
    0.00    0.000000           0         4           pread64
    0.00    0.000000           0         2         2 access
    0.00    0.000000           0         1           execve
    0.00    0.000000           0         1           geteuid
    0.00    0.000000           0         2         2 statfs
    0.00    0.000000           0         2         1 arch_prctl
    0.00    0.000000           0         1           set_tid_address
    0.00    0.000000           0         1           fadvise64
    0.00    0.000000           0        10           openat
    0.00    0.000000           0        13           newfstatat
    0.00    0.000000           0         1           set_robust_list
    0.00    0.000000           0         1           prlimit64
    0.00    0.000000           0         1           getrandom
    0.00    0.000000           0         1           rseq
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000142           1       107         6 total
```

### 2.2. `rsync`
#### Time Measurement:
```
$ time rsync BuggyApp.cpp BuggyApp1.cpp
    real    0m0.048s
    user    0m0.004s
    sys     0m0.007s
```
#### System Interaction Identification & syscall Time Breakdown:
```
$ strace -c rsync BuggyApp.cpp BuggyApp1.cpp
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    85.42    0.004512         752         6         3 wait4
    3.31    0.000175         175         1           clone
    1.53    0.000081           5        15         2 openat
    1.06    0.000056           5        11           rt_sigaction
    1.06    0.000056           3        17           futex
    0.93    0.000049          16         3         1 clock_nanosleep
    0.89    0.000047           2        23           read
    0.87    0.000046           3        13           pselect6
    0.70    0.000037          18         2           socketpair
    0.68    0.000036           3        11           fcntl
    0.61    0.000032           2        15           close
    0.40    0.000021           1        14           mprotect
    0.38    0.000020           0        42           mmap
    0.36    0.000019           1        16         1 newfstatat
    0.30    0.000016           2         6           brk
    0.28    0.000015           2         7           write
    0.28    0.000015          15         1           munmap
    0.21    0.000011          11         1           rt_sigprocmask
    0.21    0.000011          11         1           getcwd
    0.15    0.000008           8         1           getrandom
    0.13    0.000007           3         2           umask
    0.08    0.000004           4         1           prlimit64
    0.06    0.000003           3         1           geteuid
    0.06    0.000003           3         1           getegid
    0.04    0.000002           2         1         1 rt_sigreturn
    0.00    0.000000           0         4           pread64
    0.00    0.000000           0         1         1 access
    0.00    0.000000           0         1           execve
    0.00    0.000000           0         4           gettimeofday
    0.00    0.000000           0         2         1 arch_prctl
    0.00    0.000000           0         1           set_tid_address
    0.00    0.000000           0         1           set_robust_list
    0.00    0.000000           0         1           rseq
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.005282          23       227        10 total
```

### Performance Evaluation:
From the above data it is shown that `cp` command has better performance than `rsync`
- Better execution time and less syscalls

---

## 3. `diff vs. cmp`
### 3.1. `diff`
#### Time Measurement:
```
$ time diff BuggyApp.cpp BuggyApp1.cpp
    real    0m0.002s
    user    0m0.000s
    sys     0m0.003s
```

#### System Interaction Identification &  syscall Time Breakdown:
```
$ strace -c  diff BuggyApp.cpp BuggyApp1.cpp
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    26.80    0.000171           9        19        12 openat
    18.65    0.000119          11        10           mmap
    12.70    0.000081           9         9           read
    7.84    0.000050          12         4           mprotect
    6.74    0.000043           6         7           newfstatat
    5.80    0.000037          18         2           munmap
    4.39    0.000028           3         8           close
    3.29    0.000021           5         4           pread64
    2.98    0.000019           6         3           brk
    1.88    0.000012           4         3           fcntl
    1.57    0.000010           5         2         1 arch_prctl
    1.25    0.000008           4         2           rt_sigaction
    1.10    0.000007           7         1         1 access
    0.94    0.000006           6         1           lseek
    0.78    0.000005           5         1           set_tid_address
    0.78    0.000005           5         1           prlimit64
    0.63    0.000004           4         1           sigaltstack
    0.63    0.000004           4         1           set_robust_list
    0.63    0.000004           4         1           getrandom
    0.63    0.000004           4         1           rseq
    0.00    0.000000           0         6           write
    0.00    0.000000           0         1           execve
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000638           7        88        14 total
```

### 3.2. `cmp`
#### Time Measurement:
```
$ time cmp BuggyApp.cpp BuggyApp1.cpp
    real    0m0.002s
    user    0m0.000s
    sys	    0m0.002s
```
#### System Interaction Identification & syscall Time Breakdown:
```
$ strace -c cmp BuggyApp.cpp BuggyApp1.cpp 
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    28.01    0.000179           9        19        12 openat
    15.49    0.000099           9        10           mmap
    13.15    0.000084           9         9           read
    7.67    0.000049           5         9           newfstatat
    6.57    0.000042          10         4           mprotect
    6.10    0.000039           4         8           close
    5.63    0.000036          18         2           munmap
    2.66    0.000017           4         4           pread64
    2.35    0.000015           5         3           brk
    2.35    0.000015          15         1         1 access
    1.88    0.000012           4         3           fcntl
    1.56    0.000010          10         1           write
    1.25    0.000008           4         2           rt_sigaction
    0.78    0.000005           5         1           lseek
    0.78    0.000005           5         1           set_robust_list
    0.63    0.000004           4         1           sigaltstack
    0.63    0.000004           2         2         1 arch_prctl
    0.63    0.000004           4         1           set_tid_address
    0.63    0.000004           4         1           prlimit64
    0.63    0.000004           4         1           getrandom
    0.63    0.000004           4         1           rseq
    0.00    0.000000           0         1           execve
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000639           7        85        14 total
```

### Performance Evaluation:
From the above data, both commands are very similar in perfomance, but `cmp` can be slightly better.

---

## 4. `sort vs. uniq`
### 4.1. `sort`
#### Time Measurement:
```
$ time sort BuggyApp1.cpp 
    real    0m0.002s
    user    0m0.001s
    sys	    0m0.001s
```

#### System Interaction Identification &  syscall Time Breakdown:
```
$ strace -c sort BuggyApp1.cpp 
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ------------------
    31.99    0.000357         357         1           execve
    20.97    0.000234           6        39           write
    9.95    0.000111          12         9           mmap
    7.62    0.000085           3        23           rt_sigaction
    4.03    0.000045          11         4           mprotect
    3.58    0.000040          10         4           openat
    3.49    0.000039           5         7           newfstatat
    2.51    0.000028           4         6           close
    1.88    0.000021           5         4           pread64
    1.70    0.000019           9         2           sysinfo
    1.52    0.000017           5         3           read
    1.34    0.000015          15         1           munmap
    1.34    0.000015           5         3           brk
    1.34    0.000015           3         4           prlimit64
    1.16    0.000013           6         2         1 access
    0.90    0.000010           5         2         1 arch_prctl
    0.63    0.000007           7         1           sched_getaffinity
    0.45    0.000005           5         1           lseek
    0.45    0.000005           5         1           set_tid_address
    0.45    0.000005           5         1           fadvise64
    0.45    0.000005           5         1           getrandom
    0.36    0.000004           4         1           fcntl
    0.36    0.000004           4         1           getgid
    0.36    0.000004           4         1           getegid
    0.36    0.000004           4         1           set_robust_list
    0.27    0.000003           3         1           getuid
    0.27    0.000003           3         1           geteuid
    0.27    0.000003           3         1           rseq
    ------ ----------- ----------- --------- --------- ------------------
    100.00    0.001116           8       126         2 total
```

### 4.2. `uniq`
#### Time Measurement:
```
$ time uniq BuggyApp1.cpp 
    real    0m0.002s
    user    0m0.001s
    sys     0m0.001s
```
#### System Interaction Identification & syscall Time Breakdown:
```
$ strace -c uniq BuggyApp1.cpp 
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    77.92    0.000247           6        39           write
    5.36    0.000017           2         7           close
    4.10    0.000013          13         1           lseek
    3.47    0.000011           2         4           openat
    3.15    0.000010           3         3           read
    3.15    0.000010           2         5           newfstatat
    1.58    0.000005           5         1           fadvise64
    1.26    0.000004           4         1           dup3
    0.00    0.000000           0         9           mmap
    0.00    0.000000           0         4           mprotect
    0.00    0.000000           0         1           munmap
    0.00    0.000000           0         3           brk
    0.00    0.000000           0         4           pread64
    0.00    0.000000           0         1         1 access
    0.00    0.000000           0         1           execve
    0.00    0.000000           0         2         1 arch_prctl
    0.00    0.000000           0         1           set_tid_address
    0.00    0.000000           0         1           set_robust_list
    0.00    0.000000           0         1           prlimit64
    0.00    0.000000           0         1           getrandom
    0.00    0.000000           0         1           rseq
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000317           3        91         2 total
```

### Performance Evaluation:
From the above data it is shown that `uniq` command has better performance than `sort`
- Execution time are almost the same
- `uniq` has Better syscalls behavior.

---

## 5. `grep vs. sed`
### 5.1. `grep`
#### Time Measurement:
```
$ time grep "#include" BuggyApp.cpp 
    real    0m0.003s
    user    0m0.000s
    sys     0m0.003s
```

#### System Interaction Identification &  syscall Time Breakdown:
```
$ strace -c grep "#include" BuggyApp.cpp
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    23.26    0.000184           9        20        12 openat
    22.76    0.000180          12        15           mmap
    13.15    0.000104          13         8           read
    6.95    0.000055           5        10           newfstatat
    6.57    0.000052          10         5           mprotect
    6.07    0.000048           4        10           close
    4.30    0.000034          17         2           munmap
    2.78    0.000022           5         4           brk
    2.65    0.000021           7         3           write
    2.40    0.000019          19         1           execve
    2.28    0.000018           4         4           pread64
    1.14    0.000009           4         2         1 arch_prctl
    0.88    0.000007           3         2           rt_sigaction
    0.88    0.000007           7         1         1 access
    0.51    0.000004           4         1           lseek
    0.51    0.000004           4         1           sigaltstack
    0.51    0.000004           4         1           futex
    0.51    0.000004           4         1           set_tid_address
    0.51    0.000004           4         1           prlimit64
    0.51    0.000004           4         1           getrandom
    0.51    0.000004           4         1           rseq
    0.38    0.000003           3         1           set_robust_list
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000791           8        95        14 total
```

### 5.2. `sed`
#### Time Measurement:
```
$ time sed -n '/#include/p' BuggyApp.cpp 
    real    0m0.003s
    user    0m0.000s
    sys     0m0.003s
```
#### System Interaction Identification & syscall Time Breakdown:
```
$ strace -c sed -n '/#include/p' BuggyApp.cpp 
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    32.47    0.000375         375         1           execve
    23.29    0.000269          11        23           mmap
    9.78    0.000113          12         9           mprotect
    8.14    0.000094          10         9           openat
    5.63    0.000065           8         8           read
    4.42    0.000051           5        10           newfstatat
    4.07    0.000047           4        10           close
    1.90    0.000022           7         3           write
    1.82    0.000021          10         2         2 statfs
    1.56    0.000018           6         3           brk
    1.47    0.000017           4         4           pread64
    1.39    0.000016          16         1           munmap
    1.21    0.000014           7         2         2 access
    0.78    0.000009           4         2         1 arch_prctl
    0.43    0.000005           5         1           getrandom
    0.35    0.000004           4         1           futex
    0.35    0.000004           4         1           set_tid_address
    0.35    0.000004           4         1           prlimit64
    0.35    0.000004           4         1           rseq
    0.26    0.000003           3         1           set_robust_list
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.001155          12        93         5 total
```

### Performance Evaluation:
From the above data, both commands are very similar in perfomance.
