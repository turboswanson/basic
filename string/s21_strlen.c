#include "s21_string.h"

int s21_strlen(const void *str){
    const char *s = (const char *)str;
    int len = 0;
    while(*s){
        len++;
        s++;
    }

    return len;
}