#include <stdio.h>
#include "s21_string.h"
#include <string.h>

int main(void){
    char *s = "string";
    char dest[256]={0};
    
    s21_memcpy(dest,s,3);

    printf("%s",dest);

    return 0;
}

