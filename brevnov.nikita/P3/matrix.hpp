#ifndef MATRIX_HPP
#define MATRIX_HPP
namespace brevnov 
{
  void input_matrix(std::istream & in, int ** t, size_t m, size_t n);
  int ** alloc(size_t m, size_t n);
}
#endif