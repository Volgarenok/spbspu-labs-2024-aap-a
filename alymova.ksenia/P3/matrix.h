#ifndef MATRIX_H
#define MATRIX_H
namespace alymova
{
  int* create_dynamic(size_t rows, size_t cols);
  int* create_static(size_t rows, size_t cols);
  void destroy(int* matrix);
  void change_matrix(int* const matrix, size_t rows, size_t cols);
}
#endif
