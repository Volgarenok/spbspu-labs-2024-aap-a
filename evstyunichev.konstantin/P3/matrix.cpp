#include "matrix.hpp"
#include <iostream>

size_t evstyunichev::cstring_len(char* s)
{
  size_t len = 0;
  for (; s[len] != 0; len++);
  return len;
}

std::istream & evstyunichev::input(std::istream & fin, int* arr, size_t m, size_t n, size_t &read)
{
  int num = 0;
  for (size_t i = 0; i < m; i++)
  {
    for (size_t j = 0; j < n; j++)
    {
      if (fin >> num)
      {
        read++;
      }
      arr[i * n + j] = num;
    }
  }
  return fin;
}

bool evstyunichev::isRowNsm(int* arr, size_t i, size_t n)
{
  bool isNsm = true;
  for(size_t j = 1; j < n; j++)
  {
    if (arr[i * n + j] == arr[i * n + j - 1])
    {
      isNsm = 0;
    }
  }
  return isNsm;
}

size_t evstyunichev::CntRowsNsm(int* arr, size_t m, size_t n)
{
  size_t ans = 0;
  for (size_t i = 0; i < m; i++)
  {
    ans += evstyunichev::isRowNsm(arr, i, n);
  }
  return ans;
}

void evstyunichev::ddel(int* arr, int num)
{
  constexpr int dinamic_flag = 2;
  if (num == dinamic_flag)
  {
    delete[] arr;
  }
  return;
}
