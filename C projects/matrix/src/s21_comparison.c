#include "s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error = SUCCESS;

  if (!s21_is_matrix_ok(A) || !s21_is_matrix_ok(B)) {
    error = FAILURE;
  } else {
    if (A->rows == B->rows && A->columns == B->columns) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (round(A->matrix[i][j] * pow(10, 7)) !=
              round(B->matrix[i][j] * pow(10, 7))) {
            error = FAILURE;
            // printf("%lf - %lf\n",A->matrix[i][j],B->matrix[i][j]);
            break;
          }
        }
      }
    } else {
      error = FAILURE;
    }
  }

  return error;
}
