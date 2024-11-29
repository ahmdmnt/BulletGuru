# TOPICS:
- ### [[#01. Introduction to Process Management]]
- ### [[#02. Process Management Operations]]
- ### [[# ]]
- ### [[# ]]
- ### [[# ]]
- ### [[# ]]
- ### [[# ]]
- ### [[# ]]

## 01. Introduction to Process Management

### 1.1. Process Definition:
**Process is actually an Application or Program that is loaded and running on System RAM.**

![[Pasted image 20241126155026.png]]

### 1.2. Run and Load Operation:
#### Run:
1. Open Terminal.
2. Write Execution command for Application `./<APPLICATION_NAME>`.
#### Load:
4. Make a copy of Application in RAM.
5.  Application now is considered a Process.
6. Give Characteristics to this Process.
	1. **Process ID (PID).**
	2. **Priority.**
	3.  **State.**
	4. **Time from CPU (CPU Load).**
	5. **Take part from RAM.**

### 1.3. Process Management Location
Unlike other Stacks in Linux... Process Management stack is not located in a certain directory.
it is just normally part of Kernel modules.
![[Pasted image 20241126160520.png]]

## 02. Process Management Operations and Commands
#### 1. Monitor Processes.
```shell
	$ ps aux | grep "SEARCH_TEXT"
	$ ps -ef | grep "SEARCH_TEXT"
	$ top
	$ htop
	$ jobs    -> List bg jobs in bash session
```
#### 2. Start/Execute a Process.
```Shell
	$ ./<APPLICATION_NAME>              "Foreground"
	$ ./<APPLICATION_NAME> &            "Background"
	$ jobs                              "Check process run from current bash"
	$ fg %<NUM_VALUE>                   "Run stopped process in fg"
	$ bg %<NUM_VALUE>                   "Run stopped process in bg"
```
#### 3. Terminate a Process.
```shell
	$ kill <PID>
	$ kill -9 <PID>
	$ killall <PROCESS_NAME>
	$ pkill <PROCESS_NAME>
```
#### 4. Stop a Process.
```shell
	[Signal]: Ctrl + Z 
```
#### 5. Change Process Priority.
```shell
	$ sudo nice -n <NI_VALUE> <APPLICATION_NAME>
	$ sudo renice -n <NI_VALUE> <APPLICATION_NAME>
```
#### 6. Get relation between System Processes.
```shell
	$ pstree
```
#### 7. Get Information about HW capabilities.
```shell
	$ 
```

## 03. Processes States.
![[Pasted image 20241129105103.png]]
#### 3.1. Running state:
Process is currently executing in CPU.
```shell
$ top
	top - 10:47:53 up  6:03,  0 users,  load average: 0.00, 0.00, 0.00
	Tasks:   5 total,   1 running,   4 sleeping,   0 stopped,   0 zombie
	%Cpu(s):  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
	MiB Mem :  12524.2 total,  12365.4 free,    100.0 used,     58.7 buff/cache
	MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.  12247.4 avail Mem
	
	  PID USER      PR  NI    VIRT    RES    SHR [[S]]  %CPU  %MEM     TIME+ COMMAND
	   63 ahmedmo+  20   0    7788   3224   2864 [[R]]   0.0   0.0   0:00.11 top
```
#### 3.2. Waiting state:
Process is waiting for certain event to be ready back for execution.

#### 3.3. Ready state:
Process is ready for execution but currently there is a higher priority task is taking the CPU.

#### 3.4. Stopped state:
Process is currently stopped not executed `Ctrl + Z`.

#### 3.5. Terminated state:
Process is currently terminated no longer available in Process Management `Ctrl + C`.


## 04. Processes Priority.
##### 4.1. Explanation:
##### There are two columns represents Priority of the Process.
1. **Nice** **[NI]**:  *Suggestion for user*.
   Recommendation for the Kernel to assign Priority equal or near Nice values.
   but actual priority value is decided by kernel.
   
	- Highest **[-20] --> [19]** Lowest.
	
1. **Priority** **[PR]**: *Actual Priority of running priority*.
	Kernel assign acutal Priority value for running process.
	user running process nice value is mapped to range from 0 to 39
	however kernel also have the capability to assign the process priority through whole range from **-51 to 49**.
	
	- Highest  [-51] -> **[0] --> [39]** -> [49]  Lowest.

``` shell
$ top
	top - 10:47:53 up  6:03,  0 users,  load average: 0.00, 0.00, 0.00
	Tasks:   5 total,   1 running,   4 sleeping,   0 stopped,   0 zombie
	%Cpu(s):  0.0 us,  0.0 sy,  0.0 ni,100.0 id,  0.0 wa,  0.0 hi,  0.0 si,  0.0 st
	MiB Mem :  12524.2 total,  12365.4 free,    100.0 used,     58.7 buff/cache
	MiB Swap:   4096.0 total,   4096.0 free,      0.0 used.  12247.4 avail Mem
	
	  PID USER      [[PR]]  [[NI]]    VIRT    RES    SHR S  %CPU  %MEM     TIME+ COMMAND
	    1 root      [[20]]   [[0]]     908    540    472 S   0.0   0.0   0:00.02 init
	    7 root      [[20]]   [[0]]     908     88     20 S   0.0   0.0   0:00.00 init
```
##### User can only manipulate the NI value... then Kernel can take the decision and calculate how the Process Priority will be manipulated.
##### 4.2. Process Priority Operations:
**Nice and Renice Commands**
```shell
% Run a Process with adjusted nice value %
	$ sudo nice -n <NICE_VALUE> <COMMAND/APPLICATION>
	
% Adjusting nice value of an already running Process %
	$ sudo renice -n <NICE_VALUE> -p <PID>

% Adjusting nice value of all running Processes by Input User %
	$ sudo renice -n <NICE_VALUE> -u <USER_ID>
```

## 05. Processes Relation-ship
### 5.1. Explanation:
##### After the System power on "booting" the kernel starts the first process, which is Init Process with PID=1.
##### **Init Process:** is the Parent process for rest of system processes, most probably it is `systemd` process, then kernel have the ability to start rest of Managers/Processes. for ex: GUI, Network, etc..

![[Pasted image 20241129113955.png]]
##### So, there is a relation ship between the whole processes in the Linux System.

### 5.2. Operation Command:
```shell
$ pstree
	init─┬─init───init───bash───pstree
	     └─{init}
```


## 06. Information Hardware Capabilities:
### 6.1. Operation Command:
1. **Check the Number of CPU Cores**
```
$ nproc
	
```


