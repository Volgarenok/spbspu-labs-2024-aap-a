#ifndef GETLINE_HPP
#define GETLINE_HPP
#include <cstddef>
#include <fstream>

namespace lebedev
{
  char* getLine(std::istream& in, size_t& capacity, char endChar);
}
#endif
