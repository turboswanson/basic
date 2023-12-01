#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;

  if (s21_is_matrix_ok(A) && s21_is_matrix_ok(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      error = s21_create_matrix(A->rows, A->columns, result);
      if (!error) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      }
    } else {
      error = CALC_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;

  if (s21_is_matrix_ok(A) && s21_is_matrix_ok(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      error = s21_create_matrix(A->rows, A->columns, result);

      if (!error) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    } else {
      error = CALC_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error = OK;

  if (s21_is_matrix_ok(A)) {
    error = s21_create_matrix(A->rows, A->columns, result);

    if (!error) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error = OK;

  if (s21_is_matrix_ok(A) && s21_is_matrix_ok(B)) {
    if (A->columns == B->rows) {
      error = s21_create_matrix(A->rows, B->columns, result);

      if (!error) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < B->columns; j++) {
            for (int k = 0; k < B->rows; k++) {
              result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
            }
          }
        }
      }
    } else {
      error = CALC_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}

int s21_determinant(matrix_t *A, double *result) {
  int error = OK;

  if (result != NULL) {
    *result = 0;

    if (s21_is_matrix_ok(A)) {
      if (A->rows == A->columns) {
        *result = s21_get_determinant(A);
      } else {
        error = CALC_ERROR;
      }
    } else {
      error = INCORRECT_MATRIX;
    }
  } else {
    error = CALC_ERROR;
  }

  return error;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error = OK;

  if (s21_is_matrix_ok(A)) {
    if (A->rows == A->columns) {
      error = s21_create_matrix(A->rows, A->columns, result);

      if (!error) {
        if (A->rows == 1) {  // for 1x1 matrix
          result->matrix[0][0] = A->matrix[0][0];
        } else {
          matrix_t tmp = {0};

          error = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);

          if (!error) {
            for (int i = 0; i < result->rows; i++) {
              for (int j = 0; j < result->columns; j++) {
                s21_get_mx(i, j, A, &tmp);
                result->matrix[i][j] =
                    s21_get_determinant(&tmp);  // get a matrix of minors
              }
            }

            for (int i = 0; i < result->rows; i++) {
              for (int j = 0; j < result->columns; j++) {
                result->matrix[i][j] =
                    pow(-1, i + j) *
                    result->matrix[i][j];  // get a algebraic complements matrix
              }
            }
          } else {
            error = CALC_ERROR;
          }

          s21_remove_matrix(&tmp);
        }
      }

    } else {
      error = CALC_ERROR;
    }
  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error = 0;

  if (s21_is_matrix_ok(A)) {
    double determinant = 0;
    error = s21_determinant(A, &determinant);
    // printf("\n D = %lf\n",determinant);
    if (!error) {
      if (determinant != 0) {
        matrix_t tmp_calc = {0};
        s21_calc_complements(A, &tmp_calc);
        matrix_t tmp_trans = {0};
        s21_transpose(&tmp_calc, &tmp_trans);
        error = s21_mult_number(&tmp_trans, 1 / determinant, result);

        s21_remove_matrix(&tmp_calc);
        s21_remove_matrix(&tmp_trans);
      } else {
        error = CALC_ERROR;
      }
    }

  } else {
    error = INCORRECT_MATRIX;
  }

  return error;
}
