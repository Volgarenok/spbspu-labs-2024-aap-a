#include <cstddef>
#include <iostream>
#include <cstdlib>
#include <dynamicinput.h>
#include "lattwo.h"

int main()
{
  constexpr char sec_string[] = "abcd";
  char* str1 = averenkov::stringInput(std::cin);
  if (!str1)
  {
    free(str1);
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (str1[0] == '\0')
  {
    free(str1);
    std::cerr << "Empty input\n";
    return 1;
  }
  char result[27];
  averenkov::latTwo(str1, sec_string, result);
  std::cout << result << "\n";
  free(str1);
  return 0;
}
