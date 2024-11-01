#include "checkMatrix.hpp"

dribas::checkmatrix(int const* matrix, size_t size)
{
  if (matrix[size-1] == 0) {
    for (size_t i = 0; i < size; i+=1) {
      for (size_t j = 0; j < size; j+=1) {
        if (matrix[i * size + j] != 0){
          check+=1;
          if (check > i+1){
            return false;
          }
        }
      }
    }
  } else if (matrix[0] == 0) {

  }

  return false;

}
