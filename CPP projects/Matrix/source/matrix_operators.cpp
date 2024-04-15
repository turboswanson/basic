#include "../include/s21_matrix_oop.h"

/// @brief Checks for matrices equality (`EqMatrix`)
/// @param other
/// @return TRUE if equals and FALSE if not
bool S21Matrix ::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

/// @brief Indexation by matrix elements (row, column).
/// @param row
/// @param col
/// @return value of this->matrix_[row][col]
/// @return exception if index is outside the matrix
double& S21Matrix ::operator()(const int& row, const int& col) {
  if (checkRowsCols(row, col) && row < this->rows_ && col < this->cols_) {
    return matrix_[row][col];
  } else {
    throw out_of_range("Rows or cols number is out of range");
  }
}

/// @brief Addition of two matrices
/// @param other
/// @return The result matrix of adding the other matrix to this one
/// @return An exception if different matrix dimensions
S21Matrix S21Matrix ::operator+(const S21Matrix& other) {
  S21Matrix tmp(*this);
  tmp.SumMatrix(other);

  return tmp;
}

/// @brief Addition assignment (`SumMatrix`)
/// @param other
/// @return This matrix after adding the other matrix
/// @return An exception if different matrix dimensions
S21Matrix& S21Matrix ::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);

  return *this;
}

/// @brief Subtraction of two matrices
/// @param other
/// @return The result matrix of subtracting the other matrix from this one
/// @return An exception if different matrix dimensions
S21Matrix S21Matrix ::operator-(const S21Matrix& other) {
  S21Matrix tmp(*this);
  tmp.SubMatrix(other);

  return tmp;
}

/// @brief Substraction assignment (`SubMatrix`)
/// @param other
/// @return A reference to this matrix after subtracting the other matrix
/// @return An exception if different matrix dimensions
S21Matrix& S21Matrix ::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);

  return *this;
}

/// @brief Matrix multiplication by a number
/// @param number
/// @return The result matrix
S21Matrix S21Matrix ::operator*(const double& number) noexcept {
  S21Matrix tmp(*this);

  tmp.MulNumber(number);

  return tmp;
}

/// @brief Matrix multiplication
/// @param other
/// @return The result matrix
S21Matrix S21Matrix ::operator*(const S21Matrix& other) {
  S21Matrix tmp(*this);

  tmp.MulMatrix(other);

  return tmp;
}

/// @brief Number multiplication assignment
/// @param other
/// @return A reference to this matrix
S21Matrix& S21Matrix ::operator*=(const double& number) noexcept {
  this->MulNumber(number);

  return *this;
}

/// @brief Matrix multiplication assignment
/// @param other
/// @return A reference to this matrix
S21Matrix& S21Matrix ::operator*=(const S21Matrix& other) {
  this->MulMatrix(other);

  return *this;
}

/// @brief Assigment operator
/// @param other
/// @return A reference to this matrix
S21Matrix& S21Matrix ::operator=(const S21Matrix& other) {
  if (!this->EqMatrix(other)) {
    delete_matrix(this->matrix_);
    this->rows_ = other.rows_;
    this->cols_ = other.cols_;
    memory_handling();

    for (auto i = 0; i < this->rows_; i++) {
      for (auto j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] = other.matrix_[i][j];
      }
    }
  }

  return *this;
}