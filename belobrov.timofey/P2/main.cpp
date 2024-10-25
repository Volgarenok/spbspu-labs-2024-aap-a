#include <iostream>
#include "output.hpp"
using namespace belobrov;

int main()
{

  double left = 0, right = 0; //верхняя и нижняя граница 
  size_t k = 0; //количество элементов 
  std::cin >> left >> right >> k;
  if (!std::cin)
  {
    std::cerr << "pupupuuuu... bad input!" << "\n";
    return 1;
  }
  if (left > right)
  {
    std::cerr << "pupupuuuu... logic?" << "\n";
    return 1;
  }
  if ((left < -1 || left > 1) || (right < -1 || right > 1))
  {
    std::cerr << "pupupuuuu... mimo!" << "\n";
    return 1;
  }

  output(left, right, 0.05, k);

}


