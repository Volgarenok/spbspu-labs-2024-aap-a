#include "matrix.hpp"
#include <iostream>

Matrix::Matrix()
{
  rows_ = 0;
  cols_ = 0;
  data_ = nullptr;
}

Matrix::Matrix(size_t rows, size_t cols)
{
  create(rows, cols);
}

Matrix::~Matrix()
{
  clear();
}

size_t Matrix::get_rows() const
{
  return rows_;
}

size_t Matrix::get_cols() const
{
  return cols_;
}

int Matrix::get_elem(size_t row, size_t col) const
{
  return data_[cols_ * row + col];
}

void Matrix::put_elem(size_t row, size_t col, int value)
{
  data_[cols_ * row + col] = value;
}

void Matrix::resize(size_t new_rows, size_t new_cols)
{
  clear();
  create(new_rows, new_cols);
}

void Matrix::out() const
{
  for (size_t i = 0; i < rows_; i++)
  {
    for (size_t j = 0; j < cols_; j++)
    {
      std::cout << get_elem(i, j) << " ";
    }
    std::cout << "\n";
  }
}

void Matrix::create(size_t rows, size_t cols)
{
  rows_ = rows;
  cols_ = cols;
  try
  {
    data_ = new int[rows_ * cols_];
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << '\n';
    throw;
  }
}

void Matrix::clear()
{
  if (data_ != nullptr)
  {
    delete[] data_;
    data_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}
