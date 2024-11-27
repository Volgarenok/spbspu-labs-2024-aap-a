#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "check_string.h"

int main()
{
  char *str1 = nullptr;
  const char *str2 = "abc";
  if (hismatova::getLine(std::cin, &str1) == 1)
  {
    std::cerr << "error in reading first line\n";
    return 1;
  }
  if (str1[0] == '\0')
  {
    std::cerr << "empty string\n";
    free(str1);
    return 1;
  }
  char* result = hismatova::uniqueChar(str1, str2);
  if (result != nullptr)
  {
    std::cout << result << "\n";
    free(result);
  }
  else
  {
    std::cerr << "result is nullptr\n";
    free(str1);
    return 1;
  }
  free(str1);
  return 0;
}
