### Part of File System Stack is Access Control Features
- #### Which include the User Management sub-stack.
# TOPICS:
 - ## [[# 01. Definitions]]
- ## [[# 02.Operations]]
	- #### [[#2.1. Users]]
	- #### [[#2.2. Resources]]
	- #### [[#2.3. Groups]]

## 01. Definitions:
**Linux is a Multi-user environment:**
	Check current active users in Linux OS. `$ top`.
### - User: 
Accessing any Linux System is done through a certain user, example for users: root, admin,  etc...
	Operations:
		- Create/Delete User.
		- Monitor User.
		- Change User Properties.
		- Add/Remove User from Group(s).	
### - Process:
**Any Action in the System is done in a process scheduled in the system and have its ID and properties.**
	ex. accessing a Resource >> done through a process.
### - Resources:
**Resources are for example: files, system calls, etc..**
	Operations:
		- Access a resource.
		- Change Permissions.
		- All Filesystem operation...
### - Permissions:
**Set of rules applied on each resource to manage accessing them.**
	Who have the ability to access and with what type of permissions.
		- Permission types: Read, Write and Execute.
### - Group:
**Ability to group multiple users together under same grouping.**
	Operations:
		- Create/Delete Group.
		- Monitor Group.
		- Change Group properties.


## 02.Operations:
#### 2.1. Users:
```bash
$ adduser USER_NAME   # add new user to Linux OS.
	# prompt to assign the user password.

$ sudo su USER_NAME   # Switch to different users.
$ sudo su             # Switch user to root user.

$ id              # Get Information about UserId, GroupId(s) and Group Name(s).

$ sudo deluser USER_NAME   # delete an existing user.
	# --remove-home        # Option to remove user home directory
	# --remove-all-files   # Option to remove related files to this user.

$ sudo usermod [OPTION]    # Change Username / Uid / Shell / Groups / Home Path
	# --login [NEW_USERNAME] [USERNAME]
	# --uid [NEW_UID] [USERNAME]
	# --shell [NEW_SHELL_PATH] [USERNAME]
	# --append --groups [GROUP1..GROUPN] [USERNAME]
	# --move-home --home [NEW_HOME_PATH] [USERNAME]

$ top      # Get information about active users
$ W        # Get information about active users
```

#### 2.2.  Resources:
```bash
$ stat FILENAME     # Get Extended information about a file
  File: zombie.c
	  Size: 561       	    Blocks: 8              IO Block: 4096 regular file
	Device: 10304h/66308d	 Inode: 8916351           Links: 1
	Access: (0664/-rw-rw-r--)  Uid: ( 1000/ahmedmont)   Gid: ( 1000/ahmedmont) 
	Access: 2024-11-25 19:41:58.214252753 +0200
	Modify: 2024-11-25 19:41:49.525415302 +0200
	Change: 2024-11-25 19:41:49.530415209 +0200
	 Birth: 2024-11-25 19:41:49.519415414 +0200
## File Permission in Row #4

$ chmod [u/g/o][+/-][r/w/x/a] [FILENAME] # Change Permission for certain file.
$ chmod [XXX] [FILENAME]    # Change Permission, where XXX are Numbers [0 to 7]
	## Each X represent Permission for a User, Group and Others
		## 1 Execute.
		## 2 Write
		## 4 Read
```

#### 2.3. Groups:
**Primary Group:** at each user creation, the user is assigned to a primary group with the same name of user.
**Secondary Group:** any user can be assigned to other group(s). to give that user extra access control for resources, for example: sudo group.
```bash
# Add a new Group
$ sudo groupadd [GROUPNAME]

# Add to different secondary group(s).
$ sudo usermod --append --groups [GROUP1 .. GROUP-N] [USERNAME]

# Change USER OR GROUP of a Resource.
$ sudo chown [USERNAME]:[GROUP] [FILE_NAME]

# Delete Group or change Group Properties
$ sudo groupdel ....
$ sudo chgrp ...
```





