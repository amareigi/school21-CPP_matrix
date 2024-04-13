#include "s21_matrix_oop.h"

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.GetRows() || cols_ != other.GetCols())
    throw "No way to sum matrix";
  for (int row = 0; row < rows_; row++)
    for (int col = 0; col < cols_; col++)
      matrix_[row][col] += other.GetElement(row, col);
}
