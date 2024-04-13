#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(1), cols_(1) { Allocate(); }

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows_ <= 0 || cols_ <= 0) throw "wrong matrix size";
  Allocate();
}

S21Matrix::S21Matrix(const S21Matrix &other) {
  rows_ = other.GetRows();
  cols_ = other.GetCols();
  Allocate();
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) matrix_[i][j] = other.matrix_[i][j];
}

S21Matrix::S21Matrix(S21Matrix &&other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;

  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { DeAllocate(); }

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0) throw "matrix rows must be > 0";

  if (rows != rows_) {
    int old_cols = cols_;
    int min = rows > rows_ ? rows_ : rows;
    S21Matrix tmp{rows_, cols_};

    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) tmp.matrix_[i][j] = matrix_[i][j];

    DeAllocate();
    rows_ = rows;
    cols_ = old_cols;
    Allocate();

    for (int i = 0; i < min; ++i)
      for (int j = 0; j < cols_; ++j) tmp.matrix_[i][j] = matrix_[i][j];
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0) throw "matrix cols must be > 0";

  if (cols != cols_) {
    int old_rows = rows_;
    int min = cols > cols_ ? cols_ : cols;
    S21Matrix tmp{rows_, cols_};

    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < cols_; ++j) tmp.matrix_[i][j] = matrix_[i][j];

    DeAllocate();
    rows_ = old_rows;
    cols_ = cols;
    Allocate();

    for (int i = 0; i < rows_; ++i)
      for (int j = 0; j < min; ++j) tmp.matrix_[i][j] = matrix_[i][j];
  }
}

double S21Matrix::GetElement(int rows, int cols) const {
  if (rows > rows_ - 1 || cols > cols_ - 1 || rows < 0 || cols < 0)
    throw "Element is out of range";
  return matrix_[rows][cols];
}

void S21Matrix::SetElement(double value, int rows, int cols) {
  if (rows > rows_ - 1 || cols > cols_ - 1 || rows < 0 || cols < 0)
    throw "Element is out of range";
  matrix_[rows][cols] = value;
}

void S21Matrix::fill_matrix(double const array[]) {
  int k = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = array[k];
      k++;
    }
  }
}

void S21Matrix::Allocate() {
  matrix_ = (double **)malloc(rows_ * sizeof(double *));
  if (matrix_ == nullptr) throw "matrix_ allocate problem";
  for (int row = 0; row < rows_; row++) {
    matrix_[row] = (double *)malloc(cols_ * sizeof(double));
    if (matrix_[row] == nullptr) {
      DeAllocate();
      throw "matrix_[row] allocate problem";
    }
  }
  FillZero();
}

void S21Matrix::DeAllocate() {
  if (matrix_ != nullptr && rows_ > 0) {
    for (int row = 0; row < rows_; row++)
      if (matrix_[row] != nullptr) free(matrix_[row]);
    free(matrix_);
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

void S21Matrix::FillZero() {
  for (int row = 0; row < rows_; row++)
    for (int col = 0; col < cols_; col++) matrix_[row][col] = 0;
}
