#pragma once

#include <cmath>
#include <iostream>

using namespace std;

enum class ForMode { i, j };

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  void memory_handling();
  void delete_matrix(double** matrix_);

 public:
  S21Matrix();
  S21Matrix(int row, int col);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

 public:
  int GetRows() const noexcept;
  int GetCols() const noexcept;
  bool checkRowsCols(const int& row, const int& col) noexcept;
  void SetRows(int rows);
  void SetCols(int cols);
  void SetResMx(const int& rows, const int& cols, const int& cmp,
                const ForMode& mode, double**& mx) noexcept;
  void setMxEl(const int& num, const int& row, const int& col) noexcept;
  double getMxEl(const int& row, const int& col) noexcept;

 public:
  bool EqMatrix(const S21Matrix& other) noexcept;
  bool RowsColsComparing(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double& number) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() noexcept;
  double Determinant();
  S21Matrix GetMinor(int pivotRow, int pivotCol, const S21Matrix& src);
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();

 public:
  bool operator==(const S21Matrix& other);
  double& operator()(const int& row, const int& col);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator*(const double& number) noexcept;
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix& operator*=(const double& number) noexcept;
  S21Matrix& operator*=(const S21Matrix& other);
  S21Matrix& operator=(const S21Matrix& other);
};
