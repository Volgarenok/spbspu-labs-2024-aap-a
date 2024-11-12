#include "output_matrix.h"
#include <iostream>


void timofeev::check_diag(std::ostream& out, int* matrix, size_t strk, size_t stl)
{
  size_t sum_dig = strk + stl - 1;
  size_t sum_el = (strk * stl) + ((stl - 1) * stl);
  std::string* values = nullptr;
  try
  {
    values = new std::string[sum_dig]{"0"};
  }
  catch(const std::bad_alloc& e)
  {
    delete[] values;
    std::cerr << "Out of memory\n";
  }
  char* new_matrix = nullptr;
  try
  {
    new_matrix = new char[sum_el];
  }
  catch (const std::bad_alloc& e)
  {
    delete[] new_matrix;
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
  delete[] new_matrix;
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
  delete[] values;
  if (mtr > 0)
  {
    out << "the matrix contains diagonals with equal values\n";
  }
  else
  {
    out << "the matrix doesn't contains diagonals with equal values\n";
  }
}
