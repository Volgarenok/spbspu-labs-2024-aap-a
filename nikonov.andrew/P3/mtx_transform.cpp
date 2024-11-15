#include "mtx_transform.hpp"
#include <iostream>
#include <cstdlib>
std::istream& nikonov::readMatrix(std::istream& input, int* mtx, size_t m, size_t n, size_t& read)
{
  for (size_t i = 0; i < m * n; ++i)
  {
    if (!(input >> mtx[i]))
    {
      return input;
    }
    ++read;
  }
  return input;
}
void nikonov::printMatrix(std::ostream& output, int* mtx, size_t m, size_t n)
{
  if (m > 0 && n > 0)
  {
    output << m << " " << n << " " << mtx[0];
  }
  else
  {
    output << m << " " << n;
  }
  for (size_t i = 1; i < m * n; ++i)
  {
    output << " " << mtx[i];
  }
}
void nikonov::spiralMtxReduction(int* mtx, size_t m, size_t n)
{
  size_t decreaser = 1;
  size_t vertMove = n;
  size_t currentIndex = m * n - n;
  while (m > 0 && n > 0)
  {
    if (m == 1 || n == 1)
    {
      mtx[currentIndex] -= decreaser;
      break;
    }
    for (size_t moveUp = 0; moveUp < m - 1; ++moveUp)
    {
      mtx[currentIndex] -= decreaser;
      ++decreaser;
      currentIndex -= vertMove;
    }
    for (size_t moveRight = 0; moveRight < n - 1; ++moveRight)
    {
      mtx[currentIndex] -= decreaser;
      ++decreaser;
      currentIndex += 1;
    }
    for (size_t moveDown = 0; moveDown < m - 1; ++moveDown)
    {
      mtx[currentIndex] -= decreaser;
      ++decreaser;
      currentIndex += vertMove;
    }
    for (size_t moveLeft = 0; moveLeft < n - 1; ++moveLeft)
    {
      mtx[currentIndex] -= decreaser;
      ++decreaser;
      currentIndex -= 1;
    }
    currentIndex -= vertMove;
    ++currentIndex;
    if (m == 2 || n == 2)
    {
      break;
    }
    else
    {
      m -= 2;
      n -= 2;
    }
  }
}
