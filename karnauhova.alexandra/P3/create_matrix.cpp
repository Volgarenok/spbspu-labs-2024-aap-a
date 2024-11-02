#include "create_matrix.hpp"
#include <cctype>
#include <new>

int* karnauhova::ct_matrix(size_t m,size_t n){
    int* matrix2 = nullptr;
    try
    {
      matrix2 = new int[m*n];
    }
    catch(const std::bad_alloc &e)
    {
      delete[] matrix2;
      throw;
    }
    return matrix2;
}
