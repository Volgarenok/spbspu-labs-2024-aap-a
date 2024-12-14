#include <iostream>
#include "change.h"
#include "dynamic.h"
#include <cstddef>
#include <cstdlib>
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
  char * str_rep = komarova::rep_sym(str, str_res);
  if (str_rep == nullptr)
  {
    std::cerr << "Error in rep_sym \n";
    free(str);
    free(str_res);
    return 1;
  }
  std::cout << str_rep << "\n";
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
