#include "mtx_work.hpp"

std::istream & zakirov::input_mtx(std::istream & in, int * mtx, size_t columns, size_t rows)
{
  for (size_t i = 0; i < columns*rows; ++i)
  {
    in >> mtx[i];
  }
  return in;
}

int * transform_mtx(int const * base_mtx, int * new_mtx, size_t columns, size_t rows)
{
  int subtrahend = 1;
  size_t columns_step = columns - 1;
  size_t rows_step = rows - 1;
  size_t location = columns * 2;
  for (size_t i = 0; i != columns_step; ++i)
    {
      new_mtx[location] = base_mtx[location] - subtrahend;
      subtrahend += 1;
      location -= columns;
    }

  while (columns_step > 0 || rows_step > 0)
  {
    for (size_t i = 0; i != rows_step; ++i)
    {
      new_mtx[location] = base_mtx[location] - subtrahend;
      subtrahend += 1;
      location += 1;
    }
    rows_step -= 1;
    for (size_t i = 0; i != columns_step; ++i)
    {
      new_mtx[location] = base_mtx[location] - subtrahend;
      subtrahend += 1;
      location += columns;
    }
    columns_step -= 1;
    for (size_t i = 0; i != rows_step; ++i)
    {
      new_mtx[location] = base_mtx[location] - subtrahend;
      subtrahend += 1;
      location -= 1;
    }
    rows_step -= 1;
    for (size_t i = 0; i != columns_step; ++i)
    {
      new_mtx[location] = base_mtx[location] - subtrahend;
      subtrahend += 1;
      location -= columns;
    }
    columns_step -= 1;
  }

  return new_mtx;
}
