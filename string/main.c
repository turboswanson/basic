#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
char *str = "Hello world\0";
char *res = s21_strrchr(str,'\0');
printf("%s",res);
return 0;
}


