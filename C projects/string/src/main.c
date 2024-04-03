#include <stdio.h>

#include "s21_string.h"

void display(char *format, ...);

int main(void) {
  char buf[1024] = {'\0'};

  int r2 = s21_sprintf(buf, "%*d", 5, -76);  // 04d,77

  printf("%s", buf);

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
