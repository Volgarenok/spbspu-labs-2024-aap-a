#include "min_sum_mdg.hpp"
#include <limits>

void zholobov::read_matrix(std::istream& input_stream, int* matrix, size_t elements_to_read)
{
  while (elements_to_read-- != 0) {
    input_stream >> *matrix++;
    if (!input_stream) {
      throw std::runtime_error("Error occured when reading matrix data");
    }
  }
}

static void calc_diag_elem_sum(const int* start_elem, size_t matrix_width, size_t elem_number, int& min_sum)
{
  int sum = 0;
  const int* current_elem = start_elem;
  while (elem_number-- > 0) {
    sum += *current_elem;
    current_elem += (matrix_width - 1);
  }
  if (sum < min_sum) {
    min_sum = sum;
  }
}

int zholobov::calc_min_sum_mdg(const int* matrix, size_t rows, size_t cols)
{
  const int* start_elem = matrix;
  size_t anti_diagonal_n = std::min(rows, cols);
  int min_sum = std::numeric_limits< int >::max();
  for (size_t i = 0; i < cols; i++, start_elem++) {
    if (i == anti_diagonal_n - 1) {
      continue;
    }
    size_t sum_count = (i < anti_diagonal_n - 1) ? i + 1 : anti_diagonal_n;
    calc_diag_elem_sum(start_elem, cols, sum_count, min_sum);
  }
  start_elem += (cols - 1);
  for (size_t i = 1; i < rows; i++, start_elem += cols) {
    size_t sum_count = (i > rows - anti_diagonal_n) ? rows - i : anti_diagonal_n;
    calc_diag_elem_sum(start_elem, cols, sum_count, min_sum);
  }
  return min_sum;
}
