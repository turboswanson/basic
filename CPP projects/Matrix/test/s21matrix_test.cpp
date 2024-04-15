#include "../include/s21_matrix_oop.h"
#include "gtest/gtest.h"

using namespace std;

static void FillMx(S21Matrix& matrix) {
  int count = 0;

  for (auto i = 0; i < matrix.GetRows(); i++) {
    for (auto j = 0; j < matrix.GetCols(); j++) {
      matrix(i, j) = ++count;
      // matrix.setMxEl(++count, i, j);
    }
  }
}

// static void PrintMx(S21Matrix& matrix) {
//   for (auto i = 0; i < matrix.GetRows(); i++) {
//     for (auto j = 0; j < matrix.GetCols(); j++) {
//       cout << matrix(i, j) << " ";
//     }
//     cout << endl;
//   }
// }

static S21Matrix GetIdentityMatrix(int size) {
  S21Matrix result{size, size};

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      if (i == j) {
        result(i, j) = 1.0;
      }
    }
  }

  return result;
}

static void TestInverse(S21Matrix& matrix) {
  S21Matrix matrix_before = matrix;
  double det = matrix.Determinant();
  if (!det) {
    EXPECT_ANY_THROW(matrix.InverseMatrix());
  } else {
    S21Matrix matrix_inverse = matrix.InverseMatrix();
    S21Matrix matrix_mult = matrix * matrix_inverse;
    S21Matrix matrix_identity = GetIdentityMatrix(matrix.GetRows());

    for (auto i = 0; i < matrix_mult.GetRows(); i++) {
      for (auto j = 0; j < matrix_mult.GetCols(); j++) {
        EXPECT_NEAR(matrix_mult(i, j), matrix_identity(i, j), 1e-7);
      }
    }
  }
}

TEST(constructor, default) {
  S21Matrix mx;
  EXPECT_EQ(mx.GetRows(), 0);
  EXPECT_EQ(mx.GetCols(), 0);
}

TEST(constructor, parameterized) {
  S21Matrix mx(3, 4);
  EXPECT_EQ(mx.GetRows(), 3);
  EXPECT_EQ(mx.GetCols(), 4);
}

TEST(constructor, parameterized_invalid) {
  EXPECT_THROW(S21Matrix mx(-3, 4), out_of_range);
}

TEST(constructor, copy) {
  S21Matrix src1(7, 8);
  FillMx(src1);
  S21Matrix dst1(src1);
  EXPECT_EQ(dst1.EqMatrix(src1), true);
}

TEST(construct, move) {
  S21Matrix src(5, 5);
  FillMx(src);
  S21Matrix dst = move(src);

  EXPECT_DOUBLE_EQ(dst(0, 0), 1.);
  EXPECT_DOUBLE_EQ(dst(0, 1), 2.);
  EXPECT_DOUBLE_EQ(dst(0, 2), 3.);
  EXPECT_DOUBLE_EQ(dst(0, 3), 4.);
  EXPECT_DOUBLE_EQ(dst(0, 4), 5.);
  EXPECT_DOUBLE_EQ(dst(1, 0), 6.);
  EXPECT_DOUBLE_EQ(dst(1, 1), 7.);
  EXPECT_DOUBLE_EQ(dst(1, 2), 8.);
  EXPECT_DOUBLE_EQ(dst(1, 3), 9.);
  EXPECT_DOUBLE_EQ(dst(1, 4), 10.);
  EXPECT_DOUBLE_EQ(dst(2, 0), 11.);
  EXPECT_DOUBLE_EQ(dst(2, 1), 12.);
  EXPECT_DOUBLE_EQ(dst(2, 2), 13.);
  EXPECT_DOUBLE_EQ(dst(2, 3), 14);
  EXPECT_DOUBLE_EQ(dst(2, 4), 15.);
  EXPECT_DOUBLE_EQ(dst(3, 0), 16.);
  EXPECT_DOUBLE_EQ(dst(3, 1), 17.);
  EXPECT_DOUBLE_EQ(dst(3, 2), 18.);
  EXPECT_DOUBLE_EQ(dst(3, 3), 19.);
  EXPECT_DOUBLE_EQ(dst(3, 4), 20.);
  EXPECT_DOUBLE_EQ(dst(4, 0), 21.);
  EXPECT_DOUBLE_EQ(dst(4, 1), 22.);
  EXPECT_DOUBLE_EQ(dst(4, 2), 23.);
  EXPECT_DOUBLE_EQ(dst(4, 3), 24);
  EXPECT_DOUBLE_EQ(dst(4, 4), 25.);
}

TEST(function, setRows_01) {
  S21Matrix mx(3, 3);
  FillMx(mx);
  mx.SetRows(4);

  for (auto i = 0; i < mx.GetCols(); i++) {
    EXPECT_EQ(mx(3, i), 0.0);
  }
}

TEST(function, setRows_02) {
  S21Matrix mx(3, 3);

  mx(0, 0) = 10.0;
  mx(0, 1) = 20.0;
  mx(0, 2) = 30.0;
  mx(1, 0) = 40.0;
  mx(1, 1) = 50.0;
  mx(1, 2) = 60.0;
  mx(2, 0) = 70.0;
  mx(2, 1) = 80.0;
  mx(2, 2) = 90.0;

  mx.SetRows(1);

  EXPECT_EQ(mx.GetRows(), 1);
}

TEST(function, setRows_03) {
  S21Matrix mx(3, 3);

  mx(0, 0) = 10.0;
  mx(0, 1) = 20.0;
  mx(0, 2) = 30.0;
  mx(1, 0) = 40.0;
  mx(1, 1) = 50.0;
  mx(1, 2) = 60.0;
  mx(2, 0) = 70.0;
  mx(2, 1) = 80.0;
  mx(2, 2) = 90.0;

  EXPECT_THROW(mx.SetRows(-1), out_of_range);
}

TEST(function, setCols_01) {
  S21Matrix mx(3, 3);

  mx(0, 0) = 10.0;
  mx(0, 1) = 20.0;
  mx(0, 2) = 30.0;
  mx(1, 0) = 40.0;
  mx(1, 1) = 50.0;
  mx(1, 2) = 60.0;
  mx(2, 0) = 70.0;
  mx(2, 1) = 80.0;
  mx(2, 2) = 90.0;

  mx.SetCols(1);

  EXPECT_EQ(mx.GetCols(), 1);
}

TEST(function, setCols_02) {
  S21Matrix mx(3, 3);

  mx(0, 0) = 10.0;
  mx(0, 1) = 20.0;
  mx(0, 2) = 30.0;
  mx(1, 0) = 40.0;
  mx(1, 1) = 50.0;
  mx(1, 2) = 60.0;
  mx(2, 0) = 70.0;
  mx(2, 1) = 80.0;
  mx(2, 2) = 90.0;

  mx.SetCols(4);

  EXPECT_EQ(mx.GetCols(), 4);

  for (auto i = 0; i < mx.GetRows(); i++) {
    EXPECT_EQ(mx(i, 3), 0.0);
  }
}

TEST(function, setCols_03) {
  S21Matrix mx(3, 3);

  mx(0, 0) = 10.0;
  mx(0, 1) = 20.0;
  mx(0, 2) = 30.0;
  mx(1, 0) = 40.0;
  mx(1, 1) = 50.0;
  mx(1, 2) = 60.0;
  mx(2, 0) = 70.0;
  mx(2, 1) = 80.0;
  mx(2, 2) = 90.0;

  EXPECT_THROW(mx.SetCols(-1), out_of_range);
}

TEST(function, setCols_04) {
  S21Matrix mx(3, 3);

  mx(0, 0) = 10.0;
  mx(0, 1) = 20.0;
  mx(0, 2) = 30.0;
  mx(1, 0) = 40.0;
  mx(1, 1) = 50.0;
  mx(1, 2) = 60.0;
  mx(2, 0) = 70.0;
  mx(2, 1) = 80.0;
  mx(2, 2) = 90.0;

  mx.SetCols(5);

  EXPECT_EQ(mx.GetCols(), 5);
}

TEST(fucntion, checkRowsCols_01) {
  S21Matrix mx(5, 5);

  EXPECT_FALSE(mx.checkRowsCols(-1, -1));
}

TEST(fucntion, checkRowsCols_02) {
  S21Matrix mx(5, 5);

  EXPECT_FALSE(mx.checkRowsCols(2, -1));
}

TEST(fucntion, checkRowsCols_03) {
  S21Matrix mx(5, 5);

  EXPECT_FALSE(mx.checkRowsCols(2, -3));
}

TEST(function, equality) {
  S21Matrix src1(7, 8);
  FillMx(src1);
  S21Matrix src2(7, 8);
  FillMx(src2);
  ASSERT_TRUE(src2.EqMatrix(src1));
}

