#!/bin/bash

if [ $# != 1 ];then 
    echo "Provide one parameter, please!"
elif [[ ! -d $1 ]]; then
    echo "Provide valid directory, please!"
else
    path=$1

    if [[ ${path: -1} != '/' ]]; then
        path="$path/"
    fi

    start=$(date +%s)

    total=$(find "$path" -type d | wc | awk '{print $1}')
    echo "Total number of folders (including all nested ones) = $total"

    echo "TOP 5 Folders of maximum size arranged in descending order (path and size):"
    top_folders=$(du -h $path | sort -rh | awk 'NR>1 {print $2 ", " $1}' | head -n 5)
    echo "${top_folders}"

    total_number_of_files=$(find "$path" -type f | wc | awk '{print $1}')
    echo "Total number of files = $total_number_of_files"

    conf_files=$(find "$path" -type f -name \*.conf | wc | awk '{print $1}')
    text_files=$(find "$path" -type f -name \*.txt | wc | awk '{print $1}')
    exec_files=$(find "$path" -type f -executable | wc | awk '{print $1}')
    log_files=$(find "$path" -type f -name \*.log | wc | awk '{print $1}')
    archive_files=$(find "$path" -type f -name \*.zip -o -name \*.tar -o -name \*.gz | wc | awk '{print $1}')
    symbols=$(find "$path" -type l | wc | awk '{print $1}')

    echo "Number of:"
    echo " Configuration files (with the .conf extension) = $conf_files"
    echo " Text files = $text_files"
    echo " Executable files = $exec_files"
    echo " Log files (with the extension .log) = $log_files"
    echo " Archive files = $archive_files"
    echo " Symbolic links = $symbols"

    top_files=$(find "$path" -type f -printf '%s %p\n'| sort -rh | head -n 10)
    echo "TOP 10 files of maximum size arranged in descending order (path, size and type):"

    while read -r line; do
        path_f=$(echo "$line" | awk '{print $2}')
        size=$(du -h $path_f | awk '{print $1}')
        extension=$(echo "$path_f" | awk -F . '{if (NF>1) {print $NF}}')  # -F . makes ignore '.' as a separator NF - number of fields
        echo " $path_f, $size, $extension"
    done <<< "$top_files"

    ex_files=$(find $path -type f -executable -printf '%s %p\n' | sort -rh | head -n 10)
    echo "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file):"  
    
    while read -r line; do
        path_ex=$(echo "$line" | awk '{print $2}')
        size=$(du -h $path_ex | awk '{print $1}')
        hash=$(md5sum $path_ex | awk '{print $1}')
        echo "$path_ex, $size, $hash"
    done <<< "$ex_files"
    
    end=$(date +%s.%N)
    time=$(echo "$end - $start" | bc)
    echo "Script execution time (in seconds) = $time"

fi    
    