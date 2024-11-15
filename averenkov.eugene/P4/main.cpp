#include <cstddef>
#include <ios>
#include <iostream>
#include <memory>
#include "arraymoves.h"
int main()
{
  size_t max = 10;
  char* str1 = nullptr;
  char* str2 = nullptr;
  try
  {
    str1 = reinterpret_cast<char*>(malloc(sizeof(char) * (max + 1)));
    str2 = reinterpret_cast<char*>(malloc(sizeof(char) * (max + 1)));
    if (!str1 || !str2)
    {
      free(str1);
      free(str2);
      std::cerr << "Out of memory\n";
      return 1;
    }
    str1 = averenkov::stringInput(std::cin, str1);
    str2 = averenkov::stringInput(std::cin, str2);
    if (!str1 || !str2)
    {
      free(str1);
      free(str2);
      std::cerr << "Out of memory during input\n";
      return 1;
    }
  }
  catch (const std::bad_alloc& e)
  {
    free(str1);
    free(str2);
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  char* result = nullptr;
  result = averenkov::latTwo(str1, str2);
  if (result == nullptr)
  {
    free(result);
    std::cerr << "Out of memory\n";
    return 1;
  }
  std::cout << result << "\n";
  free(str1);
  free(str2);
  free(result);
  return 0;
}
