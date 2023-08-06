#ifndef S21_STRING_H
#define S21_STRING_H


#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1,const void *str2,size_t n);
void *s21_memcpy(void *dest,const void *src,size_t n);
void *s21_memset(void *str, int c, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strncpy(char *dest, const char *src, size_t n);
size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *buf,const char *format,...);


char *s21_strcat(char *dest, const char *src);
int s21_strcmp(const char *str1,const char *s2);
char *s21_strcpy(char *dest, const char *src);
size_t s21_strspn(const char *str1,const char *str2);

//sprintf

typedef struct flags{
    int space;
    int minus;
    int plus;
    int dot;
    int num;
}flags;

typedef struct specs{
    int c;
    int d;
    int i;
    int f;
    int s;
    int u;
}specs;

int check_flag(const char *format,flags *f);
int parser(const char *format,specs *s);
char *s21_itoa(int num, char *str,int base);
void reverse(char str[], int lenght);
void processing_d(const char *format, char *str,specs *s, va_list factor);
void processing_f(const char *format,char *str,specs *s, va_list factor);
char *ftochar(char *str,double f);

#endif

