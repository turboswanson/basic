#include "s21_string.h"

int s21_strcmp(const char *str1,const char *str2){
    char *s1 = (char *)str1;
    char *s2 = (char *)str2;

    while(*s1 && (*s1 == *s2)){
        s1++;
        s2++;
    }

    return *s1-*s2;

}