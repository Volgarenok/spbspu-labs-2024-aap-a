#ifndef CNT_NZR_DIG_HPP
#define CNT_NZR_DIG_HPP
#include <iostream>
#include <fstream>
namespace sveshnikov
{
  std::istream & read_matrix(std::istream &in, int *matrix, size_t num_rows, size_t num_columns, size_t & read);
  void write_matrix(std::ostream &out);
  int cnt_nzr_dig();
}
#endif