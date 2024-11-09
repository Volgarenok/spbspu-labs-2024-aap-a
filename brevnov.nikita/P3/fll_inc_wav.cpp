#include "fll_inc_wav.hpp"

void brevnov::fll_inc_wav(int * t, size_t m, size_t n)
{
  size_t maxstep = 0;
  if (m > n)
  {
    maxstep = n / 2 + n % 2;
  }
  else
  {
    maxstep = m / 2 + m % 2;
  }
  for (size_t step = 0; step < maxstep; ++step)
  {
    for (size_t i = step; i < m - step; ++i)
    {
      for (size_t j = step; j < n - step; ++j)
      {
        if ((i == step) || (j ==  step) || (i == m - step - 1) || (j == n - step - 1))
        {
          t[i * n + j] += 1 + step;
        }
      }
    }
  }
}
