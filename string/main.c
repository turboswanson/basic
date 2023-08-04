#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){                 
char str[100] = {0};
printf("%d\n",s21_sprintf(str,"string1 %-.5d string2 %5.5f string3 %c",45,3.14567843,'$'));   // 
printf("%s",str);
return 0;
}


