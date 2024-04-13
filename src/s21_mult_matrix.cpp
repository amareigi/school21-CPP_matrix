#include "s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (rows_ != other.GetCols()) throw "Can`t mult this matrixs";
  S21Matrix Matrix_copy(*this);

  int new_rows = rows_;
  int new_cols = other.GetCols();
  DeAllocate();
  rows_ = new_rows;
  cols_ = new_cols;
  Allocate();

  for (int i = 0; i < rows_; i++)
    for (int j = 0; j < cols_; j++)
      for (int k = 0; k < other.GetRows(); k++)
        matrix_[i][j] += Matrix_copy.GetElement(i, k) * other.GetElement(k, j);
}
