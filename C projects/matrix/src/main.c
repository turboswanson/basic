#include <stdio.h>
#include <stdlib.h>

#include "s21_matrix.h"

int main(void) {
  matrix_t m;
  m.rows = 4;
  m.columns = 4;
  m.matrix = (double **)calloc(4, sizeof(double *));

  s21_remove_matrix(&m);

  return 0;
}