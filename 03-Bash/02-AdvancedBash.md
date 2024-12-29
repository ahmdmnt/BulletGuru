
# **TOPICS:**
- ## [[# 01. Operations on Variables]]
	- #### [[#1.1. Set Default Values]]
- ## [[#02. Operations on Strings]]
	- #### [[#2.1. Sub-string]]
	- #### [[#2.2. Matching Patterns]]
- ## [[#03. Control Flow]]
	- #### [[#3.1. if.. Condition]]
	- #### [[#3.2. switch case.. Condition]]
	- #### [[#3.3. select.. Condition]]
- ## [[#04. Loops]]
	- #### [[#4.1. while.. Loop]]
	- #### [[#4.2. for.. Loop]]
- ## [[#05. Operations on Files]]
	- #### [[#5.1. read.. Files]]
	- #### [[#5.2. touch.. Files]]
	- #### [[#5.3. write.. Files]]
	- #### [[#5.4. extract data.. Files]]
- ## [[#06. Functions]]
	- #### [[#6.1. Definition and Declaration]]
	- #### [[#6.2. Function Arguments]]
	- #### [[#6.3. Variable Scopes]]
	- #### [[#6.4. return values]]
- ## [[#07. Debugging]]
	- #### [[#7.1. set.. command]]
- ## [[# 08. File Inclusion]]
- ## [[#09. Special Syntax in BASH]]
	- #### [[#9.1. or..]]
	- #### [[#9.2. and.. &&]]
	- #### [[#9.3. next.. ;]]
	- #### [[#9.4. pipe.. ]]
## 01. Operations on Variables:
#### 1.1. Set Default Values
```bash
declare NAME=""

echo "${NAME:-Ahmed}"    # If Vairiable is Empty.. Set a default value.
echo "${NAME:=Ahmed}"    # If Variable is not defined.. Define and Set Varible.
echo "${NAME:?Ahmed}"    # If Variable
```

## 02. Operations on Strings:
#### 2.1. Sub-string
```bash
declare STRING="Hello World!"

echo "${STRING: 2}"    # Remove total of 2 chars from the beginning(Cut).
echo "${STRING: -5}"   # Remove all chars,, except last 5 chars in string.
```

#### 2.2. Matching Patterns
```bash
declare FILENAME="Bash-Script-01.sh"

declare BASICNAME=${FILENAME%.*}     # Extract the Name of file with extension
echo "$BASICNAME"

declare EXTENSION=${FILENAME##*.}    # Extract the Extension of the file
echo "$EXTENSION"

declare STRING="Hello World!"
if [[ "${STRING}" == *"World"* ]]; then   # Check if substring exists
	echo "String containts (World)"
fi
```

## 03. Control Flow
#### 3.1. if else.. Condition
```bash
declare -i VAR=6
if [ $VAR == 5 ]; then
	echo "VAR= 5"
else
	echo "other values"
fi
```
#### 3.2. switch case.. Condition
```bash
declare OS=$1
case "${OS}" in
	"ubuntu")
		echo "item = Ubuntu"
	;;
	"win10"|"win11")
		echo "item = Microsoft Windows"
	;;
	*)
		echo "default (none of above)"
	;;
esac
```
#### 3.3. select.. Condition
```bash
declare -i n=3

for iter in $(seq 1 1 $n); do
echo -n "${iter} "
done
echo ""

for((i=0;i<=n;i++)); do
echo -n "${i}"
done
echo ""
```

## 04. Loops
#### 4.1. while.. Loop
```bash
declare -i VAR=5

while (( VAR < 10 )); do
VAR=${VAR}+1
echo "Increment"
done

echo "${VAR}"
```
#### 4.2. for.. Loop
```bash
declare -i n=3

for iter in $(seq 1 1 $n); do
echo -n "${iter} "
done
echo ""

for((i=0;i<=n;i++)); do
echo -n "${i}"
done
echo ""
```

## 05. Operations on Files
#### 5.1. read.. Files
```bash
cat $1 | while read line; do
	echo "${line}"
done

while IFS= read -r line; do
	echo "$line"
done < "$1"
```
#### 5.2. touch.. Files
```bash
FILENAME="file.txt"

# Check if the file exists
if [[ ! -e "$FILENAME" ]]; then
	touch "$FILENAME"
	echo "File created: $FILENAME"
fi
```
#### 5.3. write.. Files
```bash
echo "This is a newly created file" > $FILENAME  # Overwrite with new content.
echo "adding a new line as well" >> $FILENAME    # Append the new content.
```

