#include <limits>
#include <algorithm>
#include <cstring>
#include "titleMatrix.h"

int duhanina::outputAnswer(int * t, size_t m, size_t n)
{
  int n_int = static_cast<int>(n);
  size_t max_count_diag = m + n - 1;
  int min_sum = std::numeric_limits<int>::max();
  for (size_t sum = 0; sum < max_count_diag; ++sum)
  {
    int current_sum = 0;
    for (size_t i = 0; i < m; ++i)
    {
      int j = sum - i;
      if (j >= 0 && j < n_int)
      {
        current_sum += t[i * n + j];
      }
    }
    min_sum = std::min(min_sum, current_sum);
  }
  return min_sum;
}
