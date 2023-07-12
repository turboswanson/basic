#include <stdio.h>
#include "s21_string.h"

int main(void){
    char *s = "Hello World";
    char *m = s21_memchr(s,'e',4);
    printf("%s",m);
    return 0;

}