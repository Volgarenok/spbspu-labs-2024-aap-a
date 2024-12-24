#include <iostream>
#include <read_string.hpp>
#include "exc_snd.hpp"

constexpr char exclude_characters[] = "abc";

int main()
{
  char* str = zholobov::read_string(std::cin);
  if (str == nullptr) {
    std::cerr << "Failed to read input string\n";
    return 1;
  }
  if (*str == '\0') {
    std::cerr << "Empty string was entered\n";
    std::free(str);
    return 1;
  }
  char* result = zholobov::exc_snd(str, str, exclude_characters);
  std::cout << result << "\n";
  std::free(str);
  return 0;
}
