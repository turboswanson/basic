#include "s21_string.h"

char *s21_strstr(const char *hay, const char *needle){
    char *res = (char *)hay;
    char *s = (char *)needle;
    int count = 0;
    int x = 0;

    while(*hay){
        if(*hay == *needle){
            while(*hay == *needle){
                hay++;
                needle++;
                count++;
            }
            break;    
        }
        x++;
        hay++;
    }

    return (count == s21_strlen(s)) ? (char *)(res+x):NULL;
}