#include "../include/s21_matrix_oop.h"

/// @brief Checks if rows and cols numbers are positive
/// @param row
/// @param col
/// @return TRUE/FALSE
bool S21Matrix ::checkRowsCols(const int& row, const int& col) noexcept {
  return ((row >= 0) && (col >= 0));
}

/// @brief default constructor
S21Matrix ::S21Matrix() {
  this->rows_ = 0;
  this->cols_ = 0;
  this->matrix_ = nullptr;
}

/// @brief Parametrized constructor
/// @param rows
/// @param cols
S21Matrix ::S21Matrix(int rows, int cols) {
  this->rows_ = rows;
  this->cols_ = cols;

  if (checkRowsCols(this->rows_, this->cols_)) {
    memory_handling();

    for (auto i = 0; i < this->rows_; i++) {
      for (auto j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] = 0.0;
      }
    }

  } else {
    throw out_of_range("Rows and cols number should be positive");
  }
}

/// @brief Copy constructor
/// @param other
S21Matrix ::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (auto i = 0; i < this->rows_; i++) {
    for (auto j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

/// @brief Move constructor
/// @param other
S21Matrix ::S21Matrix(S21Matrix&& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->matrix_ = other.matrix_;  // points to the same memory block
  other.matrix_ = nullptr;
  other.rows_ = other.cols_ = 0;
}

/// @brief Matrix memory allocation function
void S21Matrix ::memory_handling() {
  this->matrix_ = new double*[rows_];

  for (int i = 0; i < this->rows_; i++) {
    this->matrix_[i] = new double[cols_];
  }
}

/// @brief Matrix memory deallocation function
/// @param matrix_
void S21Matrix ::delete_matrix(double** matrix_) {
  for (int i = 0; i < this->rows_; i++) {
    if (matrix_ && matrix_[i]) {
      delete[] matrix_[i];
    }
  }

  if (matrix_) delete[] matrix_;

  matrix_ = nullptr;
}

/// @brief Default destructor
S21Matrix ::~S21Matrix() {
  delete_matrix(matrix_);
  this->rows_ = 0;
  this->cols_ = 0;
}
