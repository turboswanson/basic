#include "s21_string.h"

// returns a difference between N elements of two strings

int s21_memcmp(const void *str1, const void *str2,size_t n){
    size_t i = 0;
    const char *s1 = (const char*)str1;
    const char *s2 = (const char*)str2;

    while(*s1 == *s2 && i < n){
        s1++;
        s2++;
        i++;
    }

    return *s1 - *s2;
}