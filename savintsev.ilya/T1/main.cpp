#include <iostream>
#include <cstring>
#include <newlineterminatedstr.h>
#include "base-types.hpp"
#include "rectangle.hpp"

int main()
{
  char * line = nullptr;
  const char * separator = " ";
  char * token = nullptr;
  while (!std::cin.eof())
  {
    line = savintsev::inputNewlineTerminatedStr(std::cin);
    if (line == nullptr)
    {
      std::cerr << "Failed to allocate memory or EOF\n";
      return 1;
    }
    if (line[0] == '\0')
    {
      std::cerr << "One of the lines is empty\n";
      delete[] line;
      return 1;
    }
    size_t wordsCounter = 0;
    token = std::strtok(line, separator);
    ++wordsCounter;
    if (!std::strcmp(token, "RECTANGLE"))
    {
      while (token)
      {
        ++wordsCounter;
        std::cout << token << '\n';
        token = std::strtok(nullptr, separator);
      }
      return 0;
    }
    else
    {
      std::cerr << "Wrong shape\n";
      return 3;
    }
  }
}
