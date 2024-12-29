## Requirements.

1. Make at least two partitions on your SD-CARD using g-parted.
2. Create for each partitions filesystem ( first one ext4 & second one ext2 ).
3. Mount two partitions on your root filesystem.
4. Add some files inside each one.
5. reboot your machine.
6. check if mounting points still exists, it should not.
7. Make the ext4 persistence by adding /etc/fstab file —-> (search how you can do that).
8. reboot your system.
9. Check if the ext4 is mounted.

```
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

## Task A:
### Manipulate a FS that is read-only and make it read/write.
**Hint: Overlay**

## Task B:
### Check the Linux Behavior:
**1. Mount a File system on a Directory that contains Originally files.**
	When you mount a filesystem on a directory that already contains files, those files become **inaccessible** until the filesystem is unmounted.
	
**2. Mount two File systems on same Directory.**
	 Only the first mounted partition is only accessible.
	