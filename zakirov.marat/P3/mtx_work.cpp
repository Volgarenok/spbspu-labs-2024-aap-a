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

void zakirov::transform_mtx(int * mtx, size_t columns, size_t rows)
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

void zakirov::output_mtx(std::ostream & out, int * mtx, size_t columns, size_t rows)
{
  out << mtx[0] << " ";
  for (size_t i = 1; i < columns*rows; ++ i)
  {
    if (i % rows == 0)
    {
      out << mtx[i] << "\n";
    }
    else
    {
      out << mtx[i] << " ";
    }
  }
  out << "\n";
}
