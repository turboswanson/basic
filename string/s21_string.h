#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <float.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define s21_size_t unsigned long
#define s21_NULL (void *)0
#define BUFF_SIZE 512

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strncat(char *dest, const char *src, s21_size_t n);
char *s21_strchr(const char *str, int c);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strcspn(const char *str1, const char *str2);
char *s21_strerror(int errnum);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strrchr(const char *str, int c);
char *s21_strstr(const char *str1, const char *str2);
char *s21_strtok(char *str, const char *delim);
int s21_sprintf(char *buf, const char *format, ...);

char *s21_strcat(char *dest, const char *src);
int s21_strcmp(const char *str1, const char *s2);
char *s21_strcpy(char *dest, const char *src);
s21_size_t s21_strspn(const char *str1, const char *str2);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_atoi(const char *str);
void *s21_memmove(void *dst, const void *src, s21_size_t n);
// Выполняет безопасное копирование блока памяти.
// Она перемещает данные из области, заданной указателем src, в область,
// заданную указателем dst, размером n байт. Возвращает указатель на dst.

// Sprintf 2
// Определение структуры flags для хранения различных флагов форматирования
typedef struct {
  bool minus;
  bool plus;
  bool space;
  bool zero;
  bool hash;
  int accuracy;
  int is_accuracy_set;
  int width;
  char length;
  char specifier;
} flags;

#define SIZE (512)

int example(char *buf, const char *format, ...);

typedef struct {
  int minus;
  int plus;
  int space;
  int zero;
  int hash;
  int width;
  char lenght;
  int accuracy_flag;
  int accuracy;
  char spec;
} options;

#endif
