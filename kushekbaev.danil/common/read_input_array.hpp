#ifndef READ_INPUT_ARRAY_HPP
#define READ_INPUT_ARRAY_HPP
#include <cstddef>
#include <istream>

namespace kushekbaev
{
  char* readInputArray(std::istream& input, const char* stop, size_t& size, size_t& max);
}
#endif
