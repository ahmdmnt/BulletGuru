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


## Task A:
### Manipulate a FS that is read-only and make it read/write.
**Hint: Overlay**

## Task B:
### Check the Linux Behaviour:
**1. Mount a File system on a Directory that contains Originally files.**
**2. Mount two File systems on same Directory.**
 