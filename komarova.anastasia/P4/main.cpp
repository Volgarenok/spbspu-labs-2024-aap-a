#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <dynamic.h>
#include "change.h"
int main()
{
  size_t size_str = 20;
  size_t size_str_now = 0;
  char* str = komarova::read(std::cin, size_str, size_str_now, '\n');
  if (str == nullptr)
  {
    std::cerr << "No memory allocated or incorrect parameters \n";
    return 1;
  }
  if (size_str_now == 0)
  {
    free(str);
    std::cerr << "Empty string \n";
    return 1;
  }
  char* str_res = reinterpret_cast< char* >(malloc((size_str_now + 1) * sizeof(char)));
  if (str_res == nullptr)
  {
    free(str);
    std::cerr << "No memory allocated \n";
    return 1;
  }
  str_res[0] = '\0';
  str_res[size_str_now] = '\0';

  std::cout << komarova::rep_sym(str, str_res) << "\n";
  char* str_vowels = komarova::vowels(str, str_res);
  if (str_vowels == nullptr)
  {
    std::cerr << "Error in vowels \n";
    free(str);
    free(str_res);
    return 1;
  }
  std::cout << str_vowels << "\n";
  free(str);
  free(str_res);
}
