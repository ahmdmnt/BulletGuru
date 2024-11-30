# TOPICS:
 - ### [[# 01. Filesystem Layered Diagram]]
 - ### [[# 02. Virtual Filesystem]]
 - ### [[# 03. Operations on VFS]]
 - ### [[#04. root file-system]] 
 - ### [[#05. Commands on File System]]
 - ### [[#06. Main Operations in FS Stack.]]
	 - #### [[#6.1. Storage Management on Device]]
		 - ##### [[#6.1.1. Create Partitions]]
		 - ##### [[#6.1.2. Set File-System Types]]
		 - ##### [[#6.1.3. Mount the Storage Partition/Device]]
		 - ##### [[#6.1.4. Practice]]

## 01. Filesystem Layered Diagram

| Filesystem Stack         |
| ------------------------ |
| Userspace                |
| Virtual Filesystem (VFS) |
| Drivers                  |
| SD CARD (HW)             |

### 1.1. Introduction:
**File system is part of Kernel-Space. all related files are located in separate directory.**

> [!From user-space perspective]
> FS is view of different Directories and Files in Storage Device (ex: SD Card).

> [!From kernel-space perspective] 
> It perform the mapping between the userspace view to actual storage in Hardware.

### 1.2. What is usage of Filesystem Stack?
It map between the User space file structure view and perform any needed operations over it through filesystem stack software.

### 1.3. Types of Filesystem:
There are different type of Filesystems for example, EXT3, EXT4, etc..

## 02. Virtual Filesystem
### 2.1. Definition:
##### Type of Filesystem "Abstract/Generic" that have the ability to add and remove different filesystem.
##### Commonly-Used in Linux.

## 03. Operations on VFS
**Everything in Linux is a file ... so to interact with hardware, you need to interact with a file**
#### 1. Add "Mount" a Specific type of Filesystem (ext3, ext4, hpfs, etc...).
Mount is simply link the Hardware Storage using a certain Entry Point, give it the ability to access storage drive through a Directory.
    - Specify the Hardware "Device File" and Filesystem type u need to mount with a Certain Directory
    ` $ mount <FS_TYPE> <PATH/DEVICE_FILE> <PATH/TARGET_DIRECTORY_IN_USERSPACE>`

#### 2. Remove "Unmount" a Specific type of Filesystem.
Unmount is simply break the link with Hardware Storage.
    - Specify only the  Hardware "Device File" or directory.
    ` $ unmount <PATH/DEVICE_FILE>`
    ` $ unmount <PATH/DIRECTORY_IN_USERSPACE>`

**There is a Hash table for all mounted devices in System.**

| Filesystem Type | Device Name | Directory |
| --------------- | ----------- | --------- |
| ext4            | sda         | /         |
| ext3            | sdb         | /home     |
| ...             | ...         | ...       |

## 04. root file-system
#### In System startup, for the Kernel to get up ... at least there should be one filesystem is mounted in VFS.
#### this filesystem is **rootfs** .. rootfs is mounted on **[ / ]**.
- Any other Filesystem is under this main filesystem.
.
#### 4.1. rootfs hierarchy contains:
**Root Filesystem contains either directories or files.**
**- List of Main Directories in Linux**

| Directories | Description                                                                                                                         |
| ----------- | ----------------------------------------------------------------------------------------------------------------------------------- |
| **`/bin`**  | binary or executable programs.                                                                                                      |
| **`/sbin`** | binary or executable programs.                                                                                                      |
| **`/etc`**  | system configuration files.                                                                                                         |
| **`/boot`** | It contains all the boot-related files and folders such as conf, grub, etc.                                                         |
| **`/dev`**  | It is the location of the device files such as dev/sda1, dev/sda2, etc.                                                             |
| **`/lib`**  | It contains kernel modules and a shared library.                                                                                    |
| **`/mnt`**  | It contains temporary mount directories for mounting the file system.                                                               |
| **`/proc`** | It is a virtual and pseudo-file system to contains info about the running processes with a specific process ID or PID.              |
| **`/sys`**  | It is a virtual file system for modern Linux distributions to store and allows modification of the devices connected to the system. |
| **`/var`**  | log files.                                                                                                                          |
| **`/usr`**  | User related programs.                                                                                                              |
| **`/opt`**  | optional or third-party software.                                                                                                   |
| **`/tmp`**  | temporary space, typically cleared on reboot.                                                                                       |
| **`/root`** | Root user, home directory.                                                                                                          |
| **`/home`** | home directory. It is the default current directory.                                                                                |

