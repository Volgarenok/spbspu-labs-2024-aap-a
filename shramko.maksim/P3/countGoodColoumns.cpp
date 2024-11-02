#include "countGoodColoumns.hpp"

size_t shramko::countGoodColoumns(const int* mtrx, size_t cnt_row, size_t cnt_col)
{
  size_t answer = 0;
  for (size_t i = 1; i < cnt_col; ++i)
  {
    bool breakPoint = true;
    for (size_t j = 1; j < cnt_row; ++j)
    {
      if (mtrx[j - 1 * cnt_col + i] == mtrx[j * cnt_col + i])
      {
        breakPoint = false;
        break;
      }
    }
    if (breakPoint = true)
    {
      ++answer;
    }
  }
  return answer;
}
