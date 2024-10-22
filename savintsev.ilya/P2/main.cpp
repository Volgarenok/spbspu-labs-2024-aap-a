#include "function.h"
#include "print.h"
#include "constants.h"

int main()
{
  std::cout << "Write interval and number of the shit\n";
  size_t k = 0;
  savintsev::Interval A = savintsev::readInterval();
  std::cin >> k;

  if (!std::cin.good())
  {
    std::cerr << "Incorrect data was entered.\n";
    std::cerr << "Make sure all data is numbers.\n";
    return 1;
  }
  if ((A.begin <= -1) || (A.end >= 1))
  {
    std::cerr << "Incorrect data was entered.\n";
    std::cerr << "Make sure the interval is in the domain of the function.\n";
    std::cerr << "Probably it's (-1;1)?\n";
    return 1;
  }
  if ((A.begin == A.end) || (A.end - A.begin) < STEP)
  {
    std::cerr << "Incorrect data was entered.\n";
    std::cerr << "Make sure the interval is not the point.\n";
    std::cerr << "Maybe STEP needs to be increased?(constants.cpp)\n";
    return 1;
  }
  if (A.begin > A.end)
  {
    std::cerr << "Incorrect data was entered.\n";
    std::cerr << "Make sure begin of the interval is lower than ending\n";
    return 1;
  }
  savintsev::printSheetOfLines(A, k);
}
