#include "min_sum_mdg.hpp"

#include <algorithm>
#include <limits>

int calc_min_sum_mdg(const int* matrix, size_t rows, size_t cols)
{
  const int* start_elem = matrix;
  size_t anti_diagonal_n = std::min(rows, cols);
  int min_sum = std::numeric_limits<int>::max();
  for (size_t i = 0; i < cols; i++, start_elem++) {
    if (i == anti_diagonal_n - 1) {
      continue;
    }
    size_t sum_count = (i < anti_diagonal_n - 1) ? i + 1 : anti_diagonal_n;
    const int* current_elem = start_elem;
    int sum = 0;
    while (sum_count-- > 0) {
      sum += *current_elem;
      current_elem += (cols - 1);
    }
    if (sum < min_sum) {
      min_sum = sum;
    }
  }
  start_elem += (cols - 1);
  for (size_t i = 1; i < rows; i++, start_elem += cols) {
    size_t sum_count = (i > rows - anti_diagonal_n) ? rows - i : anti_diagonal_n;
    const int* current_elem = start_elem;
    int sum = 0;
    while (sum_count-- > 0) {
      sum += *current_elem;
      current_elem += (cols - 1);
    }
    if (sum < min_sum) {
      min_sum = sum;
    }
  }
  return min_sum;
}
