#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error = OK;

  if (s21_is_matrix_ok(A)) {
    error = s21_create_matrix(A->columns, A->rows, result);

    if (!error) {
      for (int i = 0; i < A->columns; i++) {
        for (int j = 0; j < A->rows; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }

  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}