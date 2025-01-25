# Exercise 2: 
## User and Group Management
- Create a new user named user1.
```bash
    $ sudo useradd user1
```
- Create a new group named group1.
```bash
    $ sudo groupadd group1
```
- Add user1 to group1.
```bash
    $ sudo usermod -a -G group1 user1
```
- Change the ownership of secret.txt to user1 and group1.
```bash
    $ sudo chown user1:group1 secret.txt 
```
- Set the file permissions to allow read and write access for the owner and the group.
```bash
    $ sudo chmod 660 secret.txt 
```
- Test accessing the file both as user1 and a different user to understand group-based access control.
```bash
    $ cat secret.txt 
```