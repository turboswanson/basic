#include "s21_string.h"

const char *parsing_flags(const char *format, options *f);
const char *width_processing(const char *format, options *f, va_list factor);
const char *accuracy_processing(const char *format, options *f, va_list factor);
const char *lenght_processing(const char *format, options *f);
void parsing_specs(char *buf_tmp, options f, va_list factor);
void d_proc(options f, char *buf_tmp, va_list factor);
void u_proc(options f, char *buf_tmp, va_list factor);
void o_proc(options f, char *buf_tmp, va_list factor);
void x_proc(options f, char *buf_tmp, va_list factor);
void char_proc(options f, char *buf_tmp, va_list factor);
void string_proc(options f, char *buf_tmp, va_list factor);
void f_proc(options f, char *buf_tmp, va_list factor);

void f_accuracy(char *buf_tmp, options f);
void f_flag(char *buf_tmp, options f);

void f_itoa(long long int num, char *str, int base);  // int to char
void reverse(char str[], int lenght);

void f_wchar(options f, char *buf_tmp, wchar_t wch);
void f_char(options f, char *buf_tmp, char c);

void f_wstr(options f, char *buf_tmp, wchar_t *wstr);
void f_str(options f, char *buf_tmp, char *str);

void ftostring(long double num, char *buf_tmp, options f);

int s21_sprintf(char *buf, const char *format, ...) {
  options f = {0};

  va_list factor;
  va_start(factor, format);

  char *start = buf;

  while (*format) {
    if (*format != '%') {
      *buf++ = *format++;  // copy char to a buf if it's not a '%'
      continue;
    } else {
      format++;                      // jump over '%'
      s21_memset(&f, 0, sizeof(f));  // reset f with 0
    }

    format = parsing_flags(
        format, &f);  // format moved through all of flags that was found
    format = width_processing(format, &f, factor);
    format = accuracy_processing(format, &f, factor);
    format = lenght_processing(format, &f);

    f.spec = *format;
    format++;

    char buf_tmp[BUFF_SIZE] = {'\0'};

    parsing_specs(buf_tmp, f, factor);

    for (int i = 0; buf_tmp[i]; i++, buf++) {
      *buf = buf_tmp[i];
    }
  }

  *buf = '\0';

   va_end(factor);

  return buf - start;
}

const char *parsing_flags(const char *format, options *f) {
  while (*format == '+' || *format == '-' || *format == '0' || *format == ' ' ||
         *format == ' ' || *format == '#') {
    switch (*format) {
      case '+':
        f->plus = 1;
        break;
      case '-':
        f->minus = 1;
        break;
      case '0':
        f->zero = 1;
        break;
      case ' ':
        f->space = 1;
        break;
      case '#':
        f->hash = 1;
        break;
    }
    format++;
  }

  return format;
}

const char *width_processing(const char *format, options *f, va_list factor) {
  if (*format == '*') {  // if %*d
    format++;
    f->width = va_arg(factor, int);
  } else if (isdigit(*format)) {  // %5d
    char tmp[BUFF_SIZE] = {'\0'};

    for (int i = 0; isdigit(*format); i++) {
      tmp[i] = *format;
      format++;
    }

    f->width = s21_atoi(tmp);  // '5' -> 5
  }

  return format;
}

const char *accuracy_processing(const char *format, options *f,
                                va_list factor) {
  if (*format == '.') {
    f->accuracy_flag = 1;
    format++;
  }

  if (f->accuracy_flag) {
    char tmp[BUFF_SIZE] = {'\0'};

    if (isdigit(*format)) {
      for (int i = 0; isdigit(*format); i++) {
        tmp[i] = *format;
        format++;
      }
    }

    f->accuracy = s21_atoi(tmp);
    // f->accuracy_flag = 0;
  }

  return format;
}

const char *lenght_processing(const char *format, options *f) {
  switch (*format) {
    case 'h':
      f->lenght = 'h';
      format++;
      break;
    case 'l':
      f->lenght = 'l';
      format++;
      break;
    case 'L':
      f->lenght = 'L';
      format++;
      break;
  }

  return format;
}

