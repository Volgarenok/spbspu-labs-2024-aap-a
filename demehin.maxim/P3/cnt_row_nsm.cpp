#include "cnt_row_nsm.h"
#include <cstddef>

int demehin::cnt_row_nsm(int* t, size_t m, size_t n)
{
  size_t k = n * m;
  int l = 0;
  int count = 0;
  for (size_t i = 0; i < k; i += n)
  {
    l = 0;
    for (size_t j = i; j < i + n - 1; ++j)
    {
      if(t[j] == t[j + 1])
      {
        l += 1;
        break;
      }
    }
    if (l == 0)
    {
      count += 1;
    }
  }
  return count;
}
