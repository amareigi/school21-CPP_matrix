#include "test.h"

TEST(matrix_tests_sum, sum_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  Matrix1.SumMatrix(Matrix2);

  S21Matrix Matrix3(3, 4);
  double array3[12] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
  Matrix3.fill_matrix(array3);
  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_EQ(Matrix3.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_sum, sum_2) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1.SumMatrix(Matrix2));
}

TEST(matrix_tests_sum, sum_3) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(Matrix1.SumMatrix(Matrix2));
}

TEST(matrix_tests_sum, sum_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 3);
  double array2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(Matrix1.SumMatrix(Matrix2));
}
