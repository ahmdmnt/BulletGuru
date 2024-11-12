# Assignment 01


## BuggyApp

#### After checking output of 
```
    $ strace -c ./BuggyApp

    Error: File not found!
    % time     seconds  usecs/call     calls    errors syscall
    ------ ----------- ----------- --------- --------- ----------------
    0.00    0.000000           0         4           read
    0.00    0.000000           0         1           write
    0.00    0.000000           0         5           close
    0.00    0.000000           0        22           mmap
    0.00    0.000000           0         8           mprotect
    0.00    0.000000           0         1           munmap
    0.00    0.000000           0         3           brk
    0.00    0.000000           0         4           pread64
    0.00    0.000000           0         1         1 access
    0.00    0.000000           0         1           execve
    0.00    0.000000           0         2         1 arch_prctl
    0.00    0.000000           0         1           futex
    0.00    0.000000           0         1           set_tid_address
    0.00    0.000000           0         6         1 openat
    0.00    0.000000           0         5           newfstatat
    0.00    0.000000           0         1           set_robust_list
    0.00    0.000000           0         1           prlimit64
    0.00    0.000000           0         1           getrandom
    0.00    0.000000           0         1           rseq
    ------ ----------- ----------- --------- --------- ----------------
    100.00    0.000000           0        69         3 total

```
**Conclusion:**
it is obviuos that there is error in above syscalls.
- access()
- arch_prctl()
- openat()


#### by investegating more using:
```
    $ strace ./BuggyApp

    execve("./BuggyApp", ["./BuggyApp"], 0x7ffcff3983f0 /* 64 vars */) = 0
    brk(NULL)                               = 0x6085d0129000
--> arch_prctl(0x3001 /* ARCH_??? */, 0x7ffe87a727b0) = -1 EINVAL (Invalid argument)
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x79d310790000
--> access("/etc/ld.so.preload", R_OK)      = -1 ENOENT (No such file or directory)
    openat(AT_FDCWD, "/etc/ld.so.cache", O_RDONLY|O_CLOEXEC) = 3
    newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=65235, ...}, AT_EMPTY_PATH) = 0
    mmap(NULL, 65235, PROT_READ, MAP_PRIVATE, 3, 0) = 0x79d310780000
    close(3)                                = 0
    openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libstdc++.so.6", O_RDONLY|O_CLOEXEC) = 3
    read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
    newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=2260296, ...}, AT_EMPTY_PATH) = 0
    mmap(NULL, 2275520, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x79d310400000
    mprotect(0x79d31049a000, 1576960, PROT_NONE) = 0
    mmap(0x79d31049a000, 1118208, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x9a000) = 0x79d31049a000
    mmap(0x79d3105ab000, 454656, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1ab000) = 0x79d3105ab000
    mmap(0x79d31061b000, 57344, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x21a000) = 0x79d31061b000
    mmap(0x79d310629000, 10432, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x79d310629000
    close(3)                                = 0
    openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libgcc_s.so.1", O_RDONLY|O_CLOEXEC) = 3
    read(3, "\177ELF\2\1\1\0\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
    newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=125488, ...}, AT_EMPTY_PATH) = 0
    mmap(NULL, 127720, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x79d310760000
    mmap(0x79d310763000, 94208, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x3000) = 0x79d310763000
    mmap(0x79d31077a000, 16384, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1a000) = 0x79d31077a000
    mmap(0x79d31077e000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1d000) = 0x79d31077e000
    close(3)                                = 0
    openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libc.so.6", O_RDONLY|O_CLOEXEC) = 3
    read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0P\237\2\0\0\0\0\0"..., 832) = 832
    pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
    pread64(3, "\4\0\0\0 \0\0\0\5\0\0\0GNU\0\2\0\0\300\4\0\0\0\3\0\0\0\0\0\0\0"..., 48, 848) = 48
    pread64(3, "\4\0\0\0\24\0\0\0\3\0\0\0GNU\0I\17\357\204\3$\f\221\2039x\324\224\323\236S"..., 68, 896) = 68
    newfstatat(3, "", {st_mode=S_IFREG|0755, st_size=2220400, ...}, AT_EMPTY_PATH) = 0
    pread64(3, "\6\0\0\0\4\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0@\0\0\0\0\0\0\0"..., 784, 64) = 784
    mmap(NULL, 2264656, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x79d310000000
    mprotect(0x79d310028000, 2023424, PROT_NONE) = 0
    mmap(0x79d310028000, 1658880, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x28000) = 0x79d310028000
    mmap(0x79d3101bd000, 360448, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x1bd000) = 0x79d3101bd000
    mmap(0x79d310216000, 24576, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x215000) = 0x79d310216000
    mmap(0x79d31021c000, 52816, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_ANONYMOUS, -1, 0) = 0x79d31021c000
    close(3)                                = 0
    openat(AT_FDCWD, "/lib/x86_64-linux-gnu/libm.so.6", O_RDONLY|O_CLOEXEC) = 3
    read(3, "\177ELF\2\1\1\3\0\0\0\0\0\0\0\0\3\0>\0\1\0\0\0\0\0\0\0\0\0\0\0"..., 832) = 832
    newfstatat(3, "", {st_mode=S_IFREG|0644, st_size=940560, ...}, AT_EMPTY_PATH) = 0
    mmap(NULL, 942344, PROT_READ, MAP_PRIVATE|MAP_DENYWRITE, 3, 0) = 0x79d310679000
    mmap(0x79d310687000, 507904, PROT_READ|PROT_EXEC, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0xe000) = 0x79d310687000
    mmap(0x79d310703000, 372736, PROT_READ, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0x8a000) = 0x79d310703000
    mmap(0x79d31075e000, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_FIXED|MAP_DENYWRITE, 3, 0xe4000) = 0x79d31075e000
    close(3)                                = 0
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x79d310677000
    arch_prctl(ARCH_SET_FS, 0x79d3106783c0) = 0
    set_tid_address(0x79d310678690)         = 53630
    set_robust_list(0x79d3106786a0, 24)     = 0
    rseq(0x79d310678d60, 0x20, 0, 0x53053053) = 0
    mprotect(0x79d310216000, 16384, PROT_READ) = 0
    mprotect(0x79d31075e000, 4096, PROT_READ) = 0
    mprotect(0x79d31077e000, 4096, PROT_READ) = 0
    mmap(NULL, 8192, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x79d310675000
    mprotect(0x79d31061b000, 45056, PROT_READ) = 0
    mprotect(0x6085ce6a0000, 4096, PROT_READ) = 0
    mprotect(0x79d3107ca000, 8192, PROT_READ) = 0
    prlimit64(0, RLIMIT_STACK, NULL, {rlim_cur=8192*1024, rlim_max=RLIM64_INFINITY}) = 0
    munmap(0x79d310780000, 65235)           = 0
    getrandom("\xa2\x2e\xa8\x6f\x7e\x69\xd5\x95", 8, GRND_NONBLOCK) = 8
    brk(NULL)                               = 0x6085d0129000
    brk(0x6085d014a000)                     = 0x6085d014a000
    futex(0x79d31062977c, FUTEX_WAKE_PRIVATE, 2147483647) = 0
--> openat(AT_FDCWD, "sample.txt", O_RDONLY) = -1 ENOENT (No such file or directory)
    write(2, "Error: File not found!\n", 23Error: File not found!
    ) = 23
    exit_group(1)                           = ?
    +++ exited with 1 +++
```

**Conclusion:**
from the above output "_lines with pointing arrows_", we can conclude that there is an issue related to access the file mentioned ... "File not found!"
