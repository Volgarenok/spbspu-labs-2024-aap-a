#include <cstddef>
#include <iostream>
#include <cstdlib>
#include "arraymoves.h"
#include <dynamicinput.h>

int main()
{
  size_t max = 10;
  char* str1 = reinterpret_cast<char*>(malloc(sizeof(char) * (max + 1)));
  char* str2 = reinterpret_cast<char*>(malloc(sizeof(char) * (max + 1)));
  if (!str1 || !str2)
  {
    free(str1);
    free(str2);
    std::cerr << "Out of memory\n";
    return 1;
  }
  try
  {
    char* newStr1 = averenkov::stringInput(std::cin, str1);
    if (!newStr1)
    {
      free(str1);
      free(str2);
      std::cerr << "Out of memory during input\n";
      return 1;
    }
    free(str1);
    str1 = newStr1;
    char* newStr2 = averenkov::stringInput(std::cin, str2);
    if (!newStr2)
    {
      free(str1);
      free(str2);
      std::cerr << "Out of memory during input\n";
      return 1;
    }
    if (newStr1[0] == '\0' && newStr2[0] == '\0')
    {
      free(newStr2);
      free(newStr1);
      free(str2);
      std::cerr << "Error: Empty string input\n";
      return 1;
    }
    free(str2);
    str2 = newStr2;
    char* result = averenkov::latTwo(str1, str2);
    if (!result)
    {
      free(str1);
      free(str2);
      std::cerr << "Error in latTwo\n";
      return 1;
    }
    std::cout << result << "\n";
    free(result);
  }
  catch (const std::bad_alloc& e)
  {
    free(str1);
    free(str2);
    std::cerr << "Error: " << e.what() << "\n";
    return 1;
  }
  free(str1);
  free(str2);
  return 0;
}

