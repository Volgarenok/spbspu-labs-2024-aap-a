#include "countGoodColoumns.hpp"

size_t shramko::countGoodColoumns(const int* mtrx, size_t count_rows, size_t count_coloumns)
{
  size_t answer = 0;
  for (size_t i = 1; i < count_coloumns; ++i)
  {
    bool breakPoint = true;
    for (size_t j = 1; j < count_rows; ++j)
    {
      if (mtrx[j - 1 * count_coloumns + i] == mtrx[j * count_coloumns + i])
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