TEST(operator, equality) {
  S21Matrix src1(7, 8);
  FillMx(src1);
  S21Matrix src2(7, 8);
  FillMx(src2);

  ASSERT_TRUE(src1 == src2);
}

TEST(function, RowsColsComparing) {
  S21Matrix src(3, 4);
  S21Matrix other(4, 3);
  EXPECT_THROW(src.SumMatrix(other), out_of_range);
}

TEST(function, sumMatrix) {
  S21Matrix src(3, 4);
  S21Matrix other(4, 3);

  EXPECT_THROW(src.SumMatrix(other), out_of_range);
}

TEST(operators, brackets) {
  S21Matrix src(6, 6);
  EXPECT_THROW(src(-1, 3), out_of_range);
}

TEST(operator, brackets_01) {
  S21Matrix src(2, 2);
  FillMx(src);
  EXPECT_DOUBLE_EQ(src(0, 0), 1);
}

TEST(operator, brackets_02) {
  S21Matrix src(2, 2);
  FillMx(src);
  EXPECT_THROW(src(5, 1), out_of_range);
}

TEST(operator, brackets_03) {
  S21Matrix src(2, 2);
  FillMx(src);
  EXPECT_THROW(src(1, 5), out_of_range);
}

TEST(function, sum) {
  S21Matrix matrix1(2, 2);

  matrix1(0, 0) = 1.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 0) = 3.0;
  matrix1(1, 1) = 4.0;

  S21Matrix matrix2(2, 2);

  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = 6.0;
  matrix2(1, 0) = 7.0;
  matrix2(1, 1) = 8.0;

  matrix1.SumMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 6.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 8.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 10.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 12.0);
}

TEST(operator, add_01) {
  S21Matrix src(2, 2);
  S21Matrix mx(2, 2);
  FillMx(src);
  FillMx(mx);
  S21Matrix res = src + mx;

  EXPECT_DOUBLE_EQ(res(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(res(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(res(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(res(1, 1), 8.0);
}

TEST(operator, add_02) {
  S21Matrix src(2, 2);
  S21Matrix mx(3, 3);
  FillMx(src);
  FillMx(mx);
  EXPECT_THROW(S21Matrix res = src + mx, out_of_range);
}

TEST(operator, add_03) {
  S21Matrix src(2, 2);
  S21Matrix mx(2, 2);
  FillMx(src);
  FillMx(mx);
  src += mx;

  EXPECT_DOUBLE_EQ(src(0, 0), 2.0);
  EXPECT_DOUBLE_EQ(src(0, 1), 4.0);
  EXPECT_DOUBLE_EQ(src(1, 0), 6.0);
  EXPECT_DOUBLE_EQ(src(1, 1), 8.0);
}

TEST(function, sub) {
  S21Matrix matrix1(2, 2);

  matrix1(0, 0) = 10.0;
  matrix1(0, 1) = 20.0;
  matrix1(1, 0) = 30.0;
  matrix1(1, 1) = 40.0;

  S21Matrix matrix2(2, 2);

  matrix2(0, 0) = 5.0;
  matrix2(0, 1) = 5.0;
  matrix2(1, 0) = 5.0;
  matrix2(1, 1) = 5.0;

  matrix1.SubMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 15.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 25.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 35.0);
}

TEST(operator, sub_01) {
  S21Matrix mx1(3, 3);
  S21Matrix mx2(3, 3);

  mx1(0, 0) = 10.0;
  mx1(0, 1) = 20.0;
  mx1(0, 2) = 30.0;
  mx1(1, 0) = 40.0;
  mx1(1, 1) = 50.0;
  mx1(1, 2) = 60.0;
  mx1(2, 0) = 70.0;
  mx1(2, 1) = 80.0;
  mx1(2, 2) = 90.0;

  mx2(0, 0) = 10.0;
  mx2(0, 1) = 10.0;
  mx2(0, 2) = 10.0;
  mx2(1, 0) = 10.0;
  mx2(1, 1) = 10.0;
  mx2(1, 2) = 10.0;
  mx2(2, 0) = 10.0;
  mx2(2, 1) = 10.0;
  mx2(2, 2) = 10.0;

  S21Matrix res = mx1 - mx2;

  EXPECT_DOUBLE_EQ(res(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(res(0, 1), 10.0);
  EXPECT_DOUBLE_EQ(res(0, 2), 20.0);
  EXPECT_DOUBLE_EQ(res(1, 0), 30.0);
  EXPECT_DOUBLE_EQ(res(1, 1), 40.0);
  EXPECT_DOUBLE_EQ(res(1, 2), 50.0);
  EXPECT_DOUBLE_EQ(res(2, 0), 60.0);
  EXPECT_DOUBLE_EQ(res(2, 1), 70.0);
  EXPECT_DOUBLE_EQ(res(2, 2), 80.0);
}

TEST(operator, sub_02) {
  S21Matrix src(2, 2);
  S21Matrix mx(3, 1);
  FillMx(src);
  FillMx(mx);
  EXPECT_THROW(S21Matrix res = src - mx, out_of_range);
}

TEST(operator, sub_03) {
  S21Matrix mx1(3, 3);
  S21Matrix mx2(3, 3);

  mx1(0, 0) = 10.0;
  mx1(0, 1) = 20.0;
  mx1(0, 2) = 30.0;
  mx1(1, 0) = 40.0;
  mx1(1, 1) = 50.0;
  mx1(1, 2) = 60.0;
  mx1(2, 0) = 70.0;
  mx1(2, 1) = 80.0;
  mx1(2, 2) = 90.0;

  mx2(0, 0) = 10.0;
  mx2(0, 1) = 10.0;
  mx2(0, 2) = 10.0;
  mx2(1, 0) = 10.0;
  mx2(1, 1) = 10.0;
  mx2(1, 2) = 10.0;
  mx2(2, 0) = 10.0;
  mx2(2, 1) = 10.0;
  mx2(2, 2) = 10.0;

  mx1 -= mx2;

  EXPECT_DOUBLE_EQ(mx1(0, 0), 0.0);
  EXPECT_DOUBLE_EQ(mx1(0, 1), 10.0);
  EXPECT_DOUBLE_EQ(mx1(0, 2), 20.0);
  EXPECT_DOUBLE_EQ(mx1(1, 0), 30.0);
  EXPECT_DOUBLE_EQ(mx1(1, 1), 40.0);
  EXPECT_DOUBLE_EQ(mx1(1, 2), 50.0);
  EXPECT_DOUBLE_EQ(mx1(2, 0), 60.0);
  EXPECT_DOUBLE_EQ(mx1(2, 1), 70.0);
  EXPECT_DOUBLE_EQ(mx1(2, 2), 80.0);
}

TEST(function, mulNumber_01) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 10.0;
  matrix(0, 1) = 20.0;
  matrix(1, 0) = 30.0;
  matrix(1, 1) = 40.0;

  double number = 0.5;

  matrix.MulNumber(number);

  EXPECT_DOUBLE_EQ(matrix(0, 0), 5.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 10.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 15.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 20.0);
}

TEST(operator, mulNumber_02) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 10.0;
  matrix(0, 1) = 20.0;
  matrix(1, 0) = 30.0;
  matrix(1, 1) = 40.0;

  double number = 2.0;

  S21Matrix res = matrix * number;

  EXPECT_DOUBLE_EQ(res(0, 0), 20.0);
  EXPECT_DOUBLE_EQ(res(0, 1), 40.0);
  EXPECT_DOUBLE_EQ(res(1, 0), 60.0);
  EXPECT_DOUBLE_EQ(res(1, 1), 80.0);
}

TEST(operator, mulAssignment) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 10.0;
  matrix(0, 1) = 20.0;
  matrix(1, 0) = 30.0;
  matrix(1, 1) = 40.0;

  double number = 2.0;

  matrix *= number;

  EXPECT_DOUBLE_EQ(matrix(0, 0), 20.0);
  EXPECT_DOUBLE_EQ(matrix(0, 1), 40.0);
  EXPECT_DOUBLE_EQ(matrix(1, 0), 60.0);
  EXPECT_DOUBLE_EQ(matrix(1, 1), 80.0);
}

TEST(operator, assignment) {
  S21Matrix matrix(2, 2);

  matrix(0, 0) = 10.0;
  matrix(0, 1) = 20.0;
  matrix(1, 0) = 30.0;
  matrix(1, 1) = 40.0;

  S21Matrix res;
  res = matrix;

  EXPECT_DOUBLE_EQ(res(0, 0), 10.0);
  EXPECT_DOUBLE_EQ(res(0, 1), 20.0);
  EXPECT_DOUBLE_EQ(res(1, 0), 30.0);
  EXPECT_DOUBLE_EQ(res(1, 1), 40.0);
}

TEST(function, mulMatrix_01) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 2);

  matrix1(0, 0) = 1.0;
  matrix1(1, 0) = 3.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 1) = 1.0;
  matrix1(0, 2) = 2.0;
  matrix1(1, 2) = 1.0;

  matrix2(0, 0) = 4.0;
  matrix2(1, 0) = 3.0;
  matrix2(2, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 1) = 1.0;
  matrix2(2, 1) = 5.0;

  matrix1.MulMatrix(matrix2);

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 12.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 14.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 16.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 12.0);
}

