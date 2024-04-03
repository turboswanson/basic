#!/bin/bash

parameter=$1

if [ "$#" -eq 0 ]; then
    echo "Are you kidding me? That's not how it works you should provide something"
elif  [[ "$parameter" =~ ^[-]?[0-9]+(\.[0-9]+)?$ ]]; then
    echo "Invalid input. Please enter a text value"
else
    echo "The parameter value is : $parameter"
fi        

# =~ regex-matching operator
# ^ is a start of regex;  $ is the end of it
# [-] for negative numbers ? means optional
# + means more than one digit
# \. allows a dot to follow the digit and ? makes it optional