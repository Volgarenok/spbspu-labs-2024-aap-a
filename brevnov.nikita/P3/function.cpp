#include "matrix.hpp"

int brevnov::osed_fun(const int * t, size_t m, size_t n)
{
  int otvet = 0;
  for (size_t i = 0; i < m; i++)
  {
    size_t min_mem = brevnov::find_index_min(t, n, i);
    if (i == (brevnov::find_index_max(t, m, n, min_mem)))
    {
      otvet++;
    }
  }
  return otvet;
}

size_t brevnov::find_index_min(const int * t, size_t n, size_t i)
{
  int min_mem = t[i * n];
  size_t min_index = 0;
  for (size_t j = 1; j < n; ++j)
  {
    if (min_mem > t[i * n + j])
    {
      min_mem = t[i * n + j];
      min_index = j;
    }
  }
  return min_index;
}

size_t brevnov::find_index_max(const int * t, size_t m, size_t n, int min_mem)
{
  int max_mem = t[min_mem];
  size_t max_index = 0;
  for (size_t j = 1; j < m; ++j)
  {
    if (max_mem < t[j * n + min_mem])
    {
      max_mem = t[j * n + min_mem];
      max_index = j;
    }
  }
  return max_index;
}
