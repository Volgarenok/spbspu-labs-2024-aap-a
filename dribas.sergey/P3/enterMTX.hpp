#ifndef ENTERMTX_HPP
#define ENTERMTX_HPP
#include <fstream>

namespace dribas
{
  std::istream & enterMTX(std::istream & in, int* mtx, size_t M, size_t N, size_t& readed);
}

#endif
