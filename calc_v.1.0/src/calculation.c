#include "calc.h"

void calculation(elements *output, int count, double *res) {
  double stack[512] = {0};

  for (int i = 0; i < count; i++) {
    if (output->type == 1) {
      stack[i] = output->value;
    }

    if (output->type == 2) {
      double value2 = stack[i - 1];
      double value1 = stack[i - 2];
      stack[i - 1] = stack[i - 2] = 0;

      char operation[5] = {0};
      strcpy(operation, output->operation);
      i = i - 2;
      count = count - 2;
      double res = execute(value1, value2, operation);
      stack[i] = res;
    }

    if (output->type == 3) {
      double value2 = stack[i - 1];
      double value1 = 0;
      stack[i - 1] = 0;
      char operation[5] = {0};
      strcpy(operation, output->operation);
      i--;
      count--;
      double res = execute(value1, value2, operation);
      stack[i] = res;
    }

    output++;
  }

  *res = stack[0];
}

double execute(double value1, double value2, char *operation) {
  double res = 0.0;
  if (operation[0] == '+') {
    res = value1 + value2;
  } else if (operation[0] == '-') {
    res = value1 - value2;
  } else if (operation[0] == '*') {
    res = value1 * value2;
  } else if (operation[0] == '/') {
    res = value1 / value2;
  } else if (operation[0] == '^') {
    res = pow(value1, value2);
  } else if (!strcmp(operation, "mod")) {
    res = fmod(value1, value2);
  } else if (!strcmp(operation, "sin")) {
    res = sin(value2);
  } else if (!strcmp(operation, "cos")) {
    res = cos(value2);
  } else if (!strcmp(operation, "tan")) {
    res = tan(value2);
  } else if (!strcmp(operation, "asin")) {
    res = asin(value2);
  } else if (!strcmp(operation, "acos")) {
    res = acos(value2);
  } else if (!strcmp(operation, "atan")) {
    res = atan(value2);
  } else if (!strcmp(operation, "sqrt")) {
    res = sqrt(value2);
  } else if (!strcmp(operation, "ln")) {
    res = log(value2);
  } else if (!strcmp(operation, "log")) {
    res = log10(value2);
  }

  return res;
}