#### 5.4. extract data.. Files
```bash
# Extract data (XXXX) in line starts with "Username: XXXX"
while IFS= read -r line; do
	if [[ $line == Username:\ * ]]; then
		username="${line#Username: }"
		echo "$username"
	fi
done < "data.txt"
```

## 06. Functions
#### 6.1. Definition and Declaration
```bash
#Function Definition
function name () {
	echo "function called"
}
###################################################

#Function Call
name
```
#### 6.2. Function Arguments
```bash
#Function Definition
function name () {
	if (( $# == 0 )); then
		echo "No Function arguments passed!!"
	else
		echo "function arg: $1"
	done
}
###################################################

#Function Call <FUNCTION_NAME> "ARG#1" ..."ARG#N"
name "$NAME"
name
```
#### 6.3. Variable Scopes
```bash
# Global Variable
MY_VAR_1="Ahmed"
MY_VAR_2="Montasser"

echo "${MY_VAR_1}"
echo "${MY_VAR_2}"

function MY_FU() {
	MY_VAR_1="Ammar"     # Affects the Global Variable
	local MY_VAR_2="Abdelreheem"   # New Local Variable Created
}
###################################################

MY_FU
echo "${MY_VAR_1}"
echo "${MY_VAR_2}"
```
#### 6.4. return values
```bash
#Function Definition
function retFunction () {
	# Any Operation
	# ...
	return 10
}
###################################################

declare -i RET_VALUE=""
# To check the Return Value.. through Special variable "$?"
retFunction
RET_VALUE=$?
echo "Return Value = ${RET_VALUE}"


declare -i RET_STATUS=""
# Here, it return the function execution status
RET_STATUS=retFunction
echo "Execution Status = ${RET_STATUS}"
```

```bash
#Function Definition
function retString () {
	# Any Operation
	# ...
	echo "This is the RETURN String"
}
################################################### 

declare RET_VAL=`retString`
echo "Return String= ${RET_VAL}"
```

## 07. Debugging 
#### 7.1. set.. command
**- Error Monitoring**
```bash
#!/usr/bin/bash

# Once an Error is Detect, Script Terminates, after Error.
# Normally what happens if it it not there, the script resumes running and output only the error in that command.

set -e                  # Activate Error Monitoring
echo "Command 1 ... "
echo "Command 2 ... "
eco  "Command 3 ... "   # Script stops execution here and terminates <<<
echo "Command 4 ... "
set +e                  # Deactivate Error Monitoring

echo "Command 5 ... "
echo "Command 6 ... "
```

**- Tracing**
```bash
#!/usr/bin/bash

# Write each command, and its execution result

set -x                  # Activate Tracing
echo "Command 1 ... "
echo "Command 2 ... "
set +x                  # Deactivate Tracing

echo "Command 5 ... "
echo "Command 6 ... "
```

**- Tracing**
```bash
#!/usr/bin/bash

# Write each command, and its execution result

set -x                  # Activate Tracing
echo "Command 1 ... "
echo "Command 2 ... "
set +x                  # Deactivate Tracing

echo "Command 5 ... "
echo "Command 6 ... "
```

**- Undefined Variables Error Tracing**
```bash
#!/usr/bin/bash

# Monitoring for accessing undefined variables

echo "Username = ${Usernama} "    # Not Monitored

set -u                  # Activate 
echo "Command 1 ... "
echo "Username = ${Usernama} "    # Monitored
echo "Command 3 ... "
set +u                  # Deactivate 

echo "Command 5 ... "
echo "Command 6 ... "
```

## 08. File Inclusion
```bash
#!/usr/bin/bash

source BASH_SCRIPT_NAME.sh
```

## 09. Special Syntax in BASH
#### 9.1. or.. ||
**If a command succeeded it will ignore rest of incoming other commands**
```bash
touch file1.txt || touch file2.txt    # not execute 2nd cmd
touc file3.txt || touch file4.txt     # execute 2nd cmd becuz 1st on is failed
```
#### 9.2. and.. &&
**Will execute all commands in line if all are succeeding**
```bash
touch file1.txt && touch file2.txt    # execute both
touc file3.txt && touch file4.txt     # execute NONE
```
#### 9.3. next.. ;
**Execute Command after each other in same line**
```bash
touch file1.txt;touch file2.txt    # execute all
touc file3.txt;touch file4.txt     # execute all
```
#### 9.4. pipe.. |
**Redirect output of command one as an input to command two**
```bash
cat file.txt | grep -i "WORD"
```

