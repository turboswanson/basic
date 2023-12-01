#include "s21_matrix.h"

// void s21_print(matrix_t A){
//     for(int i = 0; i < A.rows;i++){
//         for(int j = 0; j < A.columns; j++){
//             printf("%lf ",A.matrix[i][j]);
//         }

//         printf("\n");
//     }
// }

// void s21_fill(matrix_t *A){

//     double num = 0;

//     for(int i = 0; i < A->rows; i++){
//         for(int j = 0; j < A->columns;j++){
//            A->matrix[i][j] = num++;
//         }
//     }
// }

int s21_is_matrix_ok(matrix_t *A) {
  int res = 0;

  if (A != NULL) {
    if (A->rows > 0 && A->columns > 0 && A->matrix != NULL) {
      res = 1;

      for (int i = 0; i < A->rows;
           i++) {  // at least one of rows wasn't allocated
        if (A->matrix[i] == NULL) {
          res = 0;
          break;
        }
      }
    }
  }

  return res;
}

void s21_get_mx(int row, int col, matrix_t *A, matrix_t *result) {
  int m_row = 0;
  int m_col = 0;

  for (int i = 0; i < A->rows; i++) {
    if (i == row) {
      continue;
    }

    m_col = 0;

    for (int j = 0; j < A->columns; j++) {
      if (j == col) {
        continue;
      }

      result->matrix[m_row][m_col] = A->matrix[i][j];
      m_col++;
    }
    m_row++;
  }
}

double s21_get_determinant(matrix_t *A) {
  double res = 0.0;

  if (A->rows == 1) {
    res = A->matrix[0][0];
  } else {
    matrix_t tmp = {0};
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);

    for (int i = 0; i < A->columns; i++) {
      s21_get_mx(0, i, A, &tmp);

      if (i % 2) {
        res -= A->matrix[0][i] * s21_get_determinant(&tmp);
      } else {
        res += A->matrix[0][i] * s21_get_determinant(&tmp);
      }
    }
    s21_remove_matrix(&tmp);
  }

  return res;
}