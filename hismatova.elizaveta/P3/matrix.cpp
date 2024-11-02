#include "matrix.h"
#include <iostream>

hismatova::std::istream & input_matrix(std::istream & in, int * matrix, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < (m * n); ++i) 
  {
    in >> matrix[i];
    ++read;
  }
  return in;
}
void output_matrix(std::ostream & out, int * matrix, size_t m, size_t n)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    out << matrix[i] << " ";
  }
}
int find_longest(int * matrix, int size) 
{
  
}

