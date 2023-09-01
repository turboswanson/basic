#ifndef S21_STRING_H
#define S21_STRING_H

#include <ctype.h>
#include <math.h>
#include <stdarg.h>
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

// sprintf

typedef struct flags {
  int space;
  int minus;
  int plus;
  int dot;
  int num;
  int width;
  int precision;
  int flag_minus;
} flags;

typedef struct specs {
  int c;
  int d;
  int i;
  int f;
  int s;
  int u;
  int l;
  int h;
} specs;

int check_flag(const char *format, flags *f);
void parser(const char *format, specs *s);
char *s21_itoa(long long int num, char *str, int base);
void s21_reverse(char str[], int lenght);
void processing_d(const char *format, flags f, specs *spec, char *str,
                  va_list factor);
void processing_u(const char *format, flags f, specs *spec, char *str,
                  va_list factor);
void processing_f(char *buf, char *str, flags f, va_list factor);
char *ftochar(char *str, double num, flags f);
void processing_c(const char *format, char *str, specs *spec, va_list factor);
void processing_s(const char *format, char *str, specs *spec, flags f,
                  va_list factor);
void width_processing(char *str_tmp, char *buf, flags f);
void round_float(char *str, int *flag);
void wchar_to_string(char *dest, wchar_t *src);

// SScanf

#ifndef ULONG_MAX
#define ULONG_MAX ((unsigned long)(~0L)) /* 0xFFFFFFFF */
#endif

#ifndef LONG_MAX
#define LONG_MAX ((long)(ULONG_MAX >> 1)) /* 0x7FFFFFFF */
#endif

#ifndef LONG_MIN
#define LONG_MIN ((long)(~LONG_MAX)) /* 0x80000000 */
#endif

#define is_digit(ch) ((ch) >= '0' && (ch) <= '9')
#define is_digit_o2(ch) ((ch) >= '8' && (ch) <= '9')
#define is_digit_o(ch) ((ch) >= '0' && (ch) <= '7')

struct step {
  int strStep;
  int strLength;
  int formatStep;
  int countReturn;
};

struct arguments {
  short star;
  int width;
  char modifier;
  int flag;
  int flag_o;
};

int s21_sscanf(const char *str, const char *format, ...);
int s21_switchCase(va_list ap, struct arguments *Arguments, struct step *Step,
                   const char *str, const char *format);
int s21_specifier_c(va_list ap, const char *str, struct step *Step,
                    struct arguments *args);
int s21_specifier_s(va_list ap, const char *str, struct step *Step,
                    struct arguments *args);
int s21_specifier_i(va_list ap, const char *str, struct step *Step,
                    struct arguments *args);
int s21_specifier_f_e_E_g_G(va_list ap, const char *str, struct step *Step,
                            struct arguments *args);
int s21_specifier_percent(const char *str, struct step *Step,
                          struct arguments *args);
int s21_specifier_n(va_list ap, const char *str, struct step *Step,
                    struct arguments *args, const char *format);
int s21_Euler_search(const char *str, char **end, long double *num);
int s21_string_to_Ld(const char *str, char **end, long double *numbur,
                     struct arguments *args);
int s21_inf_nan(const char *str, int i, long double *num);
long long s21_strtol(const char *nptr, char **endptr, register int base);
int s21_is_space(char c);
int s21_is_digit(char c);

int s21_sscanf_atoi_d(const char *str, struct arguments *args, long *res,
                      struct step *Step);
int s21_specifier_d(va_list valist, const char *str, struct arguments *args,
                    struct step *Step);

double s21_pow(double x, int power);
int s21_specifier_u(va_list valist, const char *str, struct arguments *args,
                    struct step *Step);
int s21_specifier_o(va_list valist, const char *str, struct arguments *args,
                    struct step *Step);
void s21_specifier_result(va_list valist, struct arguments *args,
                          long int *result);
int s21_specifier_Xx(va_list valist, const char *str, struct arguments *args,
                     struct step *Step, int *end_func);
int s21_specifier_p(va_list valist, const char *str, struct arguments *args,
                    struct step *Step, int *end_func);
int s21_checkSymbols_XxP(const char *str, int *symbols_counter, long *decimal,
                         struct arguments *args, int *end_func, int *flagx);

#endif