TEST(function, mulMatrix_02) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(2, 2);

  EXPECT_THROW(matrix1.MulMatrix(matrix2), logic_error);
}

TEST(operator, mulMatrix_03) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 2);

  matrix1(0, 0) = 1.0;
  matrix1(1, 0) = 3.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 1) = 1.0;
  matrix1(0, 2) = 2.0;
  matrix1(1, 2) = 1.0;

  matrix2(0, 0) = 4.0;
  matrix2(1, 0) = 3.0;
  matrix2(2, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 1) = 1.0;
  matrix2(2, 1) = 5.0;

  S21Matrix res = matrix1 * matrix2;

  EXPECT_DOUBLE_EQ(res(0, 0), 12.0);
  EXPECT_DOUBLE_EQ(res(0, 1), 14.0);
  EXPECT_DOUBLE_EQ(res(1, 0), 16.0);
  EXPECT_DOUBLE_EQ(res(1, 1), 12.0);
}

TEST(operator, mulMatrix_04) {
  S21Matrix matrix1(2, 3);
  S21Matrix matrix2(3, 2);

  matrix1(0, 0) = 1.0;
  matrix1(1, 0) = 3.0;
  matrix1(0, 1) = 2.0;
  matrix1(1, 1) = 1.0;
  matrix1(0, 2) = 2.0;
  matrix1(1, 2) = 1.0;

  matrix2(0, 0) = 4.0;
  matrix2(1, 0) = 3.0;
  matrix2(2, 0) = 1.0;
  matrix2(0, 1) = 2.0;
  matrix2(1, 1) = 1.0;
  matrix2(2, 1) = 5.0;

  matrix1 *= matrix2;

  EXPECT_DOUBLE_EQ(matrix1(0, 0), 12.0);
  EXPECT_DOUBLE_EQ(matrix1(0, 1), 14.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 0), 16.0);
  EXPECT_DOUBLE_EQ(matrix1(1, 1), 12.0);
}

TEST(function, transpose_01) {
  S21Matrix mx(1, 4);

  mx(0, 0) = 1;
  mx(0, 1) = 2;
  mx(0, 2) = 3;
  mx(0, 3) = 4;

  S21Matrix check(4, 1);

  check(0, 0) = 1;
  check(1, 0) = 2;
  check(2, 0) = 3;
  check(3, 0) = 4;

  S21Matrix res = mx.Transpose();

  EXPECT_TRUE(check == res);
}

TEST(function, transpose_02) {
  S21Matrix matrix1{3, 2};

  S21Matrix result_check{2, 3};

  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = 6;

  result_check(0, 0) = 1;
  result_check(1, 0) = 2;
  result_check(0, 1) = 3;
  result_check(1, 1) = 4;
  result_check(0, 2) = 5;
  result_check(1, 2) = 6;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
}

TEST(function, transpose_03) {
  S21Matrix matrix1{7, 7};

  S21Matrix result_check{7, 7};

  matrix1(0, 0) = 1.91308;
  matrix1(0, 1) = 0.60095;
  matrix1(0, 2) = -0.44777;
  matrix1(0, 3) = -0.50040;
  matrix1(0, 4) = -1.12823;
  matrix1(0, 5) = -1.81865;
  matrix1(0, 6) = -0.70084;
  matrix1(1, 0) = 1.95162;
  matrix1(1, 1) = 1.16720;
  matrix1(1, 2) = 1.28391;
  matrix1(1, 3) = -1.83298;
  matrix1(1, 4) = 1.30395;
  matrix1(1, 5) = -1.94659;
  matrix1(1, 6) = 0.92036;
  matrix1(2, 0) = -1.49041;
  matrix1(2, 1) = 1.08027;
  matrix1(2, 2) = 1.69253;
  matrix1(2, 3) = 0.59772;
  matrix1(2, 4) = 0.36828;
  matrix1(2, 5) = -0.47550;
  matrix1(2, 6) = 0.17188;
  matrix1(3, 0) = -0.41712;
  matrix1(3, 1) = -0.57195;
  matrix1(3, 2) = -1.52959;
  matrix1(3, 3) = 0.79822;
  matrix1(3, 4) = -0.81870;
  matrix1(3, 5) = -0.71609;
  matrix1(3, 6) = -1.58015;
  matrix1(4, 0) = -0.90661;
  matrix1(4, 1) = -0.09334;
  matrix1(4, 2) = 0.63205;
  matrix1(4, 3) = 1.27734;
  matrix1(4, 4) = 0.34700;
  matrix1(4, 5) = -0.91391;
  matrix1(4, 6) = 0.63581;
  matrix1(5, 0) = 1.30982;
  matrix1(5, 1) = 1.27461;
  matrix1(5, 2) = 0.56120;
  matrix1(5, 3) = -0.54912;
  matrix1(5, 4) = 1.28915;
  matrix1(5, 5) = 0.63719;
  matrix1(5, 6) = 0.38849;
  matrix1(6, 0) = -0.53430;
  matrix1(6, 1) = -0.10767;
  matrix1(6, 2) = 1.19456;
  matrix1(6, 3) = 0.05376;
  matrix1(6, 4) = 0.83746;
  matrix1(6, 5) = -0.85603;
  matrix1(6, 6) = -0.73690;

  result_check(0, 0) = 1.91308;
  result_check(0, 1) = 1.95162;
  result_check(0, 2) = -1.49041;
  result_check(0, 3) = -0.41712;
  result_check(0, 4) = -0.90661;
  result_check(0, 5) = 1.30982;
  result_check(0, 6) = -0.5343;
  result_check(1, 0) = 0.60095;
  result_check(1, 1) = 1.1672;
  result_check(1, 2) = 1.08027;
  result_check(1, 3) = -0.57195;
  result_check(1, 4) = -0.09334;
  result_check(1, 5) = 1.27461;
  result_check(1, 6) = -0.10767;
  result_check(2, 0) = -0.44777;
  result_check(2, 1) = 1.28391;
  result_check(2, 2) = 1.69253;
  result_check(2, 3) = -1.52959;
  result_check(2, 4) = 0.63205;
  result_check(2, 5) = 0.56120;
  result_check(2, 6) = 1.19456;
  result_check(3, 0) = -0.5004;
  result_check(3, 1) = -1.83298;
  result_check(3, 2) = 0.59772;
  result_check(3, 3) = 0.79822;
  result_check(3, 4) = 1.27734;
  result_check(3, 5) = -0.54912;
  result_check(3, 6) = 0.05376;
  result_check(4, 0) = -1.12823;
  result_check(4, 1) = 1.30395;
  result_check(4, 2) = 0.36828;
  result_check(4, 3) = -0.81870;
  result_check(4, 4) = 0.347;
  result_check(4, 5) = 1.28915;
  result_check(4, 6) = 0.83746;
  result_check(5, 0) = -1.81865;
  result_check(5, 1) = -1.94659;
  result_check(5, 2) = -0.47550;
  result_check(5, 3) = -0.71609;
  result_check(5, 4) = -0.91391;
  result_check(5, 5) = 0.63719;
  result_check(5, 6) = -0.85603;
  result_check(6, 0) = -0.70084;
  result_check(6, 1) = 0.92036;
  result_check(6, 2) = 0.17188;
  result_check(6, 3) = -1.58015;
  result_check(6, 4) = 0.63581;
  result_check(6, 5) = 0.38849;
  result_check(6, 6) = -0.73690;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
}