void parsing_specs(char *buf_tmp, options f, va_list factor) {
  if (f.spec == 'd' || f.spec == 'i') {
    d_proc(f, buf_tmp, factor);
  } else if (f.spec == 'u') {
    u_proc(f, buf_tmp, factor);
  } else if (f.spec == 'o') {
    o_proc(f, buf_tmp, factor);
  } else if (f.spec == 'x' || f.spec == 'X') {
    x_proc(f, buf_tmp, factor);
  } else if (f.spec == 'c') {
    char_proc(f, buf_tmp, factor);
  } else if (f.spec == 's') {
    string_proc(f, buf_tmp, factor);
  } else if (f.spec == '%') {
    buf_tmp[0] = '%';
  } else if (f.spec == 'f') {
    f_proc(f, buf_tmp, factor);
  }
}

void d_proc(options f, char *buf_tmp, va_list factor) {
  long int d = 0;

  if (f.lenght == 'l') {
    d = va_arg(factor, long);
  }

  if (f.lenght == 'h') {
    d = (short)va_arg(factor, int);
  }

  if (f.lenght != 'h' && f.lenght != 'l') {
    d = va_arg(factor, int);
  }

  f_itoa(d, buf_tmp, 10);
  f_accuracy(buf_tmp, f);
  f_flag(buf_tmp, f);
}

void f_itoa(long long int num, char *str, int base) {  // int to char
  int i = 0;
  int isneg = 0;

  if (num == 0) {
    str[i++] = '0';
    str[i] = '\0';
  }

  if (num < 0 && base == 10) {
    isneg = 1;
    num = -num;
  }

  while (num != 0) {
    int rem = num % base;
    str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
    num = num / base;
  }

  if (isneg) {
    str[i++] = '-';
  }

  str[i] = '\0';
  reverse(str, i);
}

