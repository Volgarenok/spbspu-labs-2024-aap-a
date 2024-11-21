#include <iostream>
#include <cstdlib>
#include <cstddef>
#include "fu_string.h"

int main()
{
  char *str1 = nullptr;
  char *str2 = nullptr;
  if (hismatova::getLine(&str1) == 1)
  {
    std::cerr << "error in reading first line\n";
    return 1;
  }
  if (hismatova::getLine(&str2) == 1)
  {
    std::cerr << "error in reading second line\n";
    free(str1);
    return 1;
  }
  if (str1[0] == '\0' && str2[0] == '\0')
  {
    std::cerr << "empty strings\n";
    free(str1);
    free(str2);
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
    free(str2);
    return 1;
  }
  free(str1);
  free(str2);
  return 0;
}
