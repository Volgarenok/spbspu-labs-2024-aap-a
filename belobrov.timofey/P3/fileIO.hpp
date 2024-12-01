#ifndef FILEIO_HPP
#define FILEIO_HPP

#include <cstddef>
#include <string>
#include <istream>

namespace belobrov
{
  void loadMatrix(std::istream& in, int *matrix, size_t rows, size_t cols);
  void saveMatrix(const std::string& filename, const int *matrix, size_t rows, size_t cols);
}

#endif
