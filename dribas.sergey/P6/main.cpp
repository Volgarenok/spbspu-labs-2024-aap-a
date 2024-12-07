#include <iostream>
#include <enterStr.hpp>
#include "isValidString.hpp"
int main()
{
  const char* str = dribas::enterStr(std::cin);
  if (str ==nullptr) {
    std::cerr << "error\n";
    return 1;
  }
  if (str[0] == '\0') {
    std::cerr << "nostring\n";
    return 1;
  }
  std::cout << std::boolalpha << dribas::isValidString(str) << '\n';
  return 0;
}
