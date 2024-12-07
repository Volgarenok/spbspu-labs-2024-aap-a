#include "mtx_work.hpp"
#include <iostream>

std::istream & zakirov::input_mtx(std::istream & in, int * mtx, size_t columns, size_t rows)
{
  for (size_t i = 0; i < columns * rows; ++i)
  {
    in >> mtx[i];
  }
  return in;
}

void zakirov::mtx_spiral_decrease(int * mtx, size_t columns, size_t rows)
{
  int subtrahend = 1;
  size_t columns_step = columns - 1;
  size_t rows_step = rows - 1;
  size_t location = columns * 2;
  for (size_t i = 0; i != columns_step; ++i)
  {
    mtx[location] = mtx[location] - subtrahend;
    subtrahend += 1;
    location -= columns;
  }

  while (columns_step > 0 || rows_step > 0)
  {
    for (size_t i = 0; i != rows_step; ++i)
    {
      mtx[location] = mtx[location] - subtrahend;
      subtrahend += 1;
      location += 1;
    }
    rows_step -= 1;
    for (size_t i = 0; i != columns_step; ++i)
    {
      mtx[location] = mtx[location] - subtrahend;
      subtrahend += 1;
      location += columns;
    }
    columns_step -= 1;
    for (size_t i = 0; i != rows_step; ++i)
    {
      mtx[location] = mtx[location] - subtrahend;
      subtrahend += 1;
      location -= 1;
    }
    rows_step -= 1;
    for (size_t i = 0; i != columns_step; ++i)
    {
      mtx[location] = mtx[location] - subtrahend;
      subtrahend += 1;
      location -= columns;
    }
    columns_step -= 1;
  }
}

void zakirov::output_mtx(std::ostream & out, int const * mtx, size_t columns, size_t rows)
{
  for (size_t i = 0; i < columns * rows; i += rows)
  {
    out << mtx[i];
    for (size_t j = (i + 1); j < i + columns; ++j)
    {
      out << ' ' << mtx[j];
    }
    out << '\n';
  }
}
