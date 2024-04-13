#include "s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool res = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) res = false;
  for (int row = 0; row < rows_ && res; row++)
    for (int col = 0; col < cols_ && res; col++)
      if (fabs(matrix_[row][col] - other.matrix_[row][col]) >= 1.0E-7)
        res = false;
  return res;
}
