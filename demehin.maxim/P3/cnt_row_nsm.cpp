#include "cnt_row_nsm.h"
#include <cstddef>

int demehin::cnt_row_nsm(int* t, size_t m, size_t n)
{
  size_t k = n * m;
  int count = 0;
  for (size_t i = 0; i < k - n + 1; i += n)
  {
    bool isEqual = false;
    for (size_t j = i; j < i + n - 1; ++j)
    {
      if(t[j] == t[j + 1])
      {
        isEqual = true;
        break;
      }
    }
    if (!isEqual)
    {
      count += 1;
    }
  }
  return count;
}
