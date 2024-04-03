#ifndef S21_MATRIX_H
#define S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
enum { OK = 0, INCORRECT_MATRIX = 1, CALC_ERROR = 2, MALLOC_FAILED = 3 };

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// STRUCTURE

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

// COMPARISON
int s21_eq_matrix(matrix_t *A, matrix_t *B);

// MATH

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// OTHER
int s21_transpose(matrix_t *A, matrix_t *result);

// auxiliary
int s21_is_matrix_ok(matrix_t *A);
void s21_print(matrix_t A);
void s21_fill(matrix_t *A);
void s21_get_mx(int row, int col, matrix_t *A, matrix_t *result);
double s21_get_determinant(matrix_t *A);

#endif