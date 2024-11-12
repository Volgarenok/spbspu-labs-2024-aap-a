#include "output_matrix.h"
#include <iostream>


void timofeev::check_diag(std::ostream& out, int* matrix, size_t strk, size_t stl)
{
  std::string* values = new std::string[strk + stl - 1];
  char* new_matrix = nullptr;
  try
  {
    new_matrix = new char[(strk * stl) + ((stl - 1) * stl)];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
  }
  for (size_t i = 0; i < strk * stl; i++)
  {
    new_matrix[i] = matrix[i + 2];
  }
  size_t count = 0;
  for (size_t i = 0; i < (strk + stl - 1); i++)
  {
    size_t col = 0;
    int icur = i;
    std::string diag;
    for (size_t j = (stl -1); (col <= i) && (col < stl); j--)
    {
      int jcur = j;
      if (icur * stl + jcur < (strk * stl))
      {
        char di_el = static_cast<char>(new_matrix[(icur * stl) + jcur]);
        diag += di_el;
      }
      icur--;
      jcur--;
      col++;
    }
    values[count] = diag;
    count++;
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
  if (mtr > 0)
  {
    out << "the matrix contains diagonals with equal values\n";
  }
  else
  {
    out << "the matrix doesn't contains diagonals with equal values\n";
  }
}
