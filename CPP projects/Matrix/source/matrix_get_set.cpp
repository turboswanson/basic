#include "../include/s21_matrix_oop.h"

/// @brief Matrix rows number getter
/// @return  Matrix rows number
int S21Matrix ::GetRows() const noexcept { return rows_; }

/// @brief Matrix cols number getter
/// @return Matrix cols number
int S21Matrix ::GetCols() const noexcept { return cols_; }

/// @brief Matrix rows number setter
/// @param rows
/// @details returns an exception if rows <= 1
void S21Matrix ::SetRows(int rows) {
  if (rows < 1) {
    throw out_of_range("Rows number should be positive");
  }

  S21Matrix tmp(rows, this->cols_);

  ForMode mode{ForMode::i};

  SetResMx(rows, this->cols_, this->rows_, mode, tmp.matrix_);

  delete_matrix(matrix_);

  this->rows_ = rows;
  matrix_ = tmp.matrix_;
  tmp.matrix_ = nullptr;
}

/// @brief Matrix cols number setter
/// @param cols
/// @details returns an exception if cols <= 1
void S21Matrix ::SetCols(int cols) {
  if (cols < 1) {
    throw out_of_range("Cols number should be positive");
  }

  S21Matrix tmp(this->rows_, cols);

  ForMode mode{ForMode::j};

  SetResMx(this->rows_, cols, this->cols_, mode, tmp.matrix_);

  delete_matrix(this->matrix_);

  this->cols_ = cols;
  this->matrix_ = tmp.matrix_;
  tmp.matrix_ = nullptr;
}

/// @brief Set the result matrix dimensions when SetRows or SetCols is used
/// @param rows result matrix rows number
/// @param cols result matrix cols number
/// @param num original matrix rows or cols number depends of what mode is
/// @param mode setting rows or cols
/// @param mx result matrix
void S21Matrix ::SetResMx(const int& rows, const int& cols, const int& num,
                          const ForMode& mode, double**& mx) noexcept {
  int cmp = 0;

  for (auto i = 0; i < rows; i++) {
    for (auto j = 0; j < cols; j++) {
      if (static_cast<bool>(mode))
        cmp = j;
      else
        cmp = i;

      if (cmp >= num) {
        mx[i][j] = 0.0;
      } else {
        mx[i][j] = this->matrix_[i][j];
      }
    }
  }
}

// void S21Matrix ::setMxEl(const int& num, const int& row,
//                          const int& col) noexcept {
//   matrix_[row][col] = num;
// }

// double S21Matrix ::getMxEl(const int& row, const int& col) noexcept {
//   return matrix_[row][col];
// }
