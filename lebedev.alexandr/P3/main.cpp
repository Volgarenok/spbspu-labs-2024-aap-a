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
  size_t m = 0, n = 0;
  inputFile >> m >> n;
  if (!inputFile)
  {
    std::cerr << "Incorrect data in the file!\n";
    return 2;
  }

  std::ofstream outputFile(argv[3]);
  if (num == 1)
  {
    const size_t size = (m * n);
    size_t c = 0;
    int arr[size];

    if(!inputTable(inputFile, arr, m))
    {
      std::cerr << "Incorrect data in the file!\n";
      return 2;
    }

    outputTable(outputFile, arr, m);
    outputFile << '\n';
  }
  return 0;
}
