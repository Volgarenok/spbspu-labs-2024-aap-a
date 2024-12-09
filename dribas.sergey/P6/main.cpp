
#include <iostream>
#include <enterStr.hpp>
#include "isValidString.hpp"
int main()
{
  char* str = dribas::enterStr(std::cin);
  if (!str && std::cin.eof()) {
    return 1;
  }
  if (std::cin.eof()) {
    free(str);
    return 0;
  }
  std::cout << std::boolalpha << dribas::isValidString(str) << '\n';
  free(str);
  return 0;
}
