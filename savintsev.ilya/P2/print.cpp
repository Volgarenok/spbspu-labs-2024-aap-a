#include "print.h"
#include "function.h"
#include "constants.h"

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

void savintsev::printBorder(size_t b)
{
  for (size_t i = 0; i < b; ++i)
  {
    std::cout << '=';
  }
  std::cout << '\n';
}

void savintsev::printLine(double columnNum, size_t * w, size_t k)
{
  std::cout << "| ";
  std::cout << std::setw(w[0]) << savintsev::roundN(columnNum, w[0]-2);
  std::cout << " | ";
  try
  {
    double value = f_ExpMPow2X(columnNum, k, ERROR);
    std::cout << std::setw(w[1]) << value;
  }
  catch(const std::logic_error& e)
  {
    std::cerr << std::setw(w[1]) << ERROR_MSG;
  }
  std::cout << " | ";
  std::cout << std::setw(w[2]) << savintsev::stdf_ExpMPow2X(columnNum);
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
  size_t w1th = savintsev::len(A.begin,STEP);
  size_t w2nd = std::strlen(ERROR_MSG);
  size_t w3rd = std::strlen(ERROR_MSG);
  size_t width[] = {w1th, w2nd, w3rd};
  size_t sumOfWidths = w1th+w2nd+w3rd+10;
  savintsev::printBorder(sumOfWidths);
  for (double i = A.begin; i < A.end; i += STEP)
  {
    savintsev::printLine(i, width, k);
  }
  savintsev::printBorder(sumOfWidths);
}
