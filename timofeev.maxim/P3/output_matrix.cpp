#include "output_matrix.h"

int timofeev::check_diag(const int* matrix, size_t size)
{
  const size_t move = size - 1;
  size_t diag = size;
  for (size_t i = 1; i < size; i++)
  {
    diag--;
    size_t left_in_diag = diag;
    size_t check_el = i;
    size_t fine_check = 0;
    while (left_in_diag > 0)
    {
      if (matrix[check_el] == matrix[(check_el + (move * i))])
      {
        check_el += size + 1;
        fine_check++;
      }
      left_in_diag--;
    }
    if (fine_check == diag)
    {
      return 1;
    }
  }
  return 0;
}
