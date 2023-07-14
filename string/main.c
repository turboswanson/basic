#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
    char *s = "\0";
    char *m = memchr(s,'e',4);
    printf("%s",m);
    return 0;

}