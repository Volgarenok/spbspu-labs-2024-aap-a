#include <iostream>
#include <vector>
#include <string>
#include "fileIO.hpp"
#include "matrixUtils.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4) {
      std::cerr << "Usage: " << argv[0] << " <num> <input> <output>\n";
      std::cerr << "Incorrect number of arguments\n";
      return 1;
  }

  int mode = 0;

  try {
    mode = std::stoi(argv[1]);
  }
  catch (const std::invalid_argument&) {
    std::cerr << "Error: First parameter is not a number\n";
    return 1;
  }

  if (mode != 1 && mode != 2) {
    std::cerr << "Error: First parameter is out of range (expected 1 or 2)\n";
    return 1;
  }

  std::string inputFile = argv[2];
  std::string outputFile = argv[3];

  return 0;
}
