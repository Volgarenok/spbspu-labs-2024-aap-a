#include "cleanup.h"
namepace lungu {
  void cleanup(int** matrix, int rows) {
      if (matrix) {
          for (int i = 0; i < rows; ++i) {
              delete[] matrix[i];
          }
          delete[] matrix;
      }
}
