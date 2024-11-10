#include "exc_snd.hpp"
#include <iostream>

int main()
{
  char* str = read_string(std::cin);
  char* result = exc_snd(str, nullptr);
  std::cout << result;
  return 0;
}