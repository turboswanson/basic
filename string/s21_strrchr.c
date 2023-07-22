#include "s21_string.h"

//returns a pointer to the last apperance of the symbol

char *s21_strrchr(const char *str, int c){
    char *res = (char *)str;

    size_t i = 0;
    int index = 0;
    int match = 0;

    for(;i < s21_strlen(res);i++){
        if(res[i] == c){
            index = i;
            match ++;
        }
    }

       

    return match ? (char *)(res + index) : NULL;
}
