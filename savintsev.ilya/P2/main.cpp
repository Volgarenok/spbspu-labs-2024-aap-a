#include "function.h"
#include "print.h"

int main()
{
  size_t k = 0;
  savintsev::Interval A = savintsev::readInterval();
  std::cin >> k;

  if ((A.begin <= -1) || (A.end >= 1))
  {
    return 1;
  }

  savintsev::printSheetOfLines(A, k);
}
