#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
char *str = "test1/test2/test3/test4";
char *res = s21_strtok(str,"!");
printf("%s",res);
return 0;
}


