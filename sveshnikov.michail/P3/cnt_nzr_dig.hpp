#ifndef CNT_NZR_DIG_HPP
#define CNT_NZR_DIG_HPP
#include <cstddef>
#include <fstream>
namespace sveshnikov
{
  std::istream &read_matrix(std::istream &in, int *matrix, size_t num_rows, size_t num_columns, size_t &read);
  size_t cnt_nzr_dig(const int *matrix, size_t num_rows, size_t num_columns);
}
#endif
