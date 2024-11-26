#include "cnt_nzr_dig.hpp"

std::istream &sveshnikov::read_matrix(std::istream &in, int *matrix, size_t num_rows, size_t num_columns, size_t &read)
{
  for (size_t i = 0; i < num_rows * num_columns; i++)
  {
    in >> matrix[read];
    read++;
  }
  return in;
}
