#include <stdio.h>
#include "s21_string.h"
#include <string.h>
void shift(int *s);

int main(void){
   char *s1 = "This is a 1st string s21_memcmp test";
char *s2 = "This is a 2nd STRING s21_memcmp test";

printf("%d",memcmp(s1,s2,36));
    return 0;
}

