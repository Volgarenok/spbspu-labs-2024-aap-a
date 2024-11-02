#ifndef READING_FILES
#define READING_FILES
#include <cstddef>
namespace alymova
{
  int check_num(char* argv1);
  void check_argc(int argc);
  std::istream& input_matrix(std::istream& input, int* matrix, size_t& rows, size_t& cols, size_t& read);
  void print_matrix(std::ostream& output, int* matrix, size_t rows, size_t cols);
}
#endif
