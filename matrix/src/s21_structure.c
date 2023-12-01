#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  // result->matrix = 0;

  if (rows < 1 || columns < 1 || result == NULL) {
    error = INCORRECT_MATRIX;
  } else {
    result->matrix = (double **)calloc(
        rows, sizeof(double));  // allocate memory for rows pointers

    if (result->matrix != NULL) {  // check if allocated

      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(
            columns, sizeof(double));  // allocate memory for values

        if (result->matrix[i] == NULL) {  // check if wasn't allocated
          for (int j = 0; j < i; j++) {
            free(result->matrix[j]);
          }
          free(result->matrix);

          error = INCORRECT_MATRIX;
        }
      }
    }
  }

  if (!error) {
    result->rows = rows;
    result->columns = columns;
  }

  return error;
}

/*
   the first allocation

   [0]
   [1]
   [2]
   [n-1]

   the second one

   [0]  ->   [01]     [02]       [0m-1]
   [1]  ->   [11]     [12]       [1m-1]
   [2]  ->   [21]     [22]       [2m-1]
   [n-1]-> [(n-1)1] [(n-1)2)] [(n-1)(m-1)]


   */

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL) {
    if (A->matrix != NULL) {
      for (int i = 0; i < A->rows; i++) {
        if (A->matrix[i] != NULL) {
          free(A->matrix[i]);
        }
      }

      free(A->matrix);
    }

    A->matrix = NULL;
    A->rows = 0;
    A->columns = 0;
  }
}
