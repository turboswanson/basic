#include "s21_string.h"
// copy n byte since *src to *dst making replacement

void *s21_memmove(void *dst, const void *src, s21_size_t n) {
  unsigned char buffer[n];
  for (s21_size_t i = 0; i < n; i++) {
    buffer[i] = *((unsigned char *)(src) + i);
  }

  for (s21_size_t i = 0; i < n; i++) {
    *((unsigned char *)(dst) + i) = buffer[i];
  }
  return dst;
}