TEST(function, transpose_04) {
  S21Matrix matrix1{1, 20};

  S21Matrix result_check{20, 1};

  matrix1(0, 0) = -1.32;
  matrix1(0, 1) = -1.36;
  matrix1(0, 2) = -0.09;
  matrix1(0, 3) = -0.06;
  matrix1(0, 4) = 0.49;
  matrix1(0, 5) = 0.09;
  matrix1(0, 6) = 0.61;
  matrix1(0, 7) = -1.45;
  matrix1(0, 8) = 0.55;
  matrix1(0, 9) = -0.34;
  matrix1(0, 10) = 1.26;
  matrix1(0, 11) = -1.58;
  matrix1(0, 12) = 1.29;
  matrix1(0, 13) = -1.57;
  matrix1(0, 14) = 1.62;
  matrix1(0, 15) = 1.85;
  matrix1(0, 16) = 0.34;
  matrix1(0, 17) = -0.09;
  matrix1(0, 18) = 1.22;
  matrix1(0, 19) = 0.58;

  result_check(0, 0) = -1.32;
  result_check(1, 0) = -1.36;
  result_check(2, 0) = -0.09;
  result_check(3, 0) = -0.06;
  result_check(4, 0) = 0.49;
  result_check(5, 0) = 0.09;
  result_check(6, 0) = 0.61;
  result_check(7, 0) = -1.45;
  result_check(8, 0) = 0.55;
  result_check(9, 0) = -0.34;
  result_check(10, 0) = 1.26;
  result_check(11, 0) = -1.58;
  result_check(12, 0) = 1.29;
  result_check(13, 0) = -1.57;
  result_check(14, 0) = 1.62;
  result_check(15, 0) = 1.85;
  result_check(16, 0) = 0.34;
  result_check(17, 0) = -0.09;
  result_check(18, 0) = 1.22;
  result_check(19, 0) = 0.58;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.Transpose();

  EXPECT_TRUE(result == result_check);
}

TEST(function, determinant_exception) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.Determinant());
}

TEST(function, determinant_01) {
  S21Matrix matrix1{1, 1};

  matrix1(0, 0) = 1.5;

  double result_check = 1.5;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_02) {
  S21Matrix matrix1{2, 2};

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  double result_check = -0.02;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_03) {
  S21Matrix matrix1{2, 2};

  matrix1(0, 0) = 7.72122069261968;
  matrix1(1, 0) = -7.3629210004583;
  matrix1(0, 1) = 8.93235725676641;
  matrix1(1, 1) = 2.69165195827372;

  double result_check = 86.5510796270;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_04) {
  S21Matrix matrix1{3, 3};

  matrix1(0, 0) = 0;
  matrix1(0, 1) = 1;
  matrix1(0, 2) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(1, 2) = 5;
  matrix1(2, 0) = 6;
  matrix1(2, 1) = 0;
  matrix1(2, 2) = 7;

  double result_check = -39;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
  EXPECT_TRUE(matrix1 == matrix_before);
}

TEST(function, determinant_05) {
  S21Matrix matrix1{3, 3};

  matrix1(0, 0) = 5.34922476788051;
  matrix1(1, 0) = 1.65522041497752;
  matrix1(2, 0) = -8.68382598599419;
  matrix1(0, 1) = -3.25669884728268;
  matrix1(1, 1) = 10.8967615629081;
  matrix1(2, 1) = 4.55130848893896;
  matrix1(0, 2) = -2.14478276530281;
  matrix1(1, 2) = -2.7382052554749;
  matrix1(2, 2) = 5.7808097708039;

  double result_check = 138.2380038449;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_06) {
  S21Matrix matrix1{4, 4};

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(0, 3) = 1.4;
  matrix1(1, 0) = 1.5;
  matrix1(1, 1) = 1.6;
  matrix1(1, 2) = 1.7;
  matrix1(1, 3) = 1.8;
  matrix1(2, 0) = 1.9;
  matrix1(2, 1) = 2.0;
  matrix1(2, 2) = 2.1;
  matrix1(2, 3) = 2.2;
  matrix1(3, 0) = 2.3;
  matrix1(3, 1) = 2.4;
  matrix1(3, 2) = 2.5;
  matrix1(3, 3) = 2.6;

  double result_check = -5.1347814888913e-17;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_07) {
  S21Matrix matrix1{5, 5};

  matrix1(0, 0) = 4901269.0;
  matrix1(0, 1) = 342540400593534.0;
  matrix1(0, 2) = 342540400593534.0;
  matrix1(0, 3) = 9.0;
  matrix1(0, 4) = 161144851.0;
  matrix1(1, 0) = 9048793031.0;
  matrix1(1, 1) = 342540400593534.0;
  matrix1(1, 2) = 342540400593534.0;
  matrix1(1, 3) = 87223389614.0;
  matrix1(1, 4) = 517528813858064.0;
  matrix1(2, 0) = 1645298951.0;
  matrix1(2, 1) = 342540400593534.0;
  matrix1(2, 2) = 342540400593534.0;
  matrix1(2, 3) = 115755924305184.0;
  matrix1(2, 4) = 744137398.0;
  matrix1(3, 0) = 295628643374509.0;
  matrix1(3, 1) = 342540400593534.0;
  matrix1(3, 2) = 342540400593534.0;
  matrix1(3, 3) = 17278333962.0;
  matrix1(3, 4) = 245717847641320.0;
  matrix1(4, 0) = 5490974393.0;
  matrix1(4, 1) = 342540400593534.0;
  matrix1(4, 2) = 342540400593534.0;
  matrix1(4, 3) = 71848710.0;
  matrix1(4, 4) = 429.0;

  double result_check = 0.0;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_08) {
  S21Matrix matrix1{4, 4};

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(0, 2) = 1.3;
  matrix1(0, 3) = 1.4;
  matrix1(1, 0) = 1.5;
  matrix1(1, 1) = 1.6;
  matrix1(1, 2) = 1.7;
  matrix1(1, 3) = 1.8;
  matrix1(2, 0) = 1.9;
  matrix1(2, 1) = 2.0;
  matrix1(2, 2) = 2.1;
  matrix1(2, 3) = 2.2;
  matrix1(3, 0) = 2.3;
  matrix1(3, 1) = 2.4;
  matrix1(3, 2) = 2.5;
  matrix1(3, 3) = 2.6;

  double result_check = -5.1347814888913e-17;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_09) {
  S21Matrix matrix1{4, 4};

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(3, 0) = 7.95983747509308;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(3, 1) = -3.41600720770657;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;
  matrix1(3, 2) = -10.6065054496285;
  matrix1(0, 3) = 0.586602877592668;
  matrix1(1, 3) = 10.6546861075331;
  matrix1(2, 3) = 4.33103069034405;
  matrix1(3, 3) = 8.75408579711802;

  double result_check = -6618.5495718153;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_10) {
  S21Matrix matrix1{5, 5};

  matrix1(0, 0) = 5.543;
  matrix1(0, 1) = 25.425;
  matrix1(0, 2) = 24.4325;
  matrix1(0, 3) = 23.52;
  matrix1(0, 4) = 0.0;
  matrix1(1, 0) = 52.3;
  matrix1(1, 1) = 53.2;
  matrix1(1, 2) = 34.434;
  matrix1(1, 3) = 0.0;
  matrix1(1, 4) = 53.352;
  matrix1(2, 0) = 54.23512;
  matrix1(2, 1) = 34.325;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 24.343;
  matrix1(2, 4) = 34.422;
  matrix1(3, 0) = 36.22;
  matrix1(3, 1) = 0.0;
  matrix1(3, 2) = 32.0;
  matrix1(3, 3) = 24.432;
  matrix1(3, 4) = 43.21;
  matrix1(4, 0) = 0.0;
  matrix1(4, 1) = 23.21;
  matrix1(4, 2) = 23.234;
  matrix1(4, 3) = 12.1231;
  matrix1(4, 4) = 21.2232;

  double result_check = 74346939.8940858;

  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_11) {
  S21Matrix matrix1{6, 6};

  matrix1(0, 0) = -8.25324401422404;
  matrix1(1, 0) = 7.73323425720446;
  matrix1(2, 0) = 1.84863350028172;
  matrix1(3, 0) = -10.0115760930348;
  matrix1(4, 0) = -5.15668712323532;
  matrix1(5, 0) = 0.833224474685267;
  matrix1(0, 1) = 6.72777522937395;
  matrix1(1, 1) = -5.02706401585601;
  matrix1(2, 1) = -0.966418515890837;
  matrix1(3, 1) = 7.74789611180313;
  matrix1(4, 1) = 0.869955397676677;
  matrix1(5, 1) = -2.01394975557923;
  matrix1(0, 2) = -4.55829650838859;
  matrix1(1, 2) = 3.51532235136256;
  matrix1(2, 2) = -7.3990064188838;
  matrix1(3, 2) = 0.485122002195567;
  matrix1(4, 2) = 9.88733662408777;
  matrix1(5, 2) = -3.07178143155761;
  matrix1(0, 3) = -6.01939426595345;
  matrix1(1, 3) = -7.33630517800339;
  matrix1(2, 3) = -3.09628330147825;
  matrix1(3, 3) = 8.41876223543659;
  matrix1(4, 3) = -3.80699184164405;
  matrix1(5, 3) = 1.82289709686302;
  matrix1(0, 4) = 9.28037635562941;
  matrix1(1, 4) = 8.25562612293288;
  matrix1(2, 4) = 3.07955321925692;
  matrix1(3, 4) = 1.94713557977229;
  matrix1(4, 4) = 7.41955809853971;
  matrix1(5, 4) = -9.39580690651201;
  matrix1(0, 5) = 2.73021495575085;
  matrix1(1, 5) = -5.90446221316233;
  matrix1(2, 5) = 5.84046185878105;
  matrix1(3, 5) = -2.47668161639012;
  matrix1(4, 5) = 1.28693996206857;
  matrix1(5, 5) = 4.85558348917402;

  double result_check = -109019.85742181906954580110;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, determinant_12) {
  S21Matrix matrix1{9, 9};

  matrix1(0, 0) = -0.93;
  matrix1(0, 1) = 0.96;
  matrix1(0, 2) = 0.56;
  matrix1(0, 3) = 0.05;
  matrix1(0, 4) = -0.94;
  matrix1(0, 5) = 0.01;
  matrix1(0, 6) = 0.69;
  matrix1(0, 7) = -1.70;
  matrix1(0, 8) = 0.21;
  matrix1(1, 0) = -1.68;
  matrix1(1, 1) = 0.11;
  matrix1(1, 2) = -0.34;
  matrix1(1, 3) = -1.74;
  matrix1(1, 4) = -0.13;
  matrix1(1, 5) = -0.79;
  matrix1(1, 6) = -0.56;
  matrix1(1, 7) = -1.84;
  matrix1(1, 8) = 1.86;
  matrix1(2, 0) = -1.37;
  matrix1(2, 1) = 0.23;
  matrix1(2, 2) = -0.60;
  matrix1(2, 3) = -1.65;
  matrix1(2, 4) = -1.91;
  matrix1(2, 5) = -0.90;
  matrix1(2, 6) = -0.38;
  matrix1(2, 7) = 0.82;
  matrix1(2, 8) = 1.05;
  matrix1(3, 0) = -1.77;
  matrix1(3, 1) = 1.66;
  matrix1(3, 2) = 0.17;
  matrix1(3, 3) = 0.55;
  matrix1(3, 4) = 1.93;
  matrix1(3, 5) = -0.89;
  matrix1(3, 6) = -0.08;
  matrix1(3, 7) = 1.34;
  matrix1(3, 8) = 1.74;
  matrix1(4, 0) = 0.23;
  matrix1(4, 1) = 1.96;
  matrix1(4, 2) = -0.33;
  matrix1(4, 3) = -1.73;
  matrix1(4, 4) = 0.25;
  matrix1(4, 5) = 1.22;
  matrix1(4, 6) = -0.36;
  matrix1(4, 7) = 1.16;
  matrix1(4, 8) = 1.07;
  matrix1(5, 0) = 0.25;
  matrix1(5, 1) = -0.83;
  matrix1(5, 2) = -1.90;
  matrix1(5, 3) = 0.10;
  matrix1(5, 4) = 0.26;
  matrix1(5, 5) = -1.38;
  matrix1(5, 6) = -0.52;
  matrix1(5, 7) = -0.97;
  matrix1(5, 8) = -0.01;
  matrix1(6, 0) = 1.28;
  matrix1(6, 1) = -1.70;
  matrix1(6, 2) = 1.32;
  matrix1(6, 3) = -1.35;
  matrix1(6, 4) = 0.18;
  matrix1(6, 5) = -0.66;
  matrix1(6, 6) = 1.16;
  matrix1(6, 7) = -0.81;
  matrix1(6, 8) = -1.06;
  matrix1(7, 0) = 0.87;
  matrix1(7, 1) = 1.66;
  matrix1(7, 2) = 0.12;
  matrix1(7, 3) = -1.83;
  matrix1(7, 4) = -1.25;
  matrix1(7, 5) = 0.41;
  matrix1(7, 6) = 1.21;
  matrix1(7, 7) = -1.95;
  matrix1(7, 8) = 0.08;
  matrix1(8, 0) = 1.92;
  matrix1(8, 1) = 1.96;
  matrix1(8, 2) = -1.64;
  matrix1(8, 3) = -0.44;
  matrix1(8, 4) = 1.36;
  matrix1(8, 5) = 0.74;
  matrix1(8, 6) = -0.67;
  matrix1(8, 7) = -1.03;
  matrix1(8, 8) = 1.60;

  double result_check = -63.322314761722227635;
  S21Matrix matrix_before = matrix1;
  double result = matrix1.Determinant();

  EXPECT_NEAR(result_check, result, 1e-7);
}

