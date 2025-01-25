#!/usr/bin/bash

### DESCRIPTION:-
# Bash script that organizes files in a specified directory 
# based on their file types into separate subdirectories. 

# Features:
# 1. The script should take a directory path as an argument.
# 2. It should create subdirectories based on the file extensions (e.g., “txt” for text files, “jpg” for image files).
#    2.1. Files with unknown or no file extensions should be placed in a “misc” subdirectory.
# 3. If a subdirectory for a particular file type already exists, the script should move the files into that existing directory.
# 4. The script should handle edge cases, such as files with no extensions or hidden files (those starting with a dot).
#######################################################################################

#!/bin/bash

# Check if the script argument is provided
if [ -z "$1" ]; then
    echo "Error! Script argument is missing!"
    echo "Usage: $0 <DIRECTORY_PATH>"
    exit 1
fi

# Check if the provided path is a valid directory
DIRECTORY_PATH="$1"
if [ ! -d "$DIRECTORY_PATH" ]; then
    echo "Error: '$DIRECTORY_PATH' is not a valid directory."
    exit 1
fi

# Iterate over the files in the specified directory
for ITEM in "$DIRECTORY_PATH"/* "$DIRECTORY_PATH"/.*; do
    # Check if it's a regular file
    if [ -f "$ITEM" ]; then
        EXTENSION="${ITEM##*.}"            # Extract the file extension
        FILENAME="$(basename "$ITEM")"     # Get the file name

        case "${EXTENSION}" in
            # Handle Text files
            "txt")
                # Check if Directory exists
                if [ ! -d "$DIRECTORY_PATH/txt/" ]; then
                    echo "Creating txt Directory..."
                    mkdir "$DIRECTORY_PATH/txt/"
                fi
                # Move Desired file in corresponding directory
                echo "  >> moving $FILENAME to txt directory..."
                mv "$ITEM" "$DIRECTORY_PATH/txt/"
            ;;
            # Handle Log files
            "log")
                # Check if Directory exists
                if [ ! -d "$DIRECTORY_PATH/log/" ]; then
                    echo "Creating LOG Directory..."
                    mkdir "$DIRECTORY_PATH/log/"
                fi
                # Move Desired file in corresponding directory
                echo "  >> moving $FILENAME to log directory..."
                mv "$ITEM" "$DIRECTORY_PATH/log/"
            ;;
            # Handle Image files
            "jpg"|"png")
                # Check if Directory exists
                if [ ! -d "$DIRECTORY_PATH/img/" ]; then
                    echo "Creating img Directory..."
                    mkdir "$DIRECTORY_PATH/img/"
                fi
                # Move Desired file in corresponding directory
                echo "  >> moving $FILENAME to img directory..."
                mv "$ITEM" "$DIRECTORY_PATH/img/"
            ;;
            # Handle SW files
            "c"|"h"|"cpp"|"hpp"|"sh"|"py")
                # Check if Directory exists
                if [ ! -d "$DIRECTORY_PATH/code/" ]; then
                    echo "Creating code Directory..."
                    mkdir "$DIRECTORY_PATH/code/"
                fi
                # Move Desired file in corresponding directory
                echo "  >> moving $FILENAME to code directory..."
                mv "$ITEM" "$DIRECTORY_PATH/code/"
            ;;
            # Handle rest of files extensions including hidden files and unknown extensions.
            *)
                # Check if Directory exists
                if [ ! -d "$DIRECTORY_PATH/misc/" ]; then
                    echo "Creating misc Directory..."
                    mkdir "$DIRECTORY_PATH/misc/"
                fi
                # Move Desired file in corresponding directory
                echo "  >> moving $FILENAME to misc directory..."
                mv "$ITEM" "$DIRECTORY_PATH/misc/"
            ;;
        esac
    fi
done