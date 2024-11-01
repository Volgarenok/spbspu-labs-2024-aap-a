#include "checkFirst.h"
#include <cstring>
#include <fstream>
#include <iostream>
int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "To many arguments\n";
    return 1;
  }
  else if (!kiselev::checkFirst(argv[1]))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  else if (argv[1][1] != '\0' || (argv[1][0] != '1' && argv[1][0] != '2'))
  {

    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  char* inFile = argv[2];
  std::ifstream input(inFile);
  if (!input.is_open())
  {
    std::cerr << "The file cannot be opened\n";
    return 1;
  }
  size_t m = 0, n = 0;
  input >> m >> n;
  char* outFile = argv[3];
  std::ofstream output(outFile);
}