TEST(function, CalcComplements_exception) {
  S21Matrix test_matrix(2, 3);

  EXPECT_ANY_THROW(S21Matrix res = test_matrix.CalcComplements());
}

TEST(function, CalcComplements_01) {
  S21Matrix matrix1{3, 3};

  matrix1(0, 0) = -3.00;
  matrix1(0, 1) = 6.00;
  matrix1(0, 2) = -3.00;
  matrix1(1, 0) = 6.00;
  matrix1(1, 1) = -12.00;
  matrix1(1, 2) = 6.00;
  matrix1(2, 0) = -3.00;
  matrix1(2, 1) = 6.00;
  matrix1(2, 2) = -3.00;

  S21Matrix result_check{3, 3};

  result_check(0, 0) = 0.0;
  result_check(0, 1) = 0.0;
  result_check(0, 2) = 0.0;
  result_check(1, 0) = 0.0;
  result_check(1, 1) = 0.0;
  result_check(1, 2) = 0.0;
  result_check(2, 0) = 0.0;
  result_check(2, 1) = 0.0;
  result_check(2, 2) = 0.0;

  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
}

TEST(function, CalcComplements_02) {
  S21Matrix matrix1{2, 2};

  S21Matrix result_check{2, 2};

  matrix1(0, 0) = 12.452;
  matrix1(0, 1) = 3.34245;
  matrix1(1, 0) = 3.356;
  matrix1(1, 1) = 3.543;

  result_check(0, 0) = 3.543;
  result_check(0, 1) = -3.356;
  result_check(1, 0) = -3.34245;
  result_check(1, 1) = 12.452;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
}

TEST(function, CalcComplements_03) {
  S21Matrix matrix1{3, 3};

  S21Matrix result_check{3, 3};

  matrix1(0, 0) = 1;
  matrix1(1, 0) = 2;
  matrix1(2, 0) = 3;
  matrix1(0, 1) = 4;
  matrix1(1, 1) = 5;
  matrix1(2, 1) = 6;
  matrix1(0, 2) = 7;
  matrix1(1, 2) = 8;
  matrix1(2, 2) = 9;

  result_check(0, 0) = -3;
  result_check(1, 0) = 6;
  result_check(2, 0) = -3;
  result_check(0, 1) = 6;
  result_check(1, 1) = -12;
  result_check(2, 1) = 6;
  result_check(0, 2) = -3;
  result_check(1, 2) = 6;
  result_check(2, 2) = -3;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  EXPECT_TRUE(result == result_check);
  EXPECT_TRUE(matrix1 == matrix_before);
}

// TEST(function, CalcComplements_04) {
//   S21Matrix matrix1{9, 9};

//   S21Matrix result_check{9, 9};

