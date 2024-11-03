#ifndef MATRIX_HPP
#define MATRIX_HPP
namespace brevnov 
{
  void input_matrix(std::istream & in, int * t, size_t m, size_t n);
  int ** alloc(size_t m, size_t n);
  int osed_fun(const int * t, size_t m, size_t n);
  brevnov::find_index_min(const int * t, size_t n, size_t);
}
#endif