void reverse(char str[], int lenght) {
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

void f_accuracy(char *buf_tmp, options f) {
  char str_tmp[BUFF_SIZE] = {'\0'};

  int sign = 0;
  int len = s21_strlen(buf_tmp);

  if (buf_tmp[0] == '-') {
    str_tmp[0] = '-';
    len--;
    sign = 1;
  }

  if (f.accuracy > len) {
    int i = 0;

    for (i = sign; i < f.accuracy - len + sign; i++) {  // %.4d 77 --> 0077
      str_tmp[i] = '0';
    }

    for (int j = sign; buf_tmp[j]; i++, j++) {
      str_tmp[i] = buf_tmp[j];  // 0077
    }

    s21_strcpy(buf_tmp, str_tmp);
  }

  if (f.accuracy_flag && f.accuracy == 0 && buf_tmp[0] == '0' &&
      (f.spec == 'd' || f.spec == 'i' || f.spec == 'o' || f.spec == 'x' ||
       f.spec == 'x' || f.spec == 'X')) {
    buf_tmp[0] = '\0';  //.d 0
  }
}

void f_flag(char *buf_tmp, options f) {
  char tmp[BUFF_SIZE + 1] = {'\0'};

  if (f.plus && f.spec != 'u') {  // + processing
    tmp[0] = buf_tmp[0] == '-' ? buf_tmp[0] : '+';
    s21_strcpy(tmp + 1, buf_tmp[0] == '-' ? buf_tmp + 1 : buf_tmp);
    s21_strcpy(buf_tmp, tmp);
  } else if (f.space && buf_tmp[0] != '-' && f.spec != 'u') {
    tmp[0] = ' ';
    s21_strcpy(tmp + 1, buf_tmp);
    s21_strcpy(buf_tmp, tmp);
  }

  if (f.width > (int)s21_strlen(buf_tmp)) {
    int index = f.width - s21_strlen(buf_tmp);

    if (!f.minus) {
      if (buf_tmp[0] == '-' && f.zero) {  // if %05d,-76 else 00-76
        tmp[0] = '-';
        s21_memset(tmp + 1, '0', index + 1);
        s21_strcpy(tmp + index + 1, buf_tmp + 1);
      } else {
        s21_memset(tmp, f.zero ? '0' : ' ', index);
        s21_strcpy(tmp + index, buf_tmp);
      }

    } else {
      s21_strcpy(tmp, buf_tmp);
      s21_memset(tmp + s21_strlen(tmp), ' ', index);
    }
    s21_strcpy(buf_tmp, tmp);
  }
}

void u_proc(options f, char *buf_tmp, va_list factor) {
  unsigned long u = 0;

  if (f.lenght == 'l') {
    u = va_arg(factor, unsigned long);
  }

  if (f.lenght == 'h') {
    u = (short)va_arg(factor, unsigned int);
  }

  if (f.lenght != 'h' && f.lenght != 'l') {
    u = va_arg(factor, unsigned int);
  }

  f_itoa(u, buf_tmp, 10);
  f_accuracy(buf_tmp, f);
  f_flag(buf_tmp, f);
}

void o_proc(options f, char *buf_tmp, va_list factor) {
  buf_tmp[0] = '0';
  f_itoa(va_arg(factor, int), buf_tmp + f.hash, 8);
  f_accuracy(buf_tmp, f);
  f_flag(buf_tmp, f);
}

void x_proc(options f, char *buf_tmp, va_list factor) {
  unsigned long h = va_arg(factor, unsigned long);

  switch (f.lenght) {
    case 0:
      h = (unsigned int)h;
      break;
    case 'h':
      h = (unsigned int)h;
      break;
  }

  f_itoa(h, buf_tmp, 16);

  f_accuracy(buf_tmp, f);

  if (f.hash) {
    int zero_flag = 1;

    for (int i = 0; buf_tmp[i]; i++) {
      if (buf_tmp[i] != '0') zero_flag = 0;
    }

    if (!zero_flag || f.spec == 'p') {
      s21_memmove(buf_tmp + 2, buf_tmp, s21_strlen(buf_tmp));
      // making a replacement of (s21_strlen(buf_tmp) bytes to buf_tmp + 2 from
      // buf_tmp if it was 12345 it'll be 1212345, and 12 will be replaced with
      // '0' and 'x'
      buf_tmp[0] = '0';
      buf_tmp[1] = 'x';
    }
  }

  f_flag(buf_tmp, f);
}

void char_proc(options f, char *buf_tmp, va_list factor) {
  if (f.lenght == 'l') {
    wchar_t wch = va_arg(factor, wchar_t);
    f_wchar(f, buf_tmp, wch);
  } else {
    char c = va_arg(factor, int);
    f_char(f, buf_tmp, c);
  }
}

void f_wchar(options f, char *buf_tmp, wchar_t wch) {
  if (!f.minus && f.width) {
    char tmp[BUFF_SIZE] = {'\0'};
    wcstombs(tmp, &wch, BUFF_SIZE);  // converts the first SIZE bytes of wchar
                                     // string to a equivalent and put it to tmp
    // size_t wchar(char *out,const wchar_t *in,size_t size) returns number of
    // processed bytes

    for (s21_size_t i = 0; i < f.width - s21_strlen(tmp); i++) buf_tmp[i] = ' ';

    s21_strcat(buf_tmp, tmp);

  } else if (f.width) {
    wcstombs(buf_tmp, &wch, BUFF_SIZE);

    for (int i = s21_strlen(buf_tmp); i < f.width; i++) buf_tmp[i] = ' ';
  } else {
    wcstombs(buf_tmp, &wch, BUFF_SIZE);
  }
}

void f_char(options f, char *buf_tmp, char c) {
  if (!f.minus && f.width) {
    for (int i = 0; i < f.width; i++) {
      buf_tmp[i] = ' ';
      if (i == f.width - 1) buf_tmp[i] = c;
    }
  } else if (f.width) {
    buf_tmp[0] = c;
    for (int i = 1; i < f.width; i++) buf_tmp[i] = ' ';
  } else {
    buf_tmp[0] = c;
  }
}

void string_proc(options f, char *buf_tmp, va_list factor) {
  if (f.lenght == 'l') {
    wchar_t *wstr = va_arg(factor, wchar_t *);
    f_wstr(f, buf_tmp, wstr);
  } else {
    char *str = va_arg(factor, char *);
    f_str(f, buf_tmp, str);
  }
}

void f_wstr(options f, char *buf_tmp, wchar_t *wstr) {
  char tmp[BUFF_SIZE] = {'\0'};
  char str[BUFF_SIZE] = {'\0'};

  wcstombs(str, wstr, BUFF_SIZE);

  s21_strcpy(tmp, str);

  if (f.accuracy_flag) tmp[f.accuracy] = '\0';

  int x = f.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);

  if (f.minus && x > 0) {
    s21_strcpy(buf_tmp, tmp);
    s21_memset(buf_tmp + len, ' ', x);
  } else if (x > 0) {
    s21_memset(buf_tmp, ' ', x);
    s21_strcpy(buf_tmp + x, tmp);
  } else {
    s21_strcpy(buf_tmp, tmp);
  }
}

