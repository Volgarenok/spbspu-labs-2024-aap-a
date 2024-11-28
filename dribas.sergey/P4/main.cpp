#include <iostream>
#include <enterStr.hpp>
#include "difLat.hpp"

int main()
{
  char* str = dribas::enterStr(std::cin);
  if (!str) {
    return 1;
  }
  std::cout << dribas::difLat(str);
  std::cout << '\n';
  free(str);
  return 0;
}

