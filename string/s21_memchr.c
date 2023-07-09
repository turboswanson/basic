#include "s21_string.h"

char *s21_memchr(char *string,int c,size_t n){
    for(size_t i = 0; i < n;i++){
        if(string[0] == c){
            
            return string;
        }
        string++;
    }
    return NULL;
}