void f_str(options f, char *buf_tmp, char *str) {
  char tmp[BUFF_SIZE] = {'\0'};

  s21_strcpy(tmp, str);

  if (f.accuracy_flag) tmp[f.accuracy] = '\0';

  int x = f.width - s21_strlen(tmp);
  int len = s21_strlen(tmp);

  if (f.minus && x > 0) {
    s21_strcpy(buf_tmp, tmp);
    s21_memset(buf_tmp + len, ' ', x);
  } else if (x > 0) {
    s21_memset(buf_tmp, ' ', x);
    s21_strcpy(buf_tmp + x, tmp);
  } else {
    s21_strcpy(buf_tmp, tmp);
  }
}

void f_proc(options f, char *buf_tmp, va_list factor) {
  long double num = 0;

  if (f.lenght == 'L') {
    num = va_arg(factor, long double);
  } else {
    num = va_arg(factor, double);
  }

  if (!f.accuracy_flag) {
    f.accuracy = 6;
  }

  ftostring(num, buf_tmp, f);
  f_flag(buf_tmp, f);
}

void ftostring(long double num, char *buf_tmp, options f) {
  int flag = 0;  // if num < 0
  int index = BUFF_SIZE - 2;

  char tmp[BUFF_SIZE] = {'\0'};

  if (num < 0) {
    num = -num;
    flag++;
  }

  long double l, r = modfl(num, &l);  // num = 3.14, l = 3.000000,r = 0.140000

  if (f.accuracy == 0) {  // %.f
    l = roundl(num);
    r = 0;
  }

  char rem[BUFF_SIZE] = {'\0'};

  for (int i = 0; i < f.accuracy; i++) {
    r = r * 10;

    rem[i] = (int)r + '0';
  }

  long long right = roundl(r), left = l;

  // MOVING FROM THE END

  if (!right) {
    for (int i = 0; i < f.accuracy; i++, index--) {
      tmp[index] = '0';  // 0000000
    }
  } else {
    for (size_t i = s21_strlen(rem); right || i > 0;
         right /= 10, index--, i--) {
      tmp[index] = (int)(right % 10 + 0.05) + '0';  // 345678
    }
  }

  if ((f.accuracy_flag && f.accuracy != 0) || (int)r ||
      (!f.accuracy_flag && num == 0) || s21_strlen(rem)) {
    tmp[index--] = '.';  // .00000 or .343434 here dot appears
  }

  if (!left) {
    tmp[index] = '0';  /// 0.35353
    index--;
  } else {
    for (; left; left /= 10, index--) {
      tmp[index] = (int)(left % 10) + '0';  // 3.14567
    }
  }

  for (int i = 0; tmp[index + 1]; index++, i++) {
    if (flag && i == 0) {
      buf_tmp[i] = '-';
      i++;
    }
    buf_tmp[i] = tmp[index + 1];
  }

  flag = 0;

}
