#!/bin/bash

#get Hostname
export HOSTNAME=$(hostname)
echo "Hostname: $HOSTNAME"

#get Timezone
export TIMEZONE=$(timedatectl | grep "Time zone" | awk '{print $3}')
export UTC=$( date +%z)
echo "Timezone: $TIMEZONE UTC $UTC"

#get User
export USER=$(whoami)
echo "User: $USER"

#get OS version 
export OS=$(hostnamectl | grep Operating | awk '{print $3,$4,$5}')
echo "OS:$OS"

#get current time 
export DATE=$(date '+%d %B %Y %T')
echo "Date: $DATE"

#get system uptime
export UPTIME=$(uptime -p)
export UPTIME_SEC=$(awk '{print $1}' /proc/uptime)
echo "Uptime: $UPTIME"
echo "Uptime_sec: $UPTIME_SEC"

# Print the interface names, IP addresses and Gateway
export INTERFACE_NAME=$(ip -4 a)
export GATEWAY=$(ip route | grep default | awk '{print $3}')
echo "$INTERFACE_NAME" | grep -E '^[0-9]+:| inet '  |
awk '{if ($1 ~ /^[0-9]+:/) { sub(":", "", $2); print "Interface:", $2 }  else print "IP:", $2}'

echo "Gateway: $GATEWAY"

# Get RAM info
export RAM_TOTAL=$(free -b | awk '/Mem/{printf "%.2fGb\n", $2/1024/1024/1024}')
export RAM_USED=$(free -b | awk '/Mem/{printf "%.2fGb\n", $3/1024/1024/1024}')
export RAM_FREE=$(free -b | awk '/Mem/{printf "%.2fGb\n", $4/1024/1024/1024}')
echo "RAM_TOTAL: $RAM_TOTAL"
echo "RAM_USED: $RAM_USED"
echo "RAM_FREE: $RAM_FREE"

# Get Root Partition Information
export SPACE_ROOT=$(df -B1 / | awk 'NR==2 {printf "%.2fGb\n", $2/1024/1024/1024}')
export SPACE_ROOT_USED=$(df -B1 / | awk 'NR==2 {printf "%.2fGb\n", $3/1024/1024/1024}')
export SPACE_ROOT_FREE=$(df -B1 / | awk 'NR==2 {printf "%.2fGb\n", $4/1024/1024/1024}')
echo "SPACE_ROOT: $SPACE_ROOT"
echo "SPACE_ROOT_USED: $SPACE_ROOT_USED"
echo "SPACE_ROOT_FREE: $SPACE_ROOT_FREE"

chmod +x save_to_file.sh    
bash save_to_file.sh 