## 05. Commands on File System
**For Directories**
- Create Directory: `$ mkdir <DIRECTORY_NAME>`.
- Remove Directory: `$ rm -r <DIRECTORY_NAME>`.
- Open Directory: `$ cd <DIRECTORY_PATH/NAME>`.
- Copy Directory: `$ cp -r <SRC_DIRECTORY> <DST_DIRECTORY>`.
- Move/Rename Directory: `$ mv <SRC_DIRECTORY> <DST_DIRECTORY>`.
- Print Directory PATH: `$ pwd`.
- List Content of Directory: `$ ls -l`.

**For Files**
- Create File: `$ touch/vi <FILE_NAME>`.
- Remove File: `$ rm <FILE_NAME>`.
- Open File: `$ vi <FILE_PATH/NAME>`.
- Print File: `$ cat <FILE_PATH/NAME>`.
- Copy File: `$ cp <SRC_FILE> <DST_FILE>`.
- Move/Rename File: `$ mv -r <SRC_FILE> <DST_FILE>`.

**Part of User Management Stack**
- Change Ownership: `$ chown <USER>:<GROUP> <NAME>`.
- Change Permission: `$ chmod [u/g/a][+/-][r/w/x/a] <NAME>`.
- Get Directory Information: `$ ls -al`.
- **Get File Information:** `$ file/stat <FILE_NAME>`.


## 06. Main Operations in FS Stack. 
### 6.1. Storage Management on Device
Any Storage Device in *Hardware Layer* is available in user-space as Block Device File.. **[b]**.
- **Storage device files available under `/dev/<STORAGE_NAME>`**
- **Get Information about storage devices and its partitions.**
```
	$ lsblk	
```
#### 6.1.1. Create Partitions
##### Partition Description:
**[Type]** | **[Name]** | **[Number]** | **[Size]**
##### Partition Types:
1. **Primary** : Main Partition, can contain OS and boot from it "Bootable".
2. **Extended/Logical** : Just for Data Storage.
##### Summarized Steps:
Create Two Partitions, (1. Primary & 2. Logical).
1. Set Partition Type.
2. Set Partition Number.
3. Set First Sector.
4. Set Last Sector.
5. Save Changes.

##### Main Commands:
- List all System Partitions.
```
	$ fdisk -l
```
- Clear all Data in Partition or Storage Device.
```
	$ sudo dd if=/dev/zero of=/dev/<STORAGE/PARTITION_NAME>
```
- Unmount Device {in case it is mounted before manipulation}.
```
	$ sudo umount /dev/<STORAGE/PARTITION_NAME>
```
- Manipulate certain storage device 
	*Storage Device itself and Each Partition under it has standalone file to Manipulate it.*
```
	$ sudo fdisk /dev/<STORAGE/PARTITION_NAME>
	$ m -> "For help Manual"
```
- Create Partition.
```
	$ sudo fdisk /dev/<STORAGE_NAME>
	$ n      [New Partition]
	$ p      [Type: Primary]
	$ 1      [Number: 1]
	$ enter  [First Sector: default selection "Sector Size: 512Byte"]
	$ +200M  [Last Sector = Partition Size: 200M]
	$ w
```

####  6.1.2. Set File-System Types:
After Creation of a Partition, we need to set the File-System Type.
We need to check support FS types to the Kernel
```
	$ man fs
```
##### FS Types:
1. **ext2** : 
	1. It supports a maximum file size of 4TB.
	2. The maximum file name length is 255 bytes characters.
	3. It can track the state of the file system.
	4. No file journaling
2. **ext3** : 
	-  It is better than ext2, because it has a journaling feature that is mainly required from a file system.
