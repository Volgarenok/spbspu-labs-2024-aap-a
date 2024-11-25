#include "local_min.hpp"

{
  int dirti::local_min(int * matrix, size_t m, size_t n)
  {
    int num = 0;
    for (i = 1; i < (m - 1); ++i)
    {
      for (j = 1; j < (n - 1); ++j)
      {
        if (matrix[i * n + j] < matrix[i * n + j - 1] && matrix[i * n +j] < matrix[i * n + j + 1])
        {
          ++num;
        }
      }
    }
    return num;
  }
}
