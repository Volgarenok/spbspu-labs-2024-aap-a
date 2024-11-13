#include "matrix.hpp"
#include <iostream>

int evstyunichev::CastToDigit(char* s)
{
  int ans = 0;
  if (s[1] == 0)
  {
    if ((s[0] <= '2') && (s[0] >= '1'))
    {
      ans = s[0] - '0';
    }
  }
  return ans;
}

std::istream & evstyunichev::Input(std::istream & fin, int* arr, size_t m, size_t n, size_t &read)
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

bool evstyunichev::IsRowNsm(int* arr, size_t i, size_t m)
{
  bool isNsm = true;
  for(size_t j = 1; j < m; j++)
  {
    if (arr[i * m + j] == arr[i * m + j - 1])
    {
      isNsm = 0;
    }
  }
  return isNsm;
}

size_t evstyunichev::CntRowsNsm(int* arr, size_t n, size_t m)
{
  size_t ans = 0;
  for (size_t i = 0; i < n; i++)
  {
    ans += evstyunichev::IsRowNsm(arr, i, m);
  }
  return ans;
}
