#include "titleMatrix.h"
#include <iostream>
#include <limits>
#include <cstring>

void duhanina::outputAnswer(std::ostream & out, int * t, size_t m, size_t n)
{
  int max_count_diag = m + n - 1;
  int * sums = new int[max_count_diag];
  int * diag_count = new int[max_count_diag];
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      int index_diag = j - (m - i - 1);
      sums[index_diag] += t[i * n + j];
      diag_count[index_diag]++;
    }
  }
  int min_sum = std::numeric_limits<int>::max();
  for (int i = 0; i < max_count_diag; ++i)
  {
    if (diag_count[i] > 0 && sums[i] < min_sum)
    {
      min_sum = sums[i];
    }
  }
  out << min_sum << "\n";
}
