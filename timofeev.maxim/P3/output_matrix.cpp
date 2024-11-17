#include "output_matrix.h"
#include "make_array.h"
#include <iostream>


void timofeev::check_diag(std::ostream& out, int* matrix, size_t strk, size_t stl)
{
  int sum_el = (strk * stl);
  int* values = make_array(sum_el);
  size_t count = 0;
  size_t max_short_diag = 0;
  size_t max_diag = 0;
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
    max_short_diag = col - 1;
    max_diag = col;
  }
  int hip = 0;
  size_t fine_check = 0;
  while (hip < max_short_diag)
  {
    int match = 0;
    for (size_t i = 0; i < hip + 1; i++)
    {
      if (values[(hip * (hip + 1)) / 2 + i] == values[sum_el - 1 - ((hip * (hip + 1)) / 2) - hip + i])
      {
        match++;
      }
    }
    if (match == hip + 1)
    {
      fine_check += 1;
    }
    hip++;
  }
  for (size_t i = max_diag * (max_diag - 1) / 2; i < sum_el - (max_diag * (max_diag + 1) / 2) - 1; i += 3)
  {
    for (size_t j = i + max_diag; j < sum_el - (max_diag * (max_diag - 1) / 2) - 1; j += 3)
    {
      size_t k = 0;
      size_t same_el = 0;
      while (k < max_diag)
      {
        if (values[i + k] == values[j + k])
        {
          same_el += 1;
        }
        k++;
      }
      if (same_el == max_diag)
      {
        fine_check += 1;
      }
    }
  }
  delete[] values;Fix them up in the work tree, and then use 'git add/rm <file>'
hint: as appropriate to mark resolution and make a commit.
  if (fine_check > 0)
  {
    std::cout << "the matrix contains diagonals with equal values\n";
  }
  else
  {
    std::cout << "the matrix doesn't contains diagonals with equal values\n";
  }
}
