#include <stdio.h>
#include <string.h>

#include "s21_string.h"

void display(char *format, ...);
void example(char *buf, const char *format, ...);

int main(void) {
  char *buf = s21_NULL;

  sprintf(buf,"%s","HUY!!!!!!");
  printf("%s",buf);
  return 0;
}

void display(char *format, ...) {
  int d;
  double f;
  unsigned char e;
  char *str = s21_NULL;
  va_list factor;

  va_start(factor, format);  // va_start(va_list param, last explicit param)

  for (char *c = format; *c; c++) {
    if (*c != '%') {
      printf("%c", *c);
      continue;
    }
    c++;
    switch (*c) {
      case 'd':
        d = va_arg(factor, int);  // type va_arg (va_lis param, type)
        printf("%d", d);
        break;
      case 'f':
        f = va_arg(factor, double);
        printf("%.2lf", f);
        break;
      case 'c':
        // it's necessary to use (unsigned char) because we can't use
        // va_arg(factor,char) (char will be promoted to int as it's shorter
        // than int,moreover float will be promoted as double)
        e = (unsigned char)va_arg(factor, int);
        printf("%c", e);
        break;
      case 's':
        str = va_arg(factor, char *);
        printf("%s", str);
        break;
      default:
        printf("%c", *c);
    }
  }
  va_end(factor);
}

void example(
    char *buf, const char *format,
    ...) {  // int count = example(buf,"%s",res); //example("$","%c",&x);
  va_list factor;

  va_start(factor, format);
  char *c = NULL;
  int *d = 0;
  char *str = NULL;

  int step = 0;

  while (*format) {
    if (*format == '%') {
      format++;
    }

    if (*format == 'c') {
      c = va_arg(factor, char *);

      *c = buf[step];
      step += 1;
    }

    if (*format == 'd') {
      d = va_arg(factor, int *);
    }

    if (*format == 's') {
      str = va_arg(factor, char *);

      int i = 0;

      for (i; buf[i] != 32; i++) {
        str[i] = buf[i];
      }

      buf = buf + i;
    }
    format++;
  }

  va_end(factor);
}