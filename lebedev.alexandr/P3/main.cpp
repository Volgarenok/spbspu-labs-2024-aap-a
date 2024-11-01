#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include "table.hpp"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments!\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments!\n";
    return 1;
  }
  
  char* t = argv[1];
  if (!isNumbers(t))
  {
    std::cerr << "First parameter is not a number!\n";
    return 1;
  }

  int num = atoi(t);
  if (num < 1 || num > 2)
  {
    std::cerr << "First parameter is out of range!\n";
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  if (num == 1)
  {
  
  }
  

  std::ofstream outputFile(argv[3]);
}
