#include <iostream>
#include <cctype>
#include <workWithString.hpp>
int main()
{
  char **arrStrings[10000] = {};
  for (size_t i = 0; i < 10000; i++)
  {
    arrStrings[i] = getLine(std::cin);
    
  }
}
