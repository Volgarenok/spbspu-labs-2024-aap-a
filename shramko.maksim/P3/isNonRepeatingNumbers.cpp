#include "isNonRepeatingNumbers.hpp"

bool shramko::isNonRepeatingNumbers(const int* mtrx, size_t i, size_t cnt_col, size_t cnt_row)
{
  bool is_non_repeating = true;
  for (size_t j = 1; j < cnt_row; ++j)
  {
    if (mtrx[(j - 1) * cnt_col + i] == mtrx[j * cnt_col + i])
    {
      is_non_repeating = false;
    }
  }
  return is_non_repeating;
}
