#include "print.h"
#include <cstring>
#include <iomanip>
#include "constants.h"
#include "mathematics.h"

void savintsev::printBorderEquals(const size_t * w)
{
  size_t width = 10;
  for (size_t i = 0; i < 3; ++i)
  {
    width += w[i];
  }
  for (size_t i = 0; i < (width); ++i)
  {
    std::cout << '=';
  }
  std::cout << '\n';
}

void savintsev::printBorderMinusPlus(const size_t * w)
{
  for (size_t j = 0; j < 3; ++j)
  {
    std::cout << "|";
    for (size_t i = 0; i < (w[j]+2); ++i)
    {
      std::cout << '-';
    }
  }
  std::cout << "|\n";
}

void savintsev::printMathInfo(const size_t * w)
{
  std::cout << "| ";
  std::cout << std::setw(w[0]) << "X VAL";
  std::cout << " | ";
  std::cout << std::setw(w[1]) << "F w/TAYLORSR";
  std::cout << " | ";
  std::cout << std::setw(w[2]) << "F w/CMATH";
  std::cout << " |";
  std::cout << "\n";
}

void savintsev::printMathLine(double colomn, const size_t * w, size_t k)
{
  std::cout << "| ";
  std::cout.setf(std::ios::right | std::ios::fixed);
  std::cout << std::setw(w[0]) << std::setprecision(w[0]-3) << colomn;
  std::cout << " | ";
  std::cout.unsetf(std::ios::floatfield | std::ios::adjustfield);
  std::cout.setf(std::ios::left);
  try
  {
    double value = savintsev::f_ExpMPow2X(colomn, k, savintsev::ERROR);
    std::cout << std::setw(w[1]) << std::setprecision(w[1]-2) << value;
  }
  catch(const std::logic_error& e)
  {
    std::cout << savintsev::ERROR_MSG;
  }
  std::cout << " | ";
  {
    double value = savintsev::stdf_ExpMPow2X(colomn);
    std::cout << std::setw(w[2]) << std::setprecision(w[2]-2) << value;
  }
  std::cout << " |";
  std::cout.unsetf(std::ios::floatfield | std::ios::adjustfield);
  std::cout << "\n";
}

size_t savintsev::lenOfSignedFractionalPart(double a)
{
  size_t k = (a >= 0) ? 2 : 3;
  a = std::abs(a);
  double ld = a;
  size_t li = a;
  for (; ld != li; ++k)
  {
    ld *= 10.;
    li = ld;
  }
  return k;
}

void savintsev::printMathSheet(double begin, double end, size_t k)
{
  size_t w1th = 0;
  {
    size_t a = savintsev::lenOfSignedFractionalPart(savintsev::STEP);
    size_t b = savintsev::lenOfSignedFractionalPart(begin);
    size_t c = savintsev::lenOfSignedFractionalPart(end);
    a = a > b ? a : b;
    a = a > c ? a : c;
    a = a > 5 ? a : 5;
    w1th = a;
  }
  size_t w2nd = std::strlen(savintsev::ERROR_MSG);
  size_t w3rd = std::strlen(savintsev::ERROR_MSG);
  size_t width[] = {w1th, w2nd, w3rd};
  savintsev::printBorderEquals(width);
  savintsev::printMathInfo(width);
  savintsev::printBorderMinusPlus(width);
  for (double i = begin; i < end; i += savintsev::STEP)
  {
    savintsev::printMathLine(i, width, k);
  }
  savintsev::printMathLine(end, width, k);
  savintsev::printBorderEquals(width);
}
