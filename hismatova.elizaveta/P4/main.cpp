#include "fu_string.h"
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "fu_string.h"

int main()
{
  char str1[100];
  char str2[100];
  std::cin.getline(str1, sizeof(str1));
  std::cin.getline(str2, sizeof(str2));
  char* result = hismatova::uniqueChar(str1, str2);
  if (result != nullptr)
  {
    std::cout << result << "\n";
    free(result);
  }
  else
  {
    std::cerr << "result is nullptr\n";
    return 1;
  }
  return 0;
}
