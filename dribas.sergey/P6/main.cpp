
#include <iostream>
#include <enterStr.hpp>
#include "isValidString.hpp"
int main()
{
  char* str = dribas::enterStr(std::cin);
  if (!str) {
    return 1;
  }
  std::cout << std::boolalpha << dribas::isValidString(str) << '\n';
  free(str);
  return 0;
}
