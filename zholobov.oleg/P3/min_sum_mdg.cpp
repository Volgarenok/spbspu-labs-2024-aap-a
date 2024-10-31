#include <limits>
#include <algorithm>
#include "min_sum_mdg.hpp"
#include "matrix.hpp"

int calc_min_sum_mdg(const Matrix &m)
{
  size_t anti_diagonal_n = std::min(m.get_rows(), m.get_cols());
  int min_sum = std::numeric_limits<int>::max();
  for (size_t i = 0; i < m.get_cols(); i++)
  {
    if (i == anti_diagonal_n - 1)
    {
      continue;
    }
    size_t row = 0;
    size_t col = i;
    int sum = 0;
    do
    {
      sum += m.get_elem(row, col);
    } while ((row++ < m.get_rows() - 1) && (col-- > 0));
    if (sum < min_sum)
    {
      min_sum = sum;
    }
  }
  for (size_t i = 1; i < m.get_rows(); i++)
  {
    size_t row = i;
    size_t col = m.get_cols() - 1;
    int sum = 0;
    do
    {
      sum += m.get_elem(row, col);
    } while ((row++ < m.get_rows() - 1) && (col-- > 0));
    if (sum < min_sum)
    {
      min_sum = sum;
    }
  }
  return min_sum;
}
