
# **TOPICS**:
- ### [[#01. Basics]]
	- #### [[#1.1. shebang]]
	- #### [[#1.2. Basic Syntax]]
- ### [[#02. Inputs]]
	- #### [[#2.1. Global Variables]]
	- #### [[#2.2. Positional Parameters]]
	- #### [[#2.3. Script Dynamic Behavior Use cases.]]
- ### [[#03. Results]]
	- #### [[#3.1. Using Keyword]]
	- #### [[#3.2. Redirect in file]]
- ### [[#04. Operations]]
	- #### [[#4.1. Numbers]]
	- #### [[#4.2. Strings]]
	- #### [[#4.3. Files]]
	- #### [[#4.4. Directories]]

## 01. Basics
#### 1.1. shebang 
Identify which interpreter to be used to run this script .... 
`#!/usr/bin/bash` used for bash scripts
#### 1.2. Basic Syntax
- Print on Console
```bash
echo "Hello World"
echo "${Variable_NAME} ${$1}"
```
- Variable
```bash
USERNAME="Ahmed"
AGE=31

echo "Username is ${USERNAME} and Age is ${AGE}"
```

- Read from console
```bash
USERNAME=""

echo "Please Enter the Username: "
read USERNAME

read PASSWORD  # Read will create the variable if not exists, then assign value
```


### 02. Inputs
#### 2.1. Global Variables
```bash
USERNAME="ahmedmontasser"
PASSWORD="******"
```

#### 2.2. Positional Parameters
Ability to send input for a script when running it, and this inputs are saved in specific variables in bash.
**`$0`** : Script Name
**`$1`** : Input 1
**`$2`** : Input 2
**`$N`** : Input N
**`$#`** : Number of Input Parameters
```
$ ./MY_SCRIPT <INPUT_1> <INPUT_2> ... <INPUT_N>
```

#### 2.3. Script Dynamic Behavior Use cases.
- Interactive Mode
```bash
##### INTERACTIVE SECTION #####
echo "Enter config 1"
read config1

echo "Enter config 2"
read config2

##### SCRIPT OPERATION #####
```

- conf file Mode
```bash
## CONF FILE ##
config1=""
config2=""
```

```bash
##### INCLUDE CONF SECTION #####
source ./my.conf

##### SCRIPT OPERATION #####
```


### 03. Results
#### 3.1. Using Keyword
```bash
echo "The Return Variable ${retResult}"
#OR#
printf "User name is %s and age is %d" "${USER}" 31
```
#### 3.2. Redirect in file
```bash
echo "The Return Variable ${retResult}" > output.txt
```

### 04. Operations
#### 4.1. Numbers
- Arithmetic Operations
```bash
NUM1=10
NUM2=20

RESULT=$((NUM1 + NUM2))

```
#### 4.2. Strings
```bash
str1="Ahmed"
str2="Montasser"

concatStr="${str1}${str2}"
substring=$(echo -e "${concatStr:0:4}")
```
#### 4.3. Files

#### 4.4. Directories

#### 4.5. Conditions
```bash
if [[ "${str1}" != "${str2}" ]]
	# MY CODE
fi

```
