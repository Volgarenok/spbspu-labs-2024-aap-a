#include <iostream>
#include <read_string.hpp>
#include "is_match_real.hpp"

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
  std::cout << std::boolalpha << zholobov::is_match_real(str) << "\n";
  std::free(str);
}
