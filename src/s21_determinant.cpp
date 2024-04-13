#include "s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (rows_ != cols_) throw "Matrix is not square";
  S21Matrix Matrix_copy(*this);
  int sign = 1;
  double result = 1.0;
  // метод гауса определитель
  for (int rows = 0; rows < Matrix_copy.rows_ - 1 && result; rows++) {
    int has_num = 0, zero_column = 1;
    double *no_zero_pointer = NULL;
    for (has_num = rows, zero_column = 1; has_num < Matrix_copy.rows_;
         has_num++) {
      if (Matrix_copy
              .matrix_[has_num][rows]) {  // проверяем проходя вниз по столбцу
        no_zero_pointer =
            Matrix_copy.matrix_[has_num];  // адрес строки с ненулевым элементом
        zero_column = 0;
        break;
      }
    }
    // если элемент диагонали равен нулю и есть ненулевой элемент в другой
    // строке в этом столбце
    if (Matrix_copy.matrix_[rows][rows] == 0.0 && no_zero_pointer != NULL) {
      Matrix_copy.matrix_[has_num] =
          Matrix_copy.matrix_[rows];  // меняем строки местами
      Matrix_copy.matrix_[rows] = no_zero_pointer;
      sign = -sign;  // меняется знак оперделителя если меняем строки местами
    }

    if (zero_column) {  // если все нули в столбце, опеределитель 0
      result = 0.0;
    } else {
      for (int i = rows + 1; i < Matrix_copy.rows_;
           i++) {  // изменяем строку, где вставляем ноль
        double k =
            Matrix_copy.matrix_[i][rows] / Matrix_copy.matrix_[rows][rows];
        for (int j = rows; j < Matrix_copy.cols_; j++)
          Matrix_copy.matrix_[i][j] -= Matrix_copy.matrix_[rows][j] * k;
      }
    }
  }
  for (int i = 0; i < rows_; i++) result *= Matrix_copy.matrix_[i][i];
  result *= sign;
  return result;
}
