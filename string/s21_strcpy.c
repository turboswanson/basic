#include "s21_string.h"

char *s21_strcpy(char *dest, const char *src){
    char *res = (char *)dest;
    int len = 0;

    while(*src){
        *res = *src;
        res++;
        src++;
        len++;
    }
    dest[len] =  '\0';

    return dest;
}