3. **ext4** :
	- It is better than ext3, it provides better performance, reliability, and scalability.

##### Main Commands:
- Install FS on a Partition.
```
	$ sudo mkfs -t <FS_TYPE> </PATH/PARTITION_NAME>
```

####  6.1.3. Mount the Storage Partition/Device:
After Creation of a Partition and Installation of FS, we need to mount the storage area to be able to use it.

- mount a Storage Partition.
```
	$ mkdir /PATH/<MOUNTING_DIRECTORY>   -> ex. PATH=/mnt or /media or /home/user 
	$ sudo mount -t ext4 /dev/<PARTITION_NAME> /PATH/<MOUNTING_DIRECTORY>
```
##### **IMPORTANT:** this will create a Temporary Mounting Point not <span style="color:red">Permanent</span>.
To Create a Permanent Mounting Point... you need to add it in **`fstab`**.
```
	$ cat /etc/fstab
```
if a reboot occurs... the mounting point will persists normally. 

####  6.1.4. Practice:
**Description:**
 Create two Logical Partitions equally in size... one is ext3 and another is ext4. and mount them in directories located in /mnt
**Steps:** 
	1. Clear Storage.
	2. Unmount Storage if mounted.
	3. Create Partitions and save/write configurations.
	4. Install FS Type to each Partition.
	5. Mount the Partitions.
```bash
$ fdisk -l
	Disk /dev/sda: 7.68 GiB, 8242855936 bytes, 16099328 sectors
	Disk model: Flash Disk      
	Units: sectors of 1 * 512 = 512 bytes
	Sector size (logical/physical): 512 bytes / 512 bytes
	I/O size (minimum/optimal): 512 bytes / 512 bytes
	Disklabel type: dos
	Disk identifier: 0x004a12a5

$ sudo fdisk /dev/sda
$ fdisk -l
	Disk /dev/sda: 7.68 GiB, 8242855936 bytes, 16099328 sectors
	Disk model: Flash Disk      
	Units: sectors of 1 * 512 = 512 bytes
	Sector size (logical/physical): 512 bytes / 512 bytes
	I/O size (minimum/optimal): 512 bytes / 512 bytes
	Disklabel type: dos
	Disk identifier: 0x004a12a5
	
	Device     Boot   Start      End Sectors  Size Id Type
	/dev/sda1          2048  7710719 7708672  3.7G 83 Linux
	/dev/sda2       7710720 16099327 8388608    4G 83 Linux
ahmedmont@ahmed-legion5:~/Documents$ 

$ sudo mkfs -t ext4 /dev/sda1
	mke2fs 1.46.5 (30-Dec-2021)
	Creating filesystem with 963584 4k blocks and 240960 inodes
	Filesystem UUID: ea552319-56ba-4870-87bd-240ca63ee930
	Superblock backups stored on blocks: 
		32768, 98304, 163840, 229376, 294912, 819200, 884736
	
	Allocating group tables: done                            
	Writing inode tables: done                            
	Creating journal (16384 blocks): 
	done
	Writing superblocks and filesystem accounting information: done 

$ sudo mkfs -t ext3 /dev/sda2
	mke2fs 1.46.5 (30-Dec-2021)
	Found a dos partition table in /dev/sda2
	Proceed anyway? (y,N) y
	Creating filesystem with 1048576 4k blocks and 262144 inodes
	Filesystem UUID: 400fe476-c456-492a-9c79-48d5edc4e371
	Superblock backups stored on blocks: 
		32768, 98304, 163840, 229376, 294912, 819200, 884736
	
	Allocating group tables: done                            
	Writing inode tables: done                            
	Creating journal (16384 blocks): done
	Writing superblocks and filesystem accounting information: done 

$ sudo mkdir /media/usb_drive1
$ sudo mkdir /media/usb_drive2
$ sudo mount /dev/sda1 /media/usb_drive1
$ sudo mount /dev/sda2 /media/usb_drive2

$ sudo touch file.txt
$ sudo vi file.txt 
$ cat file.txt 
	Hello
```




