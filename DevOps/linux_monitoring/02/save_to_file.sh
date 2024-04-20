#!/bin/bash

read -p "Do you want to save the information to a file? (Y/N):  " answer

if [ "$answer" == "Y" ] || [ "$answer" == "yes" ];then

currentTime=$(date '+%d_%m_%Y_%H_%M_%S')
fileName="$currentTime.status"

  echo "HOSTNAME: $HOSTNAME" >> $fileName
  echo "TIMEZONE: $TIMEZONE UTC $utc" >> $fileName
  echo "USER: $USER" >> $fileName
  echo "OS: $OS" >> $fileName
  echo "DATE: $DATE" >> $fileName
  echo "UPTIME: $UPTIME" >> $fileName
  echo "UPTIME_SEC: $UPTIME_SEC" >> $fileName
  echo "$INTERFACE_NAME" | grep -E '^[0-9]+:| inet '  |
  awk '{if ($1 ~ /^[0-9]+:/) { sub(":", "", $2); print "Interface:", $2 }  else print "IP:", $2}' >> $fileName
  echo "GATEWAY: $GATEWAY" >> $fileName
  echo "RAM_TOTAL: $RAM_TOTAL" >> $fileName
  echo "RAM_USED: $RAM_USED" >> $fileName
  echo "RAM_FREE: $RAM_FREE" >> $fileName
  echo "SPACE_ROOT: $SPACE_ROOT" >> $fileName
  echo "SPACE_ROOT_USED: $SPACE_ROOT_USED" >> $fileName
  echo "SPACE_ROOT_FREE: $SPACE_ROOT_FREE" >> $fileName
  echo "The information is saved to $fileName"
else
  echo "The information is not saved to a file."
fi