//   matrix1(0, 0) = -3.00;
//   matrix1(0, 1) = -4.00;
//   matrix1(0, 2) = -9.00;
//   matrix1(0, 3) = 1.00;
//   matrix1(0, 4) = -8.00;
//   matrix1(0, 5) = 4.00;
//   matrix1(0, 6) = -5.00;
//   matrix1(0, 7) = -4.00;
//   matrix1(0, 8) = -6.00;
//   matrix1(1, 0) = 3.00;
//   matrix1(1, 1) = 8.00;
//   matrix1(1, 2) = 1.00;
//   matrix1(1, 3) = -5.00;
//   matrix1(1, 4) = -4.00;
//   matrix1(1, 5) = -9.00;
//   matrix1(1, 6) = 1.00;
//   matrix1(1, 7) = -4.00;
//   matrix1(1, 8) = -1.00;
//   matrix1(2, 0) = 5.00;
//   matrix1(2, 1) = 6.00;
//   matrix1(2, 2) = 9.00;
//   matrix1(2, 3) = 3.00;
//   matrix1(2, 4) = 3.00;
//   matrix1(2, 5) = 3.00;
//   matrix1(2, 6) = -1.00;
//   matrix1(2, 7) = 1.00;
//   matrix1(2, 8) = 3.00;
//   matrix1(3, 0) = 5.00;
//   matrix1(3, 1) = -8.00;
//   matrix1(3, 2) = 7.00;
//   matrix1(3, 3) = 1.00;
//   matrix1(3, 4) = -9.00;
//   matrix1(3, 5) = 6.00;
//   matrix1(3, 6) = -3.00;
//   matrix1(3, 7) = -9.00;
//   matrix1(3, 8) = 0.00;
//   matrix1(4, 0) = 6.00;
//   matrix1(4, 1) = 6.00;
//   matrix1(4, 2) = -5.00;
//   matrix1(4, 3) = 0.00;
//   matrix1(4, 4) = -5.00;
//   matrix1(4, 5) = 9.00;
//   matrix1(4, 6) = -2.00;
//   matrix1(4, 7) = 7.00;
//   matrix1(4, 8) = 0.00;
//   matrix1(5, 0) = 6.00;
//   matrix1(5, 1) = 5.00;
//   matrix1(5, 2) = 0.00;
//   matrix1(5, 3) = -1.00;
//   matrix1(5, 4) = 0.00;
//   matrix1(5, 5) = 3.00;
//   matrix1(5, 6) = -6.00;
//   matrix1(5, 7) = -5.00;
//   matrix1(5, 8) = 1.00;
//   matrix1(6, 0) = 2.00;
//   matrix1(6, 1) = 0.00;
//   matrix1(6, 2) = -1.00;
//   matrix1(6, 3) = -5.00;
//   matrix1(6, 4) = 5.00;
//   matrix1(6, 5) = 8.00;
//   matrix1(6, 6) = 6.00;
//   matrix1(6, 7) = 4.00;
//   matrix1(6, 8) = 7.00;
//   matrix1(7, 0) = -8.00;
//   matrix1(7, 1) = -5.00;
//   matrix1(7, 2) = 4.00;
//   matrix1(7, 3) = 5.00;
//   matrix1(7, 4) = 8.00;
//   matrix1(7, 5) = -3.00;
//   matrix1(7, 6) = 5.00;
//   matrix1(7, 7) = -2.00;
//   matrix1(7, 8) = 0.00;
//   matrix1(8, 0) = -4.00;
//   matrix1(8, 1) = -8.00;
//   matrix1(8, 2) = -1.00;
//   matrix1(8, 3) = -6.00;
//   matrix1(8, 4) = 3.00;
//   matrix1(8, 5) = 9.00;
//   matrix1(8, 6) = -5.00;
//   matrix1(8, 7) = 9.00;
//   matrix1(8, 8) = 2.00;

//   result_check(0, 0) = 64929368;
//   result_check(0, 1) = -24807174;
//   result_check(0, 2) = 8377463;
//   result_check(0, 3) = -26260983;
//   result_check(0, 4) = 48249195;
//   result_check(0, 5) = 4895273;
//   result_check(0, 6) = 27415810;
//   result_check(0, 7) = 7596327;
//   result_check(0, 8) = -104010645;
//   result_check(1, 0) = -20042180;
//   result_check(1, 1) = 441474;
//   result_check(1, 2) = -13241381;
//   result_check(1, 3) = 28508523;
//   result_check(1, 4) = -22388553;
//   result_check(1, 5) = -12886241;
//   result_check(1, 6) = -20643250;
//   result_check(1, 7) = 2020605;
//   result_check(1, 8) = 71456481;
//   result_check(2, 0) = 78208172;
//   result_check(2, 1) = -31032894;
//   result_check(2, 2) = 4206257;
//   result_check(2, 3) = -37734051;
//   result_check(2, 4) = 61396875;
//   result_check(2, 5) = 10903673;
//   result_check(2, 6) = 38091514;
//   result_check(2, 7) = 3287709;
//   result_check(2, 8) = -139542003;
//   result_check(3, 0) = -27960066;
//   result_check(3, 1) = 11520882;
//   result_check(3, 2) = -8199477;
//   result_check(3, 3) = 15345105;
//   result_check(3, 4) = -18994227;
//   result_check(3, 5) = -8126343;
//   result_check(3, 6) = -16303074;
//   result_check(3, 7) = 456789;
//   result_check(3, 8) = 54345621;
//   result_check(4, 0) = -77614272;
//   result_check(4, 1) = 21243606;
//   result_check(4, 2) = -15804054;
//   result_check(4, 3) = 42368916;
//   result_check(4, 4) = -64653306;
//   result_check(4, 5) = -24710580;
//   result_check(4, 6) = -46419510;
//   result_check(4, 7) = -5933874;
//   result_check(4, 8) = 167781828;
//   result_check(5, 0) = -48498594;
//   result_check(5, 1) = 13815210;
//   result_check(5, 2) = -4044546;
//   result_check(5, 3) = 25243776;
//   result_check(5, 4) = -45877464;
//   result_check(5, 5) = -11919810;
//   result_check(5, 6) = -17816604;
//   result_check(5, 7) = 4305048;
//   result_check(5, 8) = 90513822;
//   result_check(6, 0) = 29519486;
//   result_check(6, 1) = -11122350;
//   result_check(6, 2) = 6357968;
//   result_check(6, 3) = -10618146;
//   result_check(6, 4) = 22712856;
//   result_check(6, 5) = 1457480;
//   result_check(6, 6) = 8381164;
//   result_check(6, 7) = 5516616;
//   result_check(6, 8) = -58625688;
//   result_check(7, 0) = -68478154;
//   result_check(7, 1) = 18602172;
//   result_check(7, 2) = -19885636;
//   result_check(7, 3) = 46293450;
//   result_check(7, 4) = -69658230;
//   result_check(7, 5) = -28413616;
//   result_check(7, 6) = -47667548;
//   result_check(7, 7) = 1703430;
//   result_check(7, 8) = 171904224;
//   result_check(8, 0) = -11614148;
//   result_check(8, 1) = 4369176;
//   result_check(8, 2) = -8028302;
//   result_check(8, 3) = 16614012;
//   result_check(8, 4) = -15098268;
//   result_check(8, 5) = -7254086;
//   result_check(8, 6) = -5637238;
//   result_check(8, 7) = -2592960;
//   result_check(8, 8) = 39427050;

//   S21Matrix matrix_before = matrix1;
//   S21Matrix result = matrix1.CalcComplements();

//   EXPECT_TRUE(result == result_check);
// }

// TEST(function, CalcComplements_05) {
//   S21Matrix matrix1{10, 10};
//   S21Matrix result_check{10, 10};

//   matrix1(0, 0) = -1;
//   matrix1(0, 1) = -0;
//   matrix1(0, 2) = 1;
//   matrix1(0, 3) = 1;
//   matrix1(0, 4) = 1;
//   matrix1(0, 5) = 1;
//   matrix1(0, 6) = -0;
//   matrix1(0, 7) = 0;
//   matrix1(0, 8) = -1;
//   matrix1(0, 9) = 0;
//   matrix1(1, 0) = 1;
//   matrix1(1, 1) = -0;
//   matrix1(1, 2) = -0;
//   matrix1(1, 3) = -1;
//   matrix1(1, 4) = -0;
//   matrix1(1, 5) = -0;
//   matrix1(1, 6) = -1;
//   matrix1(1, 7) = 0;
//   matrix1(1, 8) = -0;
//   matrix1(1, 9) = -1;
//   matrix1(2, 0) = 1;
//   matrix1(2, 1) = -1;
//   matrix1(2, 2) = -0;
//   matrix1(2, 3) = -1;
//   matrix1(2, 4) = -0;
//   matrix1(2, 5) = 0;
//   matrix1(2, 6) = -0;
//   matrix1(2, 7) = 0;
//   matrix1(2, 8) = 1;
//   matrix1(2, 9) = -0;
//   matrix1(3, 0) = -0;
//   matrix1(3, 1) = -1;
//   matrix1(3, 2) = -0;
//   matrix1(3, 3) = 1;
//   matrix1(3, 4) = 1;
//   matrix1(3, 5) = -0;
//   matrix1(3, 6) = 1;
//   matrix1(3, 7) = -0;
//   matrix1(3, 8) = -1;
//   matrix1(3, 9) = 1;
//   matrix1(4, 0) = 0;
//   matrix1(4, 1) = 1;
//   matrix1(4, 2) = 1;
//   matrix1(4, 3) = 0;
//   matrix1(4, 4) = -0;
//   matrix1(4, 5) = 1;
//   matrix1(4, 6) = -1;
//   matrix1(4, 7) = -1;
//   matrix1(4, 8) = 0;
//   matrix1(4, 9) = -0;
//   matrix1(5, 0) = 1;
//   matrix1(5, 1) = 1;
//   matrix1(5, 2) = 1;
//   matrix1(5, 3) = 0;
//   matrix1(5, 4) = -0;
//   matrix1(5, 5) = 0;
//   matrix1(5, 6) = 0;
//   matrix1(5, 7) = 1;
//   matrix1(5, 8) = -0;
//   matrix1(5, 9) = 1;
//   matrix1(6, 0) = -0;
//   matrix1(6, 1) = 0;
//   matrix1(6, 2) = -0;
//   matrix1(6, 3) = -0;
//   matrix1(6, 4) = 1;
//   matrix1(6, 5) = 0;
//   matrix1(6, 6) = -1;
//   matrix1(6, 7) = -0;
//   matrix1(6, 8) = -1;
//   matrix1(6, 9) = 1;
//   matrix1(7, 0) = -0;
//   matrix1(7, 1) = 0;
//   matrix1(7, 2) = -0;
//   matrix1(7, 3) = -1;
//   matrix1(7, 4) = -1;
//   matrix1(7, 5) = 0;
//   matrix1(7, 6) = -1;
//   matrix1(7, 7) = 1;
//   matrix1(7, 8) = 0;
//   matrix1(7, 9) = -1;
//   matrix1(8, 0) = 0;
//   matrix1(8, 1) = 1;
//   matrix1(8, 2) = 0;
//   matrix1(8, 3) = 1;
//   matrix1(8, 4) = -1;
//   matrix1(8, 5) = 1;
//   matrix1(8, 6) = -1;
//   matrix1(8, 7) = -1;
//   matrix1(8, 8) = -0;
//   matrix1(8, 9) = 0;
//   matrix1(9, 0) = -0;
//   matrix1(9, 1) = 1;
//   matrix1(9, 2) = 1;
//   matrix1(9, 3) = -0;
//   matrix1(9, 4) = -0;
//   matrix1(9, 5) = 1;
//   matrix1(9, 6) = 0;
//   matrix1(9, 7) = -0;
//   matrix1(9, 8) = -1;
//   matrix1(9, 9) = -1;

