#include "exc_snd.hpp"
#include <iostream>

int main()
{
  char* str = read_string(std::cin);
  char* result = exc_snd(str, "abc");
  std::cout << result;
  free(result);
  return 0;
}