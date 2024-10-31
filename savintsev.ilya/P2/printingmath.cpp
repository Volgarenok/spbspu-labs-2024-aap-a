#include "printingmath.h"
#include <cstring>
#include <iomanip>
#include <iostream>
#include "mathematics.h"

namespace savintsev
{
  const char * ERROR_MSG = "<MATH ERROR>";
  extern constexpr double ERROR = 0.0001;
  extern constexpr double STEP = 0.01;
}

void savintsev::printBorderEquals(Triple w)
{
  size_t width = 10;
  width += w.x + w.y + w.z;
  for (size_t i = 0; i < (width); ++i)
  {
    std::cout << '=';
  }
  std::cout << '\n';
}

void savintsev::printBorderMinusPlus(Triple w)
{
  std::cout << "|";
  for (size_t i = 0; i < (w.x + 2); ++i)
  {
    std::cout << '-';
  }
  std::cout << "|";
  for (size_t i = 0; i < (w.y + 2); ++i)
  {
    std::cout << '-';
  }
  std::cout << "|";
  for (size_t i = 0; i < (w.z + 2); ++i)
  {
    std::cout << '-';
  }
  std::cout << "|\n";
}

void savintsev::printMathInfo(Triple w)
{
  std::cout << "| ";
  std::cout << std::setw(w.x) << "X VAL";
  std::cout << " | ";
  std::cout << std::setw(w.y) << "F w/TAYLORSR";
  std::cout << " | ";
  std::cout << std::setw(w.z) << "F w/CMATH";
  std::cout << " |";
  std::cout << "\n";
}

void savintsev::printMathLine(double x, Triple w, size_t k)
{
  std::cout << "| ";
  std::cout << std::setw(w.x) << std::fixed << std::setprecision(w.x - 3) << x;
  std::cout << " | ";
  std::cout.unsetf(std::ios::floatfield | std::ios::adjustfield);
  std::cout.precision(w.y - 2);
  std::cout.setf(std::ios::left);
  try
  {
    std::cout << std::setw(w.y) << savintsev::calcFuncTaylor(x, k, savintsev::ERROR);
  }
  catch (const std::logic_error & e)
  {
    std::cout << savintsev::ERROR_MSG;
  }
  std::cout << " | ";
  std::cout.precision(w.z - 2);
  std::cout << std::setw(w.z) << savintsev::calcFuncStd(x);
  std::cout << " |";
  std::cout.unsetf(std::ios::floatfield | std::ios::adjustfield);
  std::cout << "\n";
}

size_t savintsev::calcWidth(const double * p)
{
  size_t width = 0;
  for (size_t i = 0; i < 4; ++i)
  {
    double a = p[i];
    size_t k = (a >= 0) ? 2 : 3;
    a = std::abs(a);
    double ld = a;
    size_t li = a;
    for (; ld != li; ++k)
    {
      ld *= 10.;
      li = ld;
    }
    width = (width > k) ? width : k;
  }
  return width;
}

void savintsev::printMathSheet(double begin, double end, size_t k)
{
  savintsev::Triple widths;
  {
    double w[4] = {savintsev::STEP, begin, end, 0.001};
    widths.x = savintsev::calcWidth(w);
  }
  widths.y = std::strlen(savintsev::ERROR_MSG);
  widths.z = std::strlen(savintsev::ERROR_MSG);
  savintsev::printBorderEquals(widths);
  savintsev::printMathInfo(widths);
  savintsev::printBorderMinusPlus(widths);
  for (double i = begin; i < end; i += savintsev::STEP)
  {
    savintsev::printMathLine(i, widths, k);
  }
  savintsev::printMathLine(end, widths, k);
  savintsev::printBorderEquals(widths);
}
