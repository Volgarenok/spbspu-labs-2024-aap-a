#ifndef MATRIXHANDLING_H
#define MATRIXHANDLING_H
#include <cstddef>
namespace asafov
{
  void handle_lft_top_clk(int*& mtx, const unsigned long long n, const unsigned long long m);
  int handle_num_col_lsr(const int* mtx, const unsigned long long n, const unsigned long long m);
  /*название этих функций пишу через нижнее подчеркивание потому, что
  handleNumColLsr, handleNum_col_lsr - выглядят плохо,
  а просто num_col_lsr выглядит непонятно,
  как впрочем и первые два варианта,
  убирать сокращение и писать верблюдиком будет очень длинно,
  поэтому так*/
}
#endif
