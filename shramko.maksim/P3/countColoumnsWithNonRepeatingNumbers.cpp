#include "countColoumnsWithNonRepeatingNumbers.hpp"
#include "isNonRepeatingNumbers.hpp"

size_t shramko::countColoumnsWithNonRepeatingNumbers(const int* mtrx, const size_t cnt_row, const size_t cnt_col)
{
  size_t answer = 0;
  for (size_t i = 0; i < cnt_col; ++i)
  {
    if (!(shramko::isNonRepeatingNumbers(mtrx, i, cnt_col, cnt_row)))
    {
      break;
    }
    else
    {
      ++answer;
    }
  }
  return answer;
}
