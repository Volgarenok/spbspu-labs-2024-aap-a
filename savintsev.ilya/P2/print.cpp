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
    for (size_t i = 0; i < (w[j] + 2); ++i)
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

void savintsev::printMathLine(double x, const size_t * w, size_t k)
{
  std::cout << "| ";
  std::cout << std::setw(w[0]) << std::fixed << std::setprecision(w[0] - 3) << x;
  std::cout << " | ";
  std::cout.unsetf(std::ios::floatfield | std::ios::adjustfield);
  std::cout.precision(w[1] - 2);
  std::cout.setf(std::ios::left);
  try
  {
    std::cout << std::setw(w[1]) << savintsev::calcFuncTaylor(x, k, savintsev::ERROR);
  }
  catch(const std::logic_error& e)
  {
    std::cout << savintsev::ERROR_MSG;
  }
  std::cout << " | ";
  std::cout.precision(w[2] - 2);
  std::cout << std::setw(w[2]) << savintsev::calcFuncStd(x);
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
  size_t wStep = 0;
  {
    const double w[] = {savintsev::STEP, begin, end, 0.001};
    wStep = savintsev::calcWidth(w);
  }
  size_t wMath = std::strlen(savintsev::ERROR_MSG);
  size_t width[] = {wStep, wMath, wMath};
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
