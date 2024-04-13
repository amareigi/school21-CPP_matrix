#include "test.h"

TEST(matrix_tests_operator_sum_matrix, operator_sum_matrix_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  Matrix1 += Matrix2;

  S21Matrix Matrix_exp_res(3, 4);
  double array3[12] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_sum_matrix, operator_sum_matrix_2) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1 += Matrix2);
}

TEST(matrix_tests_operator_sum_matrix, operator_sum_matrix_3) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(Matrix1 += Matrix2);
}

TEST(matrix_tests_operator_sum_matrix, operator_sum_matrix_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 3);
  double array2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(Matrix1 += Matrix2);
}

TEST(matrix_tests_operator_sub_matrix, operator_sub_matrix_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  Matrix1 -= Matrix2;

  S21Matrix Matrix_exp_res(3, 4);
  double array3[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_sub_matrix, operator_sub_matrix_2) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1 -= Matrix2);
}

TEST(matrix_tests_operator_sub_matrix, operator_sub_matrix_3) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(Matrix1 -= Matrix2);
}

TEST(matrix_tests_operator_sub_matrix, operator_sub_matrix_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 3);
  double array2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(Matrix1 -= Matrix2);
}

TEST(matrix_tests_operator_plus, operator_plus_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  S21Matrix Matrix_act_res = Matrix1 + Matrix2;

  S21Matrix Matrix_exp_res(3, 4);
  double array3[12] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_plus, operator_plus_2) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1 + Matrix2);
}

TEST(matrix_tests_operator_plus, operator_plus_3) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(S21Matrix Matrix_act_res = Matrix1 + Matrix2;);
}

TEST(matrix_tests_operator_plus, operator_plus_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 3);
  double array2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(S21Matrix Matrix_act_res = Matrix1 + Matrix2;);
}

TEST(matrix_tests_operator_mult, operator_mult_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(4, 3);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  S21Matrix Matrix_act_res = Matrix1 * Matrix2;

  S21Matrix Matrix_exp_res(3, 3);
  double array3[12] = {70, 80, 90, 158, 184, 210, 246, 288, 330};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_mult, operator_mult_2) {
  S21Matrix Matrix1(3, 2);
  double array1[12] = {1, 4, 2, 5, 3, 6};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 3);
  double array2[12] = {1, -1, 1, 2, 3, 4};
  Matrix2.fill_matrix(array2);

  S21Matrix Matrix_act_res = Matrix1 * Matrix2;

  S21Matrix Matrix_exp_res(3, 3);
  double array3[12] = {9, 11, 17, 12, 13, 22, 15, 15, 27};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_mult, operator_mult_3) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(4, 3);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1 * Matrix2);
}

TEST(matrix_tests_operator_mult, operator_mult_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(S21Matrix Matrix_act_res = Matrix1 * Matrix2;);
}

TEST(matrix_tests_operator_mult, operator_mult_5) {
  S21Matrix Matrix1(3, 2);
  double array1[12] = {1, 4, 2, 5, 3, 6};
  Matrix1.fill_matrix(array1);

  double test_number = 1;
  S21Matrix Matrix_act_res = Matrix1 * test_number;

  S21Matrix Matrix_exp_res(3, 2);
  double array3[12] = {1, 4, 2, 5, 3, 6};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_mult, operator_mult_6) {
  S21Matrix Matrix1(3, 2);
  double array1[12] = {1, 4, 2, 5, 3, 6};
  Matrix1.fill_matrix(array1);

  double test_number = 1;

  Matrix1 *= test_number;

  S21Matrix Matrix_exp_res(3, 2);
  double array3[12] = {1, 4, 2, 5, 3, 6};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}
TEST(matrix_tests_operator_mul_matrix, operator_mul_matrix_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(4, 3);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  Matrix1 *= Matrix2;

  S21Matrix Matrix_exp_res(3, 3);
  double array3[12] = {70, 80, 90, 158, 184, 210, 246, 288, 330};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_mul_matrix, operator_mul_matrix_2) {
  S21Matrix Matrix1(3, 2);
  double array1[12] = {1, 4, 2, 5, 3, 6};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 3);
  double array2[12] = {1, -1, 1, 2, 3, 4};
  Matrix2.fill_matrix(array2);

  Matrix1 *= Matrix2;

  S21Matrix Matrix_exp_res(3, 3);
  double array3[12] = {9, 11, 17, 12, 13, 22, 15, 15, 27};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_mul_matrix, operator_mul_matrix_3) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(4, 3);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1 *= Matrix2);
}

