#ifndef FILEIO_HPP
#define FILEIO_HPP

namespace belobrov
{
  void loadMatrix(std::istream& in, int *matrix, size_t rows, size_t cols);
  void saveMatrix(const std::string& filename, const int *matrix, size_t rows, size_t cols);
}

#endif
