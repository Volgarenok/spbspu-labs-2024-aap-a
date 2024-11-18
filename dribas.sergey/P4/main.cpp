#include <cstddef>
#include <iostream>
#include <ios>
#include "enterStr.hpp"
#include "checkChar.hpp"

int main()
{
  char* str = nullptr;
  dribas::enterStr(str);
  if (str == nullptr) {
    return 1;
  }
  std::cout << dribas::checkChar(str);
  std::cout << '\n';
  free(str);
  return 0;
}

