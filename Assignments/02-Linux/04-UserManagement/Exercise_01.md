# Exercise 1: 
## File Permissions and Ownership
- Create a directory called access_practice.
```bash
    $ mkdir access_practice
```
- Inside the directory, create a file named secret.txt.
```bash
    $ cd access_practice
    $ touch secret.txt
```
- Set the file permissions to allow read and write access for the owner, and no access for group and others.
```bash
    $ chmod 600 secret.text
```
- Change the ownership of the file to a different user.
```bash
    $ sudo chown AuxUser secret.txt 
    $ ll
        total 8
        -rw------- 1 AuxUser   ahmedmont    0 Jan 16 12:52 secret.txt
```
- Try accessing the file from the original and the different user accounts to observe the access permissions in action.
```bash
    $ cat secret.txt 
        cat: secret.txt: Permission denied
```