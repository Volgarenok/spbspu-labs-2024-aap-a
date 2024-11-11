#include "arrays_reading.hpp"
#include <iostream>

int main()
{
  size_t max = 10;
  size_t size1 = 0;
  size_t size2 = 0;

  char * str1 = kushekbaev::readInputArray(size1, max);

  char * str2 = kushekbaev::readInputArray(size2, max);

  if (size1 == 0 and size2 == 0)
  {
    std::cerr << "Failed input" << "\n";
    delete[] str1;
    delete[] str2;
    return 1;
  }

  int result = kushekbaev::hasCommonChars(str1, size1, str2, size2);
  std::cout << result << "\n";

  delete[] str1;
  delete[] str2;
  return 0;
}
