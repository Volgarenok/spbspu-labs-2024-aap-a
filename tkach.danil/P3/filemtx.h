#ifndef INPUTMTX_H
#define INPUTMTX_H

#include <cstddef>
#include <fstream>

namespace tkach 
{
  std::istream & inputMtx(std::istream & in, int* mtx1, size_t str);
}

#endif