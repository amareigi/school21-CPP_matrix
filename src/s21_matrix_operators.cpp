#include "s21_matrix_oop.h"

void S21Matrix::operator+=(const S21Matrix &other) { SumMatrix(other); }

void S21Matrix::operator-=(const S21Matrix &other) { SubMatrix(other); }

S21Matrix S21Matrix::operator+(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

void S21Matrix::operator*=(const S21Matrix &other) { MulMatrix(other); }

void S21Matrix::operator*=(const double num) { MulNumber(num); }

S21Matrix S21Matrix::operator-(const S21Matrix &other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

double &S21Matrix::operator()(int i, int j) {
  if (i > rows_ - 1 || j > cols_ - 1 || i < 0 || j < 0)
    throw "Element is out of range";
  return matrix_[i][j];
}

bool S21Matrix::operator==(const S21Matrix &other) { return EqMatrix(other); }

void S21Matrix::operator=(const S21Matrix &other) {
  DeAllocate();
  cols_ = other.GetCols();
  rows_ = other.GetRows();
  Allocate();
  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++) SetElement(other.GetElement(i, j), i, j);
}