//   result_check(0, 0) = -2;
//   result_check(0, 1) = -1;
//   result_check(0, 2) = -2;
//   result_check(0, 3) = 13;
//   result_check(0, 4) = 15;
//   result_check(0, 5) = 9;
//   result_check(0, 6) = -7;
//   result_check(0, 7) = 13;
//   result_check(0, 8) = 14;
//   result_check(0, 9) = -8;
//   result_check(1, 0) = 13;
//   result_check(1, 1) = -5;
//   result_check(1, 2) = 13;
//   result_check(1, 3) = 19;
//   result_check(1, 4) = 6;
//   result_check(1, 5) = -24;
//   result_check(1, 6) = -12;
//   result_check(1, 7) = -4;
//   result_check(1, 8) = 1;
//   result_check(1, 9) = -17;
//   result_check(2, 0) = 2;
//   result_check(2, 1) = 1;
//   result_check(2, 2) = -21;
//   result_check(2, 3) = -13;
//   result_check(2, 4) = 8;
//   result_check(2, 5) = 37;
//   result_check(2, 6) = 7;
//   result_check(2, 7) = 10;
//   result_check(2, 8) = 9;
//   result_check(2, 9) = 8;
//   result_check(3, 0) = 6;
//   result_check(3, 1) = -20;
//   result_check(3, 2) = 29;
//   result_check(3, 3) = 7;
//   result_check(3, 4) = -22;
//   result_check(3, 5) = -27;
//   result_check(3, 6) = -2;
//   result_check(3, 7) = -16;
//   result_check(3, 8) = -19;
//   result_check(3, 9) = 1;
//   result_check(4, 0) = -5;
//   result_check(4, 1) = -14;
//   result_check(4, 2) = 41;
//   result_check(4, 3) = -2;
//   result_check(4, 4) = -20;
//   result_check(4, 5) = -35;
//   result_check(4, 6) = -6;
//   result_check(4, 7) = -25;
//   result_check(4, 8) = -11;
//   result_check(4, 9) = 3;
//   result_check(5, 0) = 6;
//   result_check(5, 1) = 3;
//   result_check(5, 2) = 6;
//   result_check(5, 3) = 7;
//   result_check(5, 4) = 1;
//   result_check(5, 5) = -4;
//   result_check(5, 6) = -2;
//   result_check(5, 7) = 7;
//   result_check(5, 8) = 4;
//   result_check(5, 9) = 1;
//   result_check(6, 0) = -3;
//   result_check(6, 1) = 10;
//   result_check(6, 2) = -26;
//   result_check(6, 3) = -15;
//   result_check(6, 4) = 11;
//   result_check(6, 5) = 25;
//   result_check(6, 6) = 1;
//   result_check(6, 7) = 8;
//   result_check(6, 8) = -2;
//   result_check(6, 9) = 11;
//   result_check(7, 0) = -5;
//   result_check(7, 1) = -14;
//   result_check(7, 2) = 18;
//   result_check(7, 3) = -2;
//   result_check(7, 4) = -20;
//   result_check(7, 5) = -12;
//   result_check(7, 6) = -6;
//   result_check(7, 7) = -2;
//   result_check(7, 8) = -11;
//   result_check(7, 9) = 3;
//   result_check(8, 0) = 6;
//   result_check(8, 1) = 3;
//   result_check(8, 2) = -17;
//   result_check(8, 3) = 7;
//   result_check(8, 4) = 1;
//   result_check(8, 5) = 19;
//   result_check(8, 6) = -2;
//   result_check(8, 7) = 7;
//   result_check(8, 8) = 4;
//   result_check(8, 9) = 1;
//   result_check(9, 0) = 1;
//   result_check(9, 1) = 12;
//   result_check(9, 2) = -22;
//   result_check(9, 3) = -18;
//   result_check(9, 4) = 4;
//   result_check(9, 5) = 30;
//   result_check(9, 6) = 15;
//   result_check(9, 7) = 5;
//   result_check(9, 8) = -7;
//   result_check(9, 9) = 4;

//   S21Matrix matrix_before = matrix1;
//   S21Matrix result = matrix1.CalcComplements();

//   EXPECT_TRUE(result == result_check);
// }

TEST(function, CalcComplements_06) {
  S21Matrix matrix1{4, 4};

  S21Matrix result_check{4, 4};

  matrix1(0, 0) = 1.01;
  matrix1(0, 1) = 15;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 16;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 17;
  matrix1(2, 2) = 3;
  matrix1(2, 3) = 3;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 18;
  matrix1(3, 2) = 4;
  matrix1(3, 3) = 4;

  result_check(0, 0) = 0;
  result_check(0, 1) = -0;
  result_check(0, 2) = 0;
  result_check(0, 3) = -0;
  result_check(1, 0) = -0;
  result_check(1, 1) = 0;
  result_check(1, 2) = -0.14;
  result_check(1, 3) = 0.14;
  result_check(2, 0) = 0;
  result_check(2, 1) = -0;
  result_check(2, 2) = 0.28;
  result_check(2, 3) = -0.28;
  result_check(3, 0) = -0;
  result_check(3, 1) = 0;
  result_check(3, 2) = -0.14;
  result_check(3, 3) = 0.14;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  for (auto i = 0; i < matrix1.GetRows(); i++) {
    for (auto j = 0; j < matrix1.GetCols(); j++) {
      EXPECT_NEAR(result(i, j), result_check(i, j), 1e-7);
    }
  }
}

TEST(function, CalcComplements_07) {
  S21Matrix matrix1{4, 4};

  S21Matrix result_check{4, 4};

  matrix1(0, 0) = 1.000001;
  matrix1(0, 1) = 15;
  matrix1(0, 2) = 1;
  matrix1(0, 3) = 1;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 16;
  matrix1(1, 2) = 2;
  matrix1(1, 3) = 2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = 17;
  matrix1(2, 2) = 3;
  matrix1(2, 3) = 3;
  matrix1(3, 0) = 4;
  matrix1(3, 1) = 18;
  matrix1(3, 2) = 4;
  matrix1(3, 3) = 4;

  result_check(0, 0) = 0;
  result_check(0, 1) = -0;
  result_check(0, 2) = 0;
  result_check(0, 3) = -0;
  result_check(1, 0) = -0;
  result_check(1, 1) = 0;
  result_check(1, 2) = -1.4e-5;
  result_check(1, 3) = 1.4e-5;
  result_check(2, 0) = 0;
  result_check(2, 1) = -0;
  result_check(2, 2) = 2.8e-5;
  result_check(2, 3) = -2.8e-5;
  result_check(3, 0) = -0;
  result_check(3, 1) = 0;
  result_check(3, 2) = -1.4e-5;
  result_check(3, 3) = 1.4e-5;

  S21Matrix matrix_before = matrix1;
  S21Matrix result = matrix1.CalcComplements();

  for (auto i = 0; i < matrix1.GetRows(); i++) {
    for (auto j = 0; j < matrix1.GetCols(); j++) {
      EXPECT_NEAR(result(i, j), result_check(i, j), 1e-7);
    }
  }
}

TEST(function, InverseException_01) {
  S21Matrix test_matrix(2, 3);
  S21Matrix matrix_before = test_matrix;

  EXPECT_ANY_THROW(test_matrix.InverseMatrix());
  EXPECT_TRUE(test_matrix == matrix_before);
}

