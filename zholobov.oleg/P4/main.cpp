#include <iostream>
#include "exc_snd.hpp"

constexpr char exclude_characters[] = "abc";

int main()
{
  char* str = zholobov::read_string(std::cin);
  char* result = zholobov::exc_snd(str, exclude_characters);
  std::cout << result << "\n";
  free(result);
  free(str);
  return 0;
}
