#include "s21_string.h"

// returns a pointer to a first apperance of a character in N elements of a
// string or s21_NULL

void *s21_memchr(const void *str, int c, s21_size_t n) {
  const unsigned char *s = (const unsigned char *)str;

  for (s21_size_t i = 0; i < n; i++) {
    if (*s == (unsigned char)c) {
      return (void *)s;
    }
    s++;
  }

  return NULL;
}
