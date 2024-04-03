#!/bin/bash

if [ $# != 4 ];then
    echo "4 parameters should be provided. Please try again"
else
    export color1=$1 # value background
    export color2=$2 # font color
    export color3=$3 # background after '='
    export color4=$4 # font after '='
    flag=0

    for i in $color1 $color2 $color3 $color4 ; do
            if [[ $i < 1 || $i > 6 ]]; then
                echo "Enter numbers from 1 to 6. Please try again"
                flag=1
                break
            fi
    done

    if [ $flag -eq 0 ]; then
        if [ $color1 -eq $color2 ] || [ $color3 -eq $color4 ]; then
           echo "The font and background colours of one column must not match. Please try again "
        else
            ./color.sh
        fi        
    fi
fi    