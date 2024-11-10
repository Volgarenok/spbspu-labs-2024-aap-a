#ifndef INPUTMTRX_HPP
#define INPUTMTRX_HPP

#include <iostream>

namespace shramko
{
  std::istream & inputMtrx(std::istream & in, int* mtrx, size_t sizeMtrx, size_t& read_count);
}

#endif
