#include "output_matrix.h"
#include <iostream>


void timofeev::check_diag(std::ostream& out, int* matrix, size_t strk, size_t stl)
{
  size_t sum_dig = strk + stl - 1;
  size_t sum_el = (strk * stl) + ((stl - 1) * stl);
  int* values = make_array(sum_el)
  size_t count = 0;
  for (size_t i = 0; i < (strk + stl - 1); i++)
  {
    size_t col = 0;
    int icur = i;
    int diag = 0;
    for (size_t j = (stl - 1); (col <= i) && (col < stl); j--)
    {
      int jcur = j;
      if (icur * stl + jcur < (strk * stl))
      {
        values[count] = matrix[(icur * stl + jcur)];
        count++;
      }
      icur--;
      jcur--;
      col++;
    }
  }
  size_t mtr = 0;
  for (size_t i = 0; i < count; i++)
  {
    for (size_t j = 0; j < count && j != i; j++)
    {
      if (values[i] == values[j])
      {
        mtr += 1;
      }
    }
  }
  free(values);
  if (mtr > 0)
  {
    out << "the matrix contains diagonals with equal values\n";
  }
  else
  {
    out << "the matrix doesn't contains diagonals with equal values\n";
  }
}
