#include "exc_snd.hpp"
#include <iostream>

constexpr char exclude_characters[] = "abc";

int main()
{
  char* str = zholobov::read_string(std::cin);
  char* result = zholobov::exc_snd(str, exclude_characters);
  std::cout << result << "\n";
  free(result);
  return 0;
}
