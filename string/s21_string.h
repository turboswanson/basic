#ifndef S21_STRING_H
#define S21_STRING_H


#include <stdio.h>

void *s21_memchr(const void *str, int c, size_t n);
int s21_memcmp(const void *str1,const void *str2,size_t n);
void *s21_memcpy(void *dest,const void *src,size_t n);
void *s21_memset(void *str, int c, size_t n);
size_t s21_strlen(const char *str);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, size_t n);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1,const char *s2);
int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, size_t n);


#endif