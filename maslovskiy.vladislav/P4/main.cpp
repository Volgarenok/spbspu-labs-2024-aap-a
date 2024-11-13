#include <iostream>
#include "inputString.hpp"
#include "mergeStrs.hpp"
int main()
{
  char *str1 = nullptr;
  const char *str2 = "246789";
  try
  {
   char *str1 = inputString(std::cin);
  }
  catch (const std::bad_alloc &)
  {
    std::cerr << "incorrect memory allocation\n";
    return 1;
  }
  if (*str1 == '\0')
  {
    free(str1);
    std::cerr << "input string is null\n";
    return 2;
  }
  char * united = nullptr;
  try
  {
    united = static_cast<char*>(malloc(sizeof(char) * 512));
  }
  catch (const std::bad_alloc &)
  {
    free(str1);
    free(united);
    std::cerr << "Cannot create new strings\n";
    return 3;
  }
  mergeStrs(united, str1, str2);
  for (size_t i = 0; united[i] != '\0'; i++)
  {
    std::cout << united[i];
  }
  std::cout << '\n';
  free(str1);
  free(united);
}
