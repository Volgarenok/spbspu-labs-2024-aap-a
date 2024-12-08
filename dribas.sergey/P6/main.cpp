#include <iostream>
#include <enterStr.hpp>
#include "isValidString.hpp"
int main()
{
  char* str = dribas::enterStr(std::cin);
  std::cout << std::boolalpha << dribas::isValidString(str) << '\n';
  free(str);
  return 0;
}
