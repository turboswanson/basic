#!/bin/bash

# первый параметр - номер дня
# второй параметр - количество заданий

function main {
  for i in $(seq -f "%02g" 0 $2); do
    mkdir "ex${i}"
    if [[ ${#1} -lt 2 ]]; then
      DAY="0$1"
    else
      DAY=$1
    fi
    touch "ex${i}/day${DAY}_ex${i}.sql"
  done
}

main "$@"
