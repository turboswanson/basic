#include "calc.h"

static int check_symbol(char c, char symbol) {
  int res = 0;

  if (c == symbol) {
    res = 1;
  }

  return res;
}

static int is_operator(char c) {
  int res = 0;

  if ((c == '+' || c == '-' || c == '*' || c == '/' || c == '^')) {
    res = 1;
  }

  return res;
}

int validation(char *str) {
  int error = 0;
  int count_dots = 0;
  int count_open_brackets = 0;
  int count_closing_brackets = 0;

  char buffer[256] = {0};
  strncpy(buffer, str, sizeof(buffer) - 1);
  buffer[sizeof(buffer) - 1] = '\0';

  size_t len = strlen(buffer);

  if (len == 0) error++;

  for (size_t i = 0; (!error && (i < len)); i++) {
    if (check_symbol(buffer[i], '(')) {
      count_open_brackets++;
    }

    if (check_symbol(buffer[i], '.') && count_dots) {
      error++;
    }

    if (check_symbol(buffer[i], '.') && !count_dots) {
      count_dots++;
    }

    if (is_operator(buffer[i])) {
      count_dots = 0;
    }

    if (check_symbol(buffer[i], ')')) {
      count_closing_brackets++;
    }

    if (is_operator(buffer[i]) && is_operator(buffer[i + 1])) {
      error++;
    }

    if (check_symbol(buffer[i], 'm') &&
        (!(isdigit(buffer[i - 1])) || !(isdigit(buffer[i + 3])))) {
      error++;
    }

    if (check_symbol(buffer[i], '.') &&
        (!isdigit(buffer[i + 1]) || !isdigit(buffer[i - 1]))) {
      error++;
    }

    if (check_symbol(buffer[i], '(') && check_symbol(buffer[i + 1], ')')) {
      error++;
    }

    if ((is_operator(buffer[0]) && !check_symbol(buffer[0], '+')) ||
        check_symbol(buffer[0], 'm')) {
      error++;
    }

    if (is_operator(buffer[len - 1]) || check_symbol(buffer[len - 1], 'd')) {
      error++;
    }

    if (check_symbol(buffer[i], '/') && check_symbol(buffer[i + 1], '0')) {
      if (is_operator(buffer[i + 2])) {
        error++;
      } else if (i + 1 == len - 1) {
        error++;
      }
    }

    if (isdigit(buffer[i]) && !isdigit(buffer[i + 1]) && (i != len - 1)) {
      if (!is_operator(buffer[i + 1]) && !check_symbol(buffer[i + 1], ')') &&
          !check_symbol(buffer[i + 1], '.') &&
          !check_symbol(buffer[i + 1], 'm')) {
        error++;
      }
    }

    if (check_symbol(buffer[i], ')') && is_operator(buffer[i - 1])) {
      error++;
    }
  }

  if (!error && count_open_brackets != count_closing_brackets) {
    error++;
  }

  return error;
}

int x_validation(char *str) {
  int error = 0;
  size_t len = 0;

  int count_dots = 0;

  char buffer[256] = {0};
  strncpy(buffer, str, sizeof(buffer) - 1);
  buffer[sizeof(buffer) - 1] = '\0';

  len = strlen(buffer);

  for (size_t i = 0; len != 0 && !error && (i < len); i++) {
    if (i != 0 && is_operator(buffer[i])) {
      error++;
    }

    if (!isdigit(buffer[0]) && !check_symbol(buffer[0], '-') &&
        !check_symbol(buffer[0], '+')) {
      error++;
    }

    if (check_symbol(buffer[i], '.') && check_symbol(buffer[i + 1], '.')) {
      error++;
    }

    if (isalpha(buffer[i])) {
      error++;
    }

    if ((check_symbol(buffer[0], '-') || check_symbol(buffer[0], '+')) &&
        !isdigit(buffer[1])) {
      error++;
    }

    if (check_symbol(buffer[i], '(') || check_symbol(buffer[i], ')')) {
      error++;
    }

    if (check_symbol(buffer[i], '.') && count_dots) {
      error++;
    }

    if (check_symbol(buffer[i], '.') && !count_dots) {
      count_dots++;
    }
  }

  return error;
}