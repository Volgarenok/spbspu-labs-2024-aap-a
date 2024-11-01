#include <iostream>
#include <cstdlib>
#include <cstring>
#include "table.hpp"

int main(int argc, char** argv)
{
  
  char* t = argv[1];
  bool i = isNumbers(t);
  std::cout << i << '\n';
}
