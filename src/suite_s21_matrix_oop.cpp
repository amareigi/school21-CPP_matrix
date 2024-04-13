#include "test.h"

TEST(TestSetGetElem, TestGetException1) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.GetElement(1, 0));
}

TEST(TestSetGetElem, TestGetException2) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.GetElement(0, 1));
}

TEST(TestSetGetElem, TestGetException3) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.GetElement(-1, 0));
}

TEST(TestSetGetElem, TestGetException4) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.GetElement(0, -1));
}

TEST(TestSetGetElem, TestSetException1) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.SetElement(0, 1, 0));
}

TEST(TestSetGetElem, TestSetException2) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.SetElement(0, 0, 1));
}

TEST(TestSetGetElem, TestSetException3) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.SetElement(0, -1, 0));
}

TEST(TestSetGetElem, TestSetException4) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.SetElement(0, 0, -1));
}

TEST(TestSetGetElem, TestGet) {
  S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.GetElement(0, 0), 0);
}

TEST(TestSetGetElem, TestSet) {
  S21Matrix matrix_check;
  matrix_check.SetElement(10, 0, 0);
  EXPECT_EQ(matrix_check.GetElement(0, 0), 10);
}

TEST(TestCopyConstructor, Test1) {
  S21Matrix matrix_check;
  matrix_check.SetElement(10, 0, 0);
  S21Matrix matrix_check_2(matrix_check);
  EXPECT_EQ(matrix_check_2.GetElement(0, 0), 10);
}

TEST(TestMoveConstructor, Test1) {
  S21Matrix matrix_check;
  matrix_check.SetElement(10, 0, 0);
  S21Matrix matrix_check_2(std::move(matrix_check));
  EXPECT_EQ(matrix_check_2.GetElement(0, 0), 10);
}

TEST(TestConstructor, TestConstructorException1) {
  EXPECT_ANY_THROW(S21Matrix(-1, 99));
}

TEST(TestConstructor, TestConstructorException2) {
  EXPECT_ANY_THROW(S21Matrix(99, -1));
}

TEST(TestConstructor, TestConstructorParams1) {
  S21Matrix matrix_check(5, 4);
  EXPECT_EQ(matrix_check.GetRows(), 5);
  EXPECT_EQ(matrix_check.GetCols(), 4);
}

TEST(TestConstructor, TestConstructorParams2) {
  S21Matrix matrix_check;
  EXPECT_EQ(matrix_check.GetRows(), 1);
  EXPECT_EQ(matrix_check.GetCols(), 1);
}

TEST(TestConstructor, TestConstructorParams3) {
  S21Matrix matrix_check(999, 1999);
  EXPECT_EQ(matrix_check.GetRows(), 999);
  EXPECT_EQ(matrix_check.GetCols(), 1999);
}

TEST(TestSetRowCol, TestSetException1) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.SetRows(-1));
}
TEST(TestSetRowCol, TestSetException2) {
  S21Matrix matrix_check;
  EXPECT_ANY_THROW(matrix_check.SetCols(-1));
}
TEST(TestSetRowCol, TestSet1) {
  S21Matrix matrix_check;
  matrix_check.SetRows(2);
  EXPECT_EQ(matrix_check.GetRows(), 2);
  EXPECT_EQ(matrix_check.GetCols(), 1);
}
TEST(TestSetRowCol, TestSet2) {
  S21Matrix matrix_check;
  matrix_check.SetCols(2);
  EXPECT_EQ(matrix_check.GetRows(), 1);
  EXPECT_EQ(matrix_check.GetCols(), 2);
}
TEST(TestSetRowCol, TestSet3) {
  S21Matrix matrix_check;
  matrix_check.SetCols(1);
  EXPECT_EQ(matrix_check.GetRows(), 1);
  EXPECT_EQ(matrix_check.GetCols(), 1);
}
TEST(TestSetRowCol, TestSet4) {
  S21Matrix matrix_check;
  matrix_check.SetRows(1);
  EXPECT_EQ(matrix_check.GetRows(), 1);
  EXPECT_EQ(matrix_check.GetCols(), 1);
}
TEST(TestSetRowCol, TestSet5) {
  S21Matrix matrix_check(5, 5);
  matrix_check.SetRows(1);
  EXPECT_EQ(matrix_check.GetRows(), 1);
  EXPECT_EQ(matrix_check.GetCols(), 5);
}
TEST(TestSetRowCol, TestSet6) {
  S21Matrix matrix_check(5, 5);
  matrix_check.SetCols(1);
  EXPECT_EQ(matrix_check.GetRows(), 5);
  EXPECT_EQ(matrix_check.GetCols(), 1);
}
