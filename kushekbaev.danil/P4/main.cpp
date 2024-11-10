#include "arrays_reading.hpp"
#include <iostream>

int main()
{
  size_t max = 10;
  size_t size1 = 0;
  size_t size2 = 0;

  char * str1 = kushekbaev::readInputArray(size1, max);

  char * str2 = kushekbaev::readInputArray(size2, max);

  if (str1 == nullptr || str2 == nullptr || size1 == 0 || size2 == 0)
  {
    std::cerr << "Failed input";
    delete[] str1;
    delete[] str2;
    return 1;
  }

  bool hasCommonChars = false;

  for (size_t i = 0; i < size1; i++)
  {
    for (size_t j = 0; j < size2; j++)
    {
      if (str1[i] == str2[j])
      {
        hasCommonChars = true;
        break;
      }
    }
      if (hasCommonChars) break;
    }

    std::cout << (hasCommonChars ? 1 : 0) << std::endl;

  delete[] str1;
  delete[] str2;
  return 0;
}
