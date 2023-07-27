#include "s21_string.h"

//returns a pointer to the last apperance of the symbol

char *s21_strrchr(const char *str, int c){
  const char* ptr = str;
  int flag = 0;

  while (*str) {
    str++;
  }
  while (str >= ptr) {
    if (*str == (char)c) {
      flag = 1;
      break;
    }
    str--;
  }
  return flag ? (char*)str : NULL;
}
