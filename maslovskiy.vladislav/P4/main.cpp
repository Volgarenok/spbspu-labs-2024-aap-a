#include <cstdlib>
#include <iostream>
#include "inputString.hpp"
#include "mergeStrs.hpp"
int main()
{
  using namespace maslovskiy;
  char *str1 = nullptr;
  const char *str2 = "246789";
  str1 = inputString(std::cin);
  if (str1 == nullptr)
  {
    std::cerr << "Memory allocation failed for input string\n";
    return 1;
  }
  if (*str1 == '\0')
  {
    free(str1);
    std::cerr << "Input string is null\n";
    return 2;
  }
  constexpr size_t newSize = 512;
  char *united = static_cast< char* >(malloc(sizeof(char) * newSize));
  if (united == nullptr)
  {
    free(str1);
    std::cerr << "Cannot allocate memory for united string\n";
    return 3;
  }
  mergeStrs(united, str1, str2);
  std::cout << united << '\n';
  free(str1);
  free(united);
}
