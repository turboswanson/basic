/*

Specifiers
c - character    s21_sprintf(buf,"string%c",'$');
d - signed decimal integer  s21_sprintf(buf,"string%d",46);
i - signed decimal integer(may be decimal, octal, hexadecimal)
s21_sprintf(buf,"string%i",65); f - decimal floating point
s21_sprintf(buf,"string%f",46.5); s - string of characters
s21_sprintf(buf,"string%s","another string"); u - unsigned decimal integer % -
character %

Flags
- left-justify   s21_sprintf(buf,"string%-d",46);     COMPARE OUTPUT to see the
difference!!!!!! sprintf(str,"string1 %5d",45)   sprintf(str,"string1 %-5d",45)

+ forces to precede the result with a plus or minus
s21_sprintf(buf,"string%+d",46); space if no sign is going to be written
s21_sprintf(buf,"string % d",46);

Width
 minimum number of characters to be written  s21_sprintf(buf,"string%5d",46)
----->  string   46

Precision   s21_sprintf(buf,"string%.5d",46); ------> string00046
s21_sprintf(buf,"string%3.3f",46.565646);    -----> srting46.566
%.44.1 -- > 44  %.3s ("format")  - --- > "for"
Length
h  s21_sprintf(buf,"string%hd",46);
l s21_sprintf(buf,"string%ld",46);  long int (ld) = -2 147 483 648 to  2 147 483
648



example s21_sprintf(buf,"string1 %.5dstring2 %5.5f string3
%c",45,3.14567843,'$');  ----> string1 00045 string2 3.14568 string3 $
*/

#include "s21_string.h"

int s21_sprintf(char *buf, const char *format, ...) {
  flags f = {0};
  specs s = {0};

  int precision_flag = 0;

  va_list factor;
  va_start(factor, format);  // va_start(va_list param, last explicit param)

  while (*format) {
    if (*format != '%') {
      char c[2] = {'\0'};
      c[0] = *format;
      s21_strcat(buf, c);
      format++;
    } else {
      format++;  // got a '%' and move for one step to see what is the next one

      if (*format == '%') {
        s21_strcat(buf, "%");
        format++;
        continue;
      }

      char str_num[1024] = {'\0'};   // the string for width char
      char str_prec[1024] = {'\0'};  // the string for precision char

      while (check_flag(
          format,
          &f)) {  // find out if there is a space, '-', '+' or a number after %
        if (f.space) {  // if s21_sprintf(buf,"string %   5d",45)
          s21_strcat(buf, " ");
          format++;
          continue;
        }

        if (f.num) {             // PUT THE WIDTH IN STR_NUM TO MAKE IT INT!
          if (precision_flag) {  // if number that appears is a precision
            char b[2] = {'\0'};
            b[0] = *format;
            s21_strcat(str_prec, b);
            f.num = 0;
          } else {  // if number that appears is a width
            char a[2] = {'\0'};
            a[0] = *format;
            s21_strcat(str_num, a);
            f.num = 0;
          }
        }

        if (f.dot) {
          precision_flag = 1;
        }

        format++;
      }

      f.width = atoi(str_num);
      f.precision = atoi(str_prec);

      if (*format == 'l') {
        s.l = 1;
        format++;
      }

      if (*format == 'h') {
        s.h = 1;
        format++;
      }

      parser(format, &s);  // find out what specifier is

      char str_tmp[1024] = {'\0'};  // create a string for va_arg

      if (s.d || s.i) {
        processing_d(format, f, &s, str_tmp, factor);

        width_processing(str_tmp, buf, f);

        s.d = 0;
        s.i = 0;
      }

      if (s.u) {
        processing_u(format, f, &s, str_tmp, factor);

        width_processing(str_tmp, buf, f);

        s.u = 0;
      }

      if (s.f) {
        processing_f(buf, str_tmp, f, factor);

        width_processing(str_tmp, buf, f);

        s.f = 0;
      }

      if (s.c) {
        processing_c(format, str_tmp, &s, factor);
        width_processing(str_tmp, buf, f);
        s.c = 0;
      }

      if (s.s) {
        processing_s(format, str_tmp, &s, f, factor);
        width_processing(str_tmp, buf, f);
        s.s = 0;
      }

      format++;
    }
    f.dot = 0;
    f.minus = 0;
    f.plus = 0;
    precision_flag = 0;
  }

  va_end(factor);
  return s21_strlen(buf);
}