TEST(matrix_tests_operator_mul_matrix, operator_mul_matrix_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(Matrix1 *= Matrix2;);
}

TEST(matrix_tests_operator_minus, operator_minus_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  S21Matrix Matrix_act_res = Matrix1 - Matrix2;

  S21Matrix Matrix_exp_res(3, 4);
  double array3[12] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
  Matrix_exp_res.fill_matrix(array3);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j),
                Matrix_act_res.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_minus, operator_minus_2) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_NO_THROW(Matrix1 - Matrix2);
}

TEST(matrix_tests_operator_minus, operator_minus_3) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(2, 4);
  double array2[8] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(S21Matrix Matrix_act_res = Matrix1 - Matrix2;);
}

TEST(matrix_tests_operator_minus, operator_minus_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 3);
  double array2[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix2.fill_matrix(array2);

  EXPECT_ANY_THROW(S21Matrix Matrix_act_res = Matrix1 - Matrix2;);
}

TEST(matrix_tests_operator_index, operator_index_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  Matrix1(1, 2) = 99;

  S21Matrix Matrix_exp_res(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 99, 8, 9, 10, 11, 12};
  Matrix_exp_res.fill_matrix(array2);
  for (int i = 0; i < Matrix_exp_res.GetRows(); i++) {
    for (int j = 0; j < Matrix_exp_res.GetCols(); j++) {
      EXPECT_EQ(Matrix_exp_res.GetElement(i, j), Matrix1.GetElement(i, j));
    }
  }
}

TEST(matrix_tests_operator_index, operator_index_2) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  EXPECT_NO_THROW(Matrix1(1, 2) = 99);
}

TEST(matrix_tests_operator_index, operator_index_3) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  EXPECT_ANY_THROW(Matrix1(5, 3) = 99;);
}

TEST(matrix_tests_operator_index, operator_index_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  EXPECT_ANY_THROW(Matrix1(2, 5) = 99;);
}

TEST(matrix_tests_operator_equal, operator_equal_1) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_EQ(Matrix1 == Matrix2, true);
  EXPECT_EQ(Matrix2 == Matrix1, true);
}

TEST(matrix_tests_operator_equal, operator_equal_2) {
  S21Matrix Matrix1(2, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_EQ(Matrix1 == Matrix2, false);
  EXPECT_EQ(Matrix2 == Matrix1, false);
}

TEST(matrix_tests_operator_equal, operator_equal_3) {
  S21Matrix Matrix1(3, 3);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_EQ(Matrix1 == Matrix2, false);
  EXPECT_EQ(Matrix2 == Matrix1, false);
}

TEST(matrix_tests_operator_equal, operator_equal_4) {
  S21Matrix Matrix1(3, 4);
  double array1[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 11, 12};
  Matrix1.fill_matrix(array1);

  S21Matrix Matrix2(3, 4);
  double array2[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix2.fill_matrix(array2);

  EXPECT_EQ(Matrix1 == Matrix2, false);
  EXPECT_EQ(Matrix2 == Matrix1, false);
}

TEST(matrix_tests_operator_assign, operator_assign_1) {
  S21Matrix Matrix1(3, 4);
  double array[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
  Matrix1.fill_matrix(array);

  S21Matrix Matrix2(3, 4);
  Matrix2 = Matrix1;

  EXPECT_EQ(Matrix1.GetRows(), Matrix2.GetRows());
  EXPECT_EQ(Matrix1.GetCols(), Matrix2.GetCols());
  for (int i = 0; i < Matrix1.GetRows(); i++) {
    for (int j = 0; j < Matrix1.GetCols(); j++) {
      EXPECT_EQ(Matrix1.GetElement(i, j), Matrix2.GetElement(i, j));
    }
  }
}
