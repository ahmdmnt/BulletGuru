#!/usr/bin/bash

### DESCRIPTION:-
# Bash script that serves as a simple process monitor, 
# allowing users to view, manage, and analyze running processes on a Unix-like system.

# Features:
# 1. 
# Process Information:
# Provide detailed information about a specific process, including its PID, parent process ID, user, CPU and memory usage, etc.
# 2. 
# Kill a Process:
# Allow users to terminate a specific process by entering its PID.
# 3. 
# Process Statistics:
# Display overall system process statistics, such as the total number of processes, memory usage, and CPU load. 
# 4. 
# Real-time Monitoring:
# Implement real-time monitoring, updating the display at regular intervals to show the latest process information.
# 5. 
# Search and Filter:
# Allow users to search for processes based on criteria such as name, user, or resource usage.
# 6. 
# Interactive Mode:
# Implement an interactive mode where users can choose operations from a menu.
# 7. 
# Resource Usage Alerts:
# Set up alerts for processes exceeding predefined resource usage thresholds.
# 8.
# Logging:
# Include logging features to record process-related activities, especially when a process is terminated.
# 9. 
# Configuration Options:
# Allow users to configure the script through a configuration file. For example, users might specify the update interval, alert thresholds, etc.
#######################################################################################

#!/bin/bash

#### Process Monitor Script :-
################################

function show_menu() {
    echo "============================"
    echo " Simple Process Monitor"
    echo "============================"
    echo "1. List all processes"
    echo "2. Search for a process by name"
    echo "3. Kill a process by PID"
    echo "4. Display System Stats"
    echo "5. Exit"
    echo "============================"
    echo -n "Enter your choice: "
}

function list_processes() {
    echo ""
    echo "Listing all running processes:"
    echo "-----------------------------"
    ps -eo user,ppid,pid,time,%cpu,%mem | head -n 20
}

function search_process() {
    echo ""
    echo -n "Enter the name of the process to search: "
    read -r INPUT_TEXT

    if [ -z "$INPUT_TEXT" ]; then
        echo "Process name cannot be empty."
        return
    fi

    echo ""
    echo "Searching for processes with name: $INPUT_TEXT"
    echo "------------------------------------------"
    ps -eo pid,user,%cpu,%mem,command | head -n 1 
    ps -eo pid,user,%cpu,%mem,command | awk -v pid="$INPUT_TEXT" '$1 == pid'
    # ps -eo pid,user,%cpu,%mem,command | pgrep "$INPUT_TEXT" | pgrep -v "grep" | head -n 20
}

function kill_process() {
    echo ""
    echo -n "Enter the PID of the process to kill: "
    read -r pid

    if ! [[ "$pid" =~ ^[0-9]+$ ]]; then
        echo "Invalid PID. Please enter a numeric value."
        return
    fi

    echo "Attempting to kill process with PID: $pid"
    kill "$pid" 2>/dev/null

    if [ $? -eq 0 ]; then
        echo "Process $pid terminated successfully."
    else
        echo "Failed to terminate process $pid. Check if the PID is correct and you have the necessary permissions."
    fi
}

function display_system_stats() {
    echo ""
    echo "Overall System Process Statistics:"
    echo "---------------------------------"

    total_processes=$(ps -e --no-headers | wc -l)
    cpu_load=$(uptime)
    memory_usage=$(free -h | awk '/^Mem:/ {print $3 " used of " $2}')

    echo "Total number of processes:"
    echo " $total_processes"
    echo "CPU Load Averages:"
    echo "$cpu_load"
    echo "Memory Usage:"
    echo " $memory_usage"
}

while true; do
    show_menu
    read -r CHOICE

    case $CHOICE in
        1)
            list_processes
            ;;
        2)
            search_process
            ;;
        3)
            kill_process
            ;;
        4)
            display_system_stats
            ;;
        5)
            echo "Exiting Process Monitor. Goodbye!"
            exit 0
            ;;
        *)
            echo "Invalid choice. Please try again."
            ;;
    esac

echo ""
done

