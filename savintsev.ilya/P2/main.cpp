#include <iostream>
#include "interactterminal.h"

int main()
{
  std::cout << "Write interval and number of terms (accuracy) for Taylor series\n";
  double begin = 0., end = 0.;
  size_t k = 0;
  std::cin >> begin >> end >> k;

  if (!std::cin.good())
  {
    std::cerr << "Incorrect data was entered.\n";
    std::cerr << "Make sure all data is numbers.\n";
    return 1;
  }
  if ((begin <= -1) || (end >= 1))
  {
    std::cerr << "Incorrect data was entered.\n";
    std::cerr << "Make sure the interval is in the domain of the function.\n";
    std::cerr << "Probably it's (-1;1)?\n";
    return 1;
  }
  if (begin == end)
  {
    std::cerr << "Incorrect data was entered.\n";
    std::cerr << "Make sure the interval is not the point.\n";
    return 1;
  }
  if (begin > end)
  {
    std::cerr << "Incorrect data was entered.\n";
    std::cerr << "Make sure begin of the interval is lower than ending\n";
    return 1;
  }
  savintsev::printMathSheet(begin, end, k);
}
