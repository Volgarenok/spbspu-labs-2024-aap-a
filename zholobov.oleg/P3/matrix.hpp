#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <cstddef>

class Matrix
{
  size_t rows_;
  size_t cols_;
  int *data_;

public:
  Matrix();
  Matrix(size_t rows, size_t cols);
  ~Matrix();

  size_t get_rows() const;
  size_t get_cols() const;
  int get_elem(size_t row, size_t col) const;
  void put_elem(size_t row, size_t col, int value);
  void resize(size_t new_rows, size_t new_cols);
  void out() const;

private:
  void create(size_t rows, size_t cols);
  void clear();
};

#endif
