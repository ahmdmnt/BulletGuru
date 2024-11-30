# commands-fs

## Exercise 1: Basic Navigation

- Use ls to list all files and directories in the current directory.
```
$ ls -ltrh
	total 72K
	drwxr-xr-x  2 ahmedmont ahmedmont 4.0K Nov  3 15:52 Templates
	drwxr-xr-x  2 ahmedmont ahmedmont 4.0K Nov  3 15:52 Desktop
	drwxr-xr-x  2 ahmedmont ahmedmont 4.0K Nov  3 15:52 Videos
	drwxr-xr-x  2 ahmedmont ahmedmont 4.0K Nov  3 15:52 Public
	drwxr-xr-x  2 ahmedmont ahmedmont 4.0K Nov  3 15:52 Music
	drwxrwxr-x  2 ahmedmont ahmedmont 4.0K Nov  3 16:19 _files
	drwxr-xr-x  3 ahmedmont ahmedmont 4.0K Nov  7 00:37 Pictures
	drwxrwxr-x  4 ahmedmont ahmedmont 4.0K Nov  9 10:42 _embeddedLinux
	drwxrwxr-x  2 ahmedmont ahmedmont 4.0K Nov 12 19:58 Assignment01
	drwxr-xr-x  3 ahmedmont ahmedmont 4.0K Nov 15 11:09 Documents
	drwx------ 11 ahmedmont ahmedmont 4.0K Nov 15 14:28 snap
	-rw-rw-r--  1 ahmedmont ahmedmont  561 Nov 25 19:41 zombie.c
	-rwxrwxr-x  1 ahmedmont ahmedmont  16K Nov 25 19:41 zombie
	drwxr-xr-x  3 ahmedmont ahmedmont 4.0K Nov 30 10:00 Downloads
	drwxrwxr-x  6 ahmedmont ahmedmont 4.0K Nov 30 10:02 _gitHub

```
- Use cd to navigate to a specific directory.
```
$ cd _gitHub/
```
- Use pwd to print the current working directory.
```
$ pwd
	/home/ahmedmont/_gitHub
```

## Exercise 2: File and Directory Operations

- Create a directory named “practice” in the current directory using mkdir.
```
$ mkdir practice
```
- Create an empty file named “file.txt” within the “practice” directory using touch.
```
$ touch practice/file.txt 
```
- Copy “file.txt” to a new file “file_backup.txt” using cp.
```
$ cp practice/file.txt practice/file_backup.txt
```
- Move “file_backup.txt” to another directory using mv.
```
mv practice/file_backup.txt practice2/
```
- Rename “file.txt” to “new_file.txt” using mv.
```
$ mv file.txt new_file.txt
$ ll
	total 8
	-rw-rw-r-- 1 ahmedmont ahmedmont    0 Nov 30 10:46 new_file.txt
```
- Delete the “new_file.txt” using rm.
```
$ rm -f new_file.txt 
```

## Exercise 3: File Viewing and Editing

Create a text file using echo or a text editor like nano. View the contents of the file using cat. View the contents of the file using less. Edit the file using nano or another text editor. Redirect the output of a command (e.g., ls) to a file using >.
```
$ vi myfile.txt
$ cat myfile.txt 
	Hello World!
$ ls -l >> myfile.txt 
$ cat myfile.txt 
	Hello World!
	total 4
	-rw-rw-r-- 1 ahmedmont ahmedmont 13 Nov 30 11:10 myfile.txt
```
## Exercise 4: File Permissions

Create a file and set specific permissions using chmod. Check the permissions of the file using ls -l. Change the owner and group of the file using chown. Verify the changes using ls -l.
```
$ chmod a+x myfile.txt 
$ ls -ltrh
	total 4.0K
	-rwxrwxr-x 1 ahmedmont ahmedmont 81 Nov 30 11:11 myfile.txt
---------------------------------------------------------------------
$ chmod 777 myfile.txt 
$ ls -ltrh
	total 4.0K
	-rwxrwxrwx 1 ahmedmont ahmedmont 81 Nov 30 11:11 myfile.txt
---------------------------------------------------------------------
$ sudo chown swGuru:developers myfile.txt 
$ ls -ltrh
	total 4.0K
	-rwxrwxrwx 1 swGuru developers 81 Nov 30 11:11 myfile.txt
---------------------------------------------------------------------
$ sudo userdel -r swGuru
	userdel: swGuru mail spool (/var/mail/swGuru) not found
$ id swGuru
	id: ‘swGuru’: no such user
$ sudo groupdel developers
$ grep developers /etc/group
```
## Exercise 5: User and Group Management

Create a new user using useradd. Set a password for the new user using passwd. Create a new group using groupadd. Add the user to the newly created group using usermod.
```
$ sudo groupadd developers
$ sudo useradd -m -g developers swGuru
$ id swGuru
	uid=1001(swGuru) gid=1001(developers) groups=1001(developers)
$ sudo groupadd CPPdevelopers
$ sudo usermod -G CPPdevelopers swGuru
$ id swGuru
	uid=1001(swGuru) gid=1001(developers) groups=1001(developers),1002(CPPdevelopers)
$ sudo userdel -r swGuru
	userdel: swGuru mail spool (/var/mail/swGuru) not found
$ sudo groupdel developers
$ sudo groupdel CPPdevelopers
$ id swGuru
	id: ‘swGuru’: no such user
$ grep -i developers /etc/group
$ grep -i CPPdevelopers /etc/group
```

## Exercise 6: Process Management

List all processes using ps. List processes in real-time using top. Find a specific process using pgrep. Terminate a process using kill.

## Exercise 7: File Searching

Use find to search for a specific file or directory. Use grep to search for a specific string in a file.cd
```
 find . -name "myfile.txt"
	./practice/myfile.txt
$ grep -i "h" practice/myfile.txt 
	Hello World!
	-rw-rw-r-- 1 ahmedmont ahmedmont 13 Nov 30 11:10 myfile.txt
```