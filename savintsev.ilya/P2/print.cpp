#include "print.h"
#include "function.h"
#include "constants.h"
#include <cstdio>

savintsev::Interval savintsev::readInterval()
{
  savintsev::Interval new_A = {};
  std::cin >> new_A.begin >> new_A.end;
  return new_A;
}

double savintsev::roundN(double value, size_t n)
{
  double st = std::pow(10., n);
  return ((value >= 0) ? (std::round(value * st) / st) : (std::round(value * st) / st));
}

void savintsev::printBorder(size_t variation, size_t * w)
{
  size_t width = 10;
  for (size_t i = 0; i < 3; ++i)
    {
      width += w[i];
    }
  switch (variation)
  {
  case 1:
    for (size_t i = 0; i < (width); ++i)
    {
      std::cout << '=';
    }
    std::cout << '\n';
    break;
  case 2:
    for (size_t j = 0; j < 3; ++j)
    {
      std::cout << "|";
      for (size_t i = 0; i < (w[j]+2); ++i)
      {
        std::cout << '-';
      }
    }
    std::cout << "|\n";
    break;
  }
}

void savintsev::printLine(size_t * w)
{
  std::cout << "|";
  int stc = static_cast<int>(w[0]+2);
  printf("%*.*s", stc, stc, "X VAL");
  std::cout << "|";
  stc = static_cast<int>(w[1]+2);
  printf("%*.*s", stc, stc, "F w/TAYLORSER");
  std::cout << "|";
  stc = static_cast<int>(w[2]+2);
  printf("%*.*s", stc, stc, "F w/CMATH");
  std::cout << "|";
  std::cout << "\n";
}

void savintsev::printLine(double columnNum, size_t * w, size_t k)
{
  int stc = 0;
  std::cout << "| ";
  stc = static_cast<int>(w[0]);
  printf("%- *.*g", stc, stc-2, savintsev::roundN(columnNum, w[0]));
  std::cout << " | ";
  stc = static_cast<int>(w[1]);
  try
  {
    printf("%-*.*g", stc, stc-2, f_ExpMPow2X(columnNum, k, ERROR));
  }
  catch(const std::logic_error& e)
  {
    printf("%-*.*s", stc, stc, ERROR_MSG);
  }
  std::cout << " | ";
  stc = static_cast<int>(w[2]);
  printf("%-*.*g", stc, stc-2, savintsev::stdf_ExpMPow2X(columnNum));
  std::cout << " |";
  std::cout << "\n";
}

size_t savintsev::len(double b, double a)
{
  size_t k = b >= 0 ? 2 : 3;
  double ld = a;
  size_t li = a;
  for (; ld != li; ++k)
  {
    ld *= 10.;
    li = ld;
  }
  return k;
}

void savintsev::printSheetOfLines(Interval A, size_t k)
{
  size_t w1th = 0;
  {
    size_t a = savintsev::len(A.begin,STEP);
    size_t b = savintsev::len(A.begin,std::abs(A.begin));
    size_t c = savintsev::len(A.begin,std::abs(A.end));
    a = a > b ? a : b;
    a = a > c ? a : c;
    w1th = a;
  }
  size_t w2nd = std::strlen(ERROR_MSG);
  size_t w3rd = std::strlen(ERROR_MSG);
  size_t width[] = {w1th, w2nd, w3rd};
  savintsev::printBorder(1, width);
  savintsev::printLine(width);
  savintsev::printBorder(2, width);
  for (double i = A.begin; i < A.end; i += STEP)
  {
    savintsev::printLine(i, width, k);
  }
  savintsev::printLine(A.end, width, k);
  savintsev::printBorder(1, width);
}
