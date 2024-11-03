#ifndef MATRIX_H
#define MATRIX_H
#include <cstddef>
namespace alymova
{
  int* create_dynamic(size_t rows, size_t cols);
  void create_static(int* matrix);
  void destroy(int* matrix);
  void change_matrix(int* const matrix, size_t rows, size_t cols);
}
#endif
