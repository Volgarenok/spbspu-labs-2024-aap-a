#include "cnt_row_nsm.h"
#include <cstddef>

int demehin::cnt_row_nsm(const int* t, const size_t m, const size_t n)
{
  size_t k = n * m;
  if (k == 0)
  {
    return 0;
  }
  int count = 0;
  for (size_t i = 0; i < k - n + 1; i += n)
  {
    bool isEqual = false;
    for (size_t j = i; j < i + n - 1; ++j)
    {
      if (t[j] == t[j + 1])
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
