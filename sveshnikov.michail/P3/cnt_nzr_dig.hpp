#ifndef CNT_NZR_DIG_HPP
#define CNT_NZR_DIG_HPP
#include <iostream>
#include <fstream>
namespace sveshnikov
{
  void read_matrix(std::istream &in, int *matrix, constexpr size_t len);
  void write_matrix(std::ostream &out);
  int cnt_nzr_dig();
}
#endif