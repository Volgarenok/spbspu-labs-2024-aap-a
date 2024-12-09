#include <iostream>
#include <enterStr.hpp>
#include "isValidString.hpp"
int main()
{
  char* str = dribas::enterStr(std::cin);
  if (std::cin.eof()) {
    return 1;
  }
  if (!str) {
    return 0;
  }
  std::cout << std::boolalpha << dribas::isValidString(str) << '\n';
  free(str);
  return 0;
}
