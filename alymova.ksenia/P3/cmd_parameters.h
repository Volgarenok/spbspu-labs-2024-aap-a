#ifndef READING_FILES
#define READING_FILES
#include <cstddef>
#include <istream>
namespace alymova
{
  int check_num(const char* const argv1);
  void check_argc(int argc);
  std::istream& input_matrix(std::istream& input, int* const matrix, size_t& rows, size_t& cols, size_t& read);
  std::istream& input_size(std::istream& input, size_t& rows, size_t& cols);
  void print_matrix(std::ostream& output, const int* const matrix, size_t rows, size_t cols);
}
#endif
