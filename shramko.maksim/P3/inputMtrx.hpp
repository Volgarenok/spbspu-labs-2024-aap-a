#ifndef INPUTMTRX_HPP
#define INPUTMTRX_HPP

#include <iostream>

namespace shramko
{
  std::istream & inputMtrx(std::istream & in, int* mtrx, size_t cnt_row, size_t cnt_col, int& read);
}

#endif
