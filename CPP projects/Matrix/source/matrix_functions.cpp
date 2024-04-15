#include "../include/s21_matrix_oop.h"
/// @brief Checks if this matrix and other matrix rows and cols number are match
/// @param other
/// @return TRUE/FALSE
bool S21Matrix ::RowsColsComparing(const S21Matrix& other) {
  return ((this->rows_ == other.rows_) && (this->cols_ == other.cols_));
}

/// @brief Checks if two matrix are equal
/// @param other
/// @return TRUE/FALSE
bool S21Matrix ::EqMatrix(const S21Matrix& other) noexcept {
  bool result = true;

  if (rows_ != other.rows_ || cols_ != other.cols_) result = false;

  if (result) {
    for (auto i = 0; i < rows_ && result; i++) {
      for (auto j = 0; j < cols_; j++) {
        if (this->matrix_[i][j] != other.matrix_[i][j]) {
          result = false;
        }
      }
    }
  }

  return result;
}

/// @brief Adds the second matrix to the current one
/// @param other
void S21Matrix ::SumMatrix(const S21Matrix& other) {
  if (!RowsColsComparing(other)) {
    throw out_of_range("Rows and Cols numbers should be equal");
  }

  for (auto i = 0; i < this->rows_; i++) {
    for (auto j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

/// @brief Subtracts another matrix from the current one
/// @param other
void S21Matrix ::SubMatrix(const S21Matrix& other) {
  if (!RowsColsComparing(other)) {
    throw out_of_range("Rows and Cols numbers should be equal");
  }

  for (auto i = 0; i < this->rows_; i++) {
    for (auto j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

/// @brief Multiplies the current matrix by a number
/// @param number
void S21Matrix ::MulNumber(const double& number) noexcept {
  for (auto i = 0; i < this->rows_; i++) {
    for (auto j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] *= number;
    }
  }
}

/// @brief Multiplies the current matrix by the second matrix
/// @param other
void S21Matrix ::MulMatrix(const S21Matrix& other) {
  if (this->cols_ != other.rows_) {
    throw logic_error("Rows and Cols numbers should be equal");
  }

  S21Matrix res(this->rows_, other.cols_);

  for (auto i = 0; i < this->rows_; i++) {
    for (auto j = 0; j < other.cols_; j++) {
      for (auto k = 0; k < other.rows_; k++) {
        res.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }

  *this = move(res);
}

/// @brief Creates a new transposed matrix from the current one and returns it
/// @return The result matrix
S21Matrix S21Matrix ::Transpose() noexcept {
  S21Matrix tmp(this->cols_, this->rows_);

  for (auto i = 0; i < this->cols_; i++) {
    for (auto j = 0; j < this->rows_; j++) {
      tmp.matrix_[i][j] = this->matrix_[j][i];
    }
  }

  return tmp;
}

/// @brief Getting minor matrix for the current one
/// @param pivotRow row index
/// @param pivotCol col index
/// @param src original matrix
/// @return The result matrix
S21Matrix S21Matrix ::GetMinor(int pivotRow, int pivotCol,
                               const S21Matrix& src) {
  S21Matrix res(src.rows_ - 1, src.cols_ - 1);

  int mRow = 0;
  int mCol = 0;

  for (auto i = 0; i < src.rows_; i++) {
    if (i == pivotRow) continue;

    mCol = 0;

    for (auto j = 0; j < src.cols_; j++) {
      if (j == pivotCol) continue;

      res.matrix_[mRow][mCol] = src.matrix_[i][j];
      mCol++;
    }

    mRow++;
  }

  return res;
}

/// @brief Calculates and returns the determinant of the current matrix.
/// @return Determinant number
double S21Matrix ::Determinant() {
  if (this->rows_ != this->cols_) {
    throw logic_error("The matrix is not squere");
  }

  double res = 0.0;

  if (this->rows_ == 1) {
    res = this->matrix_[0][0];
  } else {
    for (auto i = 0; i < this->cols_; i++) {
      S21Matrix tmp(GetMinor(0, i, *this));

      if (i % 2) {
        res -= this->matrix_[0][i] * tmp.Determinant();
      } else {
        res += this->matrix_[0][i] * tmp.Determinant();
      }
    }
  }

  return res;
}

/// @brief  Calculates the algebraic addition matrix of the current one and
/// returns it.
/// @return The result matrix
S21Matrix S21Matrix ::CalcComplements() {
  if (this->rows_ != this->cols_) {
    throw logic_error("The matrix is not squere");
  }
  S21Matrix res(this->rows_, this->cols_);

  if (this->rows_ == 1) {
    res.matrix_[0][0] = this->matrix_[0][0];
  } else {
    for (auto i = 0; i < res.rows_; i++) {
      for (auto j = 0; j < res.cols_; j++) {
        S21Matrix tmp(GetMinor(i, j, *this));

        res.matrix_[i][j] = tmp.Determinant() * pow(-1, i + j);
      }
    }
  }

  return res;
}

/// @brief Calculates and returns the inverse matrix
/// @return The result matrix
S21Matrix S21Matrix ::InverseMatrix() {
  if (!this->Determinant()) {
    throw logic_error("The inverse one doesn't exist for this matrix");
  }

  double coef = 1.0 / Determinant();
  S21Matrix res;

  if (this->rows_ == 1) {
    S21Matrix tmp(1, 1);
    tmp.matrix_[0][0] = coef;
    res = tmp;

  } else {
    S21Matrix tmp = this->CalcComplements().Transpose() * coef;
    res = tmp;
  }

  return res;
}