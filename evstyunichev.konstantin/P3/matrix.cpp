#include "matrix.hpp"
#include <iostream>

int evstyunichev::cast_to_digit(char *s)
{
  int ans = 0;
  if (!s[0])
  {
    return 0;
  }
  if (!s[1])
  {
    if ((s[0] <= '2') && (s[0] >= '1'))
    {
      ans = s[0] - '0';
    }
  }
  return ans;
}

std::istream & evstyunichev::input(std::istream &fin, int *arr, size_t n, size_t m, size_t &read)
{
  int num = 0;
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      if (fin >> num)
      {
        read++;
      }
      else
      {
        num = 0;
      }
      arr[i * m + j] = num;
    }
  }
  return fin;
}

bool evstyunichev::is_row_nsm(int *arr, size_t i, size_t m)
{
  bool isNsm = m;
  for(size_t j = 1; j < m; j++)
  {
    if (arr[i * m + j] == arr[i * m + j - 1])
    {
      isNsm = 0;
    }
  }
  return isNsm;
}

size_t evstyunichev::cnt_rows_nsm(int *arr, size_t n, size_t m)
{
  size_t ans = 0;
  for (size_t i = 0; i < n; i++)
  {
    ans += evstyunichev::is_row_nsm(arr, i, m);
  }
  return ans;
}

bool evstyunichev::solve_print(std::istream &fin, std::ostream &fout, int *arr, size_t n, size_t m, size_t &read)
{
  if (input(fin, arr, n, m, read) && (read == n * m))
  {
    fout << cnt_rows_nsm(arr, n, m) << '\n';
    return 1;
  }
  return 0;
}

void evstyunichev::output(std::ostream &fout, int *arr, size_t n, size_t m)
{
  for (size_t i = 0; i < n; i++)
  {
    for (size_t j = 0; j < m; j++)
    {
      fout << arr[i * m + j] << ' ';
    }
    fout << '\n';
  }
  return;
}
