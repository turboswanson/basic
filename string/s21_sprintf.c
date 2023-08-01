#include "s21_string.h"

int s21_sprintf(char *buf,const char *format,...){
    buf[0] = '\0';
    va_list arg_ptr;
    va_start(arg_ptr,format);

    while(*format){
        if(*format != '%'){
            //считываем символ
            format++;
        }else if

    }
}
