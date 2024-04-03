#!/bin/bash

if [ $# != 0 ]; then
    echo "Don't provide any parameters, please!"
else
    source color.conf
    export color1=$column1_font_color
    export color2=$column1_background
    export color3=$column2_font_color
    export color4=$column2_background

    flag=0

    for i in $color1 $color2 $color3 $color4 ; do
            if [[ $i < 1 || $i > 6 ]]; then
                echo "Enter numbers from 1 to 6. Please try again"
                flag=1
                break
            fi
    done

    if [[ -z $color1 && -z $color2 && -z $color3 && -z $color4 ]]; then
        flag=1
        ./color.sh
    fi

    if [ $flag -eq 0 ]; then
        if [[ $color1 -eq $color2 ]] || [[ $color3 -eq $color4 ]]; then
           echo "The font and background colours of one column must not match. Please try again "
        else
            ./color.sh
        fi        
    fi
fi        