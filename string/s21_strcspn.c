#include "s21_string.h"

// calculates a length of the segment contains only not match to the str2
// characters

s21_size_t s21_strcspn(const char *s, const char *reject) {
  s21_size_t count = 0;
  int match = 0;
  int len_r = s21_strlen(reject);
  int len_s = s21_strlen(s);

  for (int i = 0; i < len_s; i++) {
    for (int j = 0; j < len_r; j++) {
      if (reject[j] == s[i]) {
        match++;
      }
    }

    if (match) {
      break;
    } else {
      count++;
    }
  }
  return count;
}