TEST(function, InverseException_02) {
  S21Matrix matrix1{1, 1};

  matrix1(0, 0) = 0.0;

  S21Matrix matrix_before = matrix1;

  EXPECT_ANY_THROW(matrix1.InverseMatrix());
}

TEST(function, Inverse_01) {
  S21Matrix matrix1{1, 1};

  matrix1(0, 0) = 1.5;

  TestInverse(matrix1);
}

TEST(function, Inverse_02) {
  S21Matrix matrix1{2, 2};

  matrix1(0, 0) = 1.1;
  matrix1(0, 1) = 1.2;
  matrix1(1, 0) = 1.3;
  matrix1(1, 1) = 1.4;

  TestInverse(matrix1);
}

TEST(function, Inverse_03) {
  S21Matrix matrix1{3, 3};

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;

  TestInverse(matrix1);
}

TEST(function, Inverse_04) {
  S21Matrix matrix1{4, 4};

  matrix1(0, 0) = -7.00037610391155;
  matrix1(1, 0) = -6.32839397341013;
  matrix1(2, 0) = 10.222164043691;
  matrix1(3, 0) = 7.95983747509308;
  matrix1(0, 1) = -9.82599597726949;
  matrix1(1, 1) = 3.03237457247451;
  matrix1(2, 1) = 0.587724786484614;
  matrix1(3, 1) = -3.41600720770657;
  matrix1(0, 2) = 8.27683520526625;
  matrix1(1, 2) = -4.28063526446931;
  matrix1(2, 2) = -6.93227237439714;
  matrix1(3, 2) = -10.6065054496285;
  matrix1(0, 3) = 0.586602877592668;
  matrix1(1, 3) = 10.6546861075331;
  matrix1(2, 3) = 4.33103069034405;
  matrix1(3, 3) = 8.75408579711802;

  TestInverse(matrix1);
}

TEST(function, Inverse_05) {
  S21Matrix matrix1{5, 5};

  matrix1(0, 0) = 54.543;
  matrix1(0, 1) = 255.425;
  matrix1(0, 2) = 24.4325;
  matrix1(0, 3) = 23.52;
  matrix1(0, 4) = 0.0;
  matrix1(1, 0) = 523.3;
  matrix1(1, 1) = 534.2;
  matrix1(1, 2) = 342.434;
  matrix1(1, 3) = 0.0;
  matrix1(1, 4) = 532.352;
  matrix1(2, 0) = 543.23512;
  matrix1(2, 1) = 34.325;
  matrix1(2, 2) = 0.0;
  matrix1(2, 3) = 241.343;
  matrix1(2, 4) = 3423.422;
  matrix1(3, 0) = 3625.22;
  matrix1(3, 1) = 0.0;
  matrix1(3, 2) = 3244.0;
  matrix1(3, 3) = 24.432;
  matrix1(3, 4) = 4365.21;
  matrix1(4, 0) = 0.0;
  matrix1(4, 1) = 231.21;
  matrix1(4, 2) = 2314.234;
  matrix1(4, 3) = 1234.1231;
  matrix1(4, 4) = 213.2232;

  TestInverse(matrix1);
}

TEST(function, Inverse_06) {
  S21Matrix matrix1{7, 7};

  matrix1(0, 0) = 832;
  matrix1(0, 1) = -253;
  matrix1(0, 2) = -100;
  matrix1(0, 3) = -215;
  matrix1(0, 4) = -63;
  matrix1(0, 5) = -236;
  matrix1(0, 6) = -771;
  matrix1(1, 0) = 473;
  matrix1(1, 1) = 104;
  matrix1(1, 2) = -626;
  matrix1(1, 3) = 354;
  matrix1(1, 4) = -915;
  matrix1(1, 5) = -258;
  matrix1(1, 6) = -580;
  matrix1(2, 0) = -597;
  matrix1(2, 1) = 831;
  matrix1(2, 2) = -498;
  matrix1(2, 3) = -504;
  matrix1(2, 4) = 691;
  matrix1(2, 5) = 912;
  matrix1(2, 6) = -973;
  matrix1(3, 0) = 131;
  matrix1(3, 1) = -949;
  matrix1(3, 2) = -875;
  matrix1(3, 3) = 127;
  matrix1(3, 4) = -38;
  matrix1(3, 5) = -7;
  matrix1(3, 6) = 587;
  matrix1(4, 0) = 661;
  matrix1(4, 1) = 301;
  matrix1(4, 2) = -283;
  matrix1(4, 3) = -254;
  matrix1(4, 4) = -948;
  matrix1(4, 5) = -449;
  matrix1(4, 6) = 338;
  matrix1(5, 0) = -207;
  matrix1(5, 1) = -880;
  matrix1(5, 2) = -838;
  matrix1(5, 3) = 697;
  matrix1(5, 4) = 893;
  matrix1(5, 5) = -915;
  matrix1(5, 6) = -592;
  matrix1(6, 0) = 739;
  matrix1(6, 1) = 886;
  matrix1(6, 2) = 912;
  matrix1(6, 3) = 247;
  matrix1(6, 4) = -118;
  matrix1(6, 5) = -30;
  matrix1(6, 6) = -336;

  TestInverse(matrix1);
}

// TEST(function, Inverse_07) {
//   S21Matrix matrix1{9, 9};

//   matrix1(0, 0) = -929;
//   matrix1(0, 1) = -332;
//   matrix1(0, 2) = 313;
//   matrix1(0, 3) = 190;
//   matrix1(0, 4) = 287;
//   matrix1(0, 5) = 44;
//   matrix1(0, 6) = -468;
//   matrix1(0, 7) = -381;
//   matrix1(0, 8) = -397;
//   matrix1(1, 0) = 961;
//   matrix1(1, 1) = 371;
//   matrix1(1, 2) = -532;
//   matrix1(1, 3) = 842;
//   matrix1(1, 4) = 87;
//   matrix1(1, 5) = 92;
//   matrix1(1, 6) = -40;
//   matrix1(1, 7) = -356;
//   matrix1(1, 8) = 822;
//   matrix1(2, 0) = -469;
//   matrix1(2, 1) = -55;
//   matrix1(2, 2) = -426;
//   matrix1(2, 3) = 282;
//   matrix1(2, 4) = -706;
//   matrix1(2, 5) = -270;
//   matrix1(2, 6) = 912;
//   matrix1(2, 7) = -823;
//   matrix1(2, 8) = -769;
//   matrix1(3, 0) = -612;
//   matrix1(3, 1) = -924;
//   matrix1(3, 2) = 327;
//   matrix1(3, 3) = 454;
//   matrix1(3, 4) = -29;
//   matrix1(3, 5) = -366;
//   matrix1(3, 6) = 724;
//   matrix1(3, 7) = 775;
//   matrix1(3, 8) = 897;
//   matrix1(4, 0) = -775;
//   matrix1(4, 1) = -36;
//   matrix1(4, 2) = 9;
//   matrix1(4, 3) = -955;
//   matrix1(4, 4) = -289;
//   matrix1(4, 5) = -594;
//   matrix1(4, 6) = -735;
//   matrix1(4, 7) = 475;
//   matrix1(4, 8) = 993;
//   matrix1(5, 0) = 89;
//   matrix1(5, 1) = -156;
//   matrix1(5, 2) = -834;
//   matrix1(5, 3) = -102;
//   matrix1(5, 4) = 465;
//   matrix1(5, 5) = 626;
//   matrix1(5, 6) = -649;
//   matrix1(5, 7) = -828;
//   matrix1(5, 8) = 248;
//   matrix1(6, 0) = -660;
//   matrix1(6, 1) = -400;
//   matrix1(6, 2) = -30;
//   matrix1(6, 3) = 740;
//   matrix1(6, 4) = 374;
//   matrix1(6, 5) = 473;
//   matrix1(6, 6) = -654;
//   matrix1(6, 7) = 684;
//   matrix1(6, 8) = -153;
//   matrix1(7, 0) = -374;
//   matrix1(7, 1) = -892;
//   matrix1(7, 2) = -316;
//   matrix1(7, 3) = -811;
//   matrix1(7, 4) = 789;
//   matrix1(7, 5) = 222;
//   matrix1(7, 6) = -985;
//   matrix1(7, 7) = -248;
//   matrix1(7, 8) = -440;
//   matrix1(8, 0) = -869;
//   matrix1(8, 1) = -758;
//   matrix1(8, 2) = 332;
//   matrix1(8, 3) = -572;
//   matrix1(8, 4) = 105;
//   matrix1(8, 5) = -548;
//   matrix1(8, 6) = 925;
//   matrix1(8, 7) = 137;
//   matrix1(8, 8) = 739;

//   TestInverse(matrix1);
// }

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
