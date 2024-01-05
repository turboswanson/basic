#include "calc.h"

int validation(char *str) {
  int error = 0;
  char buffer[1024] = {0};
  strncpy(buffer, str, sizeof(buffer) - 1);
  buffer[sizeof(buffer) - 1] = '\0';
  size_t len = strlen(buffer);
  if (len == 0) error++;
  for (size_t i = 0; i < len; i++) {
    if (buffer[i] == '(') error++;
    if (buffer[i] == ')') error--;
    if ((((buffer[i] == 's' && buffer[i + 1] != 'q' && buffer[i - 1] != 'o') ||
          buffer[i] == 'c' || (buffer[i] == 't' && buffer[i - 1] != 'r')) &&
         buffer[i - 1] != 'a') &&
        buffer[i + 3] != '(')
      error++;
    if ((buffer[i] == 'a' && buffer[i - 1] != 't') && buffer[i + 4] != '(')
      error++;
    if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' ||
        buffer[i] == '/' || buffer[i] == '^') {
      if (buffer[i + 1] == '+' || buffer[i + 1] == '-' ||
          buffer[i + 1] == '*' || buffer[i + 1] == '/' ||
          buffer[i + 1] == '^') {
        error++;
      }
    }
    if (buffer[i] == 'm' &&
        (!(isdigit(buffer[i - 1])) || !(isdigit(buffer[i + 3]))))
      error++;
    if (buffer[i] == '.' &&
        (!isdigit(buffer[i + 1]) || !isdigit(buffer[i - 1])))
      error++;
    if (buffer[i] == '(' && buffer[i + 1] == ')') error++;
    if (buffer[0] == '*' || buffer[0] == '/' || buffer[0] == '^' ||
        buffer[0] == 'm')
      error++;
    if (buffer[len - 1] == '+' || buffer[len - 1] == '-' ||
        buffer[len - 1] == '*' || buffer[len - 1] == '/' ||
        buffer[len - 1] == '^' || buffer[len - 1] == 'm')
      error++;
    if (buffer[i] == '/' && buffer[i + 1] == '0' &&
        (buffer[i + 2] == '+' || buffer[i + 2] == '*' || buffer[i + 2] == '/' ||
         buffer[i + 2] == '^'))
      error++;
    if (i == len - 2 && buffer[i] == '/' && buffer[i + 1] == '0') error++;
  }
  return error;
}