int check_flag(const char *format, flags *f) {
  int flag = 0;
  switch (*format) {
    case ' ':
      f->space = 1;
      flag = 1;
      break;
    case '-':
      f->minus = 1;
      flag = 1;
      break;
    case '+':
      f->plus = 1;
      flag = 1;
      break;
    case '.':
      f->dot = 1;
      flag = 1;
      break;
  }

  if (isdigit(*format)) {
    f->num = 1;
    flag = 1;
  }

  return flag;
}

void parser(const char *format, specs *s) {
  switch (*format) {
    case 'c':
      s->c = 1;
      break;
    case 'd':
      s->d = 1;
      break;
    case 'i':
      s->i = 1;
      break;
    case 'f':
      s->f = 1;
      break;
    case 's':
      s->s = 1;
      break;
    case 'u':
      s->u = 1;
      break;
  }
}

void s21_reverse(char str[], int lenght) {
  int start = 0;
  int end = lenght - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

void processing_d(const char *format, flags f, specs *spec, char *str,
                  va_list factor) {
  long int d = 0;

  if (spec->l) {
    d = va_arg(factor, long);
  }

  if (spec->h) {
    d = (short)va_arg(factor, int);
  }

  if (!spec->l && !spec->h) {
    d = va_arg(factor, int);
  }

  spec->l = 0;
  spec->h = 0;

  char s[1024] = {'\0'};

  if (d < 0) {
    s21_strcat(str, "-");
    d = d * (-1);
  }

  s21_itoa(d, s, 10);

  if (d >= 0 && f.plus) {
    s21_strcat(str, "+");
  }

  if (d) {
    if (s21_strlen(s) < f.precision) {
      for (int i = 0; i < (f.precision - s21_strlen(s)); i++) {
        s21_strcat(str, "0");
      }
    }

    s21_strcat(str, s);
  }
}

void processing_u(const char *format, flags f, specs *spec, char *str,
                  va_list factor) {
  unsigned long d = 0;

  if (spec->l) {
    d = va_arg(factor, unsigned long);
  }

  if (spec->h) {
    d = (short)va_arg(factor, unsigned int);
  }

  if (!spec->l && !spec->h) {
    d = va_arg(factor, unsigned int);
  }

  spec->l = 0;
  spec->h = 0;

  char s[1024] = {'\0'};

  if (d < 0) {
    s21_strcat(str, "-");
    d = d * (-1);
  }

  s21_itoa(d, s, 10);

  if (d >= 0 && f.plus) {
    s21_strcat(str, "+");
  }

  if (d) {
    if (s21_strlen(s) < f.precision) {
      for (int i = 0; i < (f.precision - s21_strlen(s)); i++) {
        s21_strcat(str, "0");
      }
    }

    s21_strcat(str, s);
  }
}

void processing_f(char *buf, char *str, flags f, va_list factor) {
  double num = 0;
  num = va_arg(factor, double);

  int flag_minus = 0;

  if (num < 0) {
    f.flag_minus = 1;
    num = -num;
  }

  if (num >= 0 && f.plus) {
    s21_strcat(str, "+");
  }

  if (f.flag_minus) s21_strcat(buf, "-");

  char str_char[1024] = {'\0'};

  ftochar(str_char, num, f);
  s21_strcat(str, str_char);

  f.flag_minus = 0;
}

char *ftochar(char *str, double num, flags f) {
  int flag = 0;
  int flag_s21_NULL = 0;  // for %.0f

  long long int x = (long long int)num;
  num = num - x;
  // y = modf(num, &x); // num = 0.9 // 0.01 // 0.0009 // num = 0.7853

  if (num * 10 >= 5 && (f.precision == 0 && f.dot)) {
    x = x + 1;
    flag_s21_NULL = 1;
  }

  if ((f.precision == 0 && f.dot)) {
    flag_s21_NULL = 1;
  }

  s21_itoa(x, str, 10);

  int accuracy = 0;
  s21_size_t dot = s21_strlen(str);

  str[dot] = '.';

  if (f.precision == 0) {
    accuracy = 6;
  } else {
    accuracy = f.precision;
  }

  for (s21_size_t i = 1; i != accuracy + 2; i++) {
    num *= 10;
    x = (int)num;
    str[dot + i] = x + 48;
    num -= x;
  }

  round_float(str, &flag);

  if (flag_s21_NULL) {
    str[dot] = '\0';
  }
}

void round_float(char *str, int *flag) {  // 0.005
  if (str[s21_strlen(str) - 1] > '4') {   // the last one
    for (int i = (int)s21_strlen(str) - 2; i >= 0;
         i--) {  // the one before last
      if (str[i] == '.') {
        i--;
      }

      if (str[i] != '9') {
        str[i] = str[i] + 1;
        break;
      } else if (i != 0) {
        str[i] = '0';
      } else if (str[i] != '0') {
        *flag = 1;

        for (i = s21_strlen(str); i > 0; i--) {
          str[i] = str[i - 1];
        }

        str[1] = '0';
        str[0] = '1';
        break;
      } else {
        str[i] = '1';
      }
    }
  }
  str[s21_strlen(str) - 1] = '\0';
}

void processing_c(const char *format, char *str, specs *spec, va_list factor) {
  wchar_t c;

  if (spec->l) {
    c = va_arg(factor, wchar_t);
  } else {
    c = (char)va_arg(factor, int);
  }

  spec->l = 0;

  char str_c[2] = {'\0'};
  str_c[0] = c;
  s21_strcat(str, str_c);
}

void processing_s(const char *format, char *str, specs *spec, flags f,
                  va_list factor) {
  char buf[1024] = {'\0'};
  wchar_t *tmp = s21_NULL;
  char *res = s21_NULL;

  int wflag = 0;

  if (spec->l) {
    tmp = va_arg(factor, wchar_t *);
    wchar_to_string(buf, tmp);
    wflag = 1;
  } else {
    res = (char *)va_arg(factor, char *);
  }

  spec->l = 0;

  if (wflag) {
    if (f.precision) {
      for (int i = 0; i < f.precision && buf[i]; i++) {
        str[i] = buf[i];
      }
    } else if (f.precision == 0 && f.dot) {
      str[0] = '\0';
    } else {
      s21_strcat(str, buf);
    }
  } else {
    if (f.precision) {
      for (int i = 0; i < f.precision && *res; i++) {
        str[i] = *res++;
      }
    } else if (f.precision == 0 && f.dot) {
      str[0] = '\0';
    } else {
      s21_strcat(str, res);
    }
  }
}

void width_processing(char *str_tmp, char *buf, flags f) {
  if ((f.width - ((int)s21_strlen(str_tmp))) > 0) {
    if (!f.minus) {
      for (int i = 0; i < (f.width - s21_strlen(str_tmp)); i++) {
        s21_strcat(buf, " ");
      }

      s21_strcat(buf, str_tmp);
    }

    if (f.minus) {
      s21_strcat(buf, str_tmp);

      for (int i = 0; i < (f.width - s21_strlen(str_tmp)); i++) {
        s21_strcat(buf, " ");
      }
    }
  } else {
    s21_strcat(buf, str_tmp);
  }
}

void wchar_to_string(char *dest, wchar_t *src) {
  int i = 0;

  while (src[i]) {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
}