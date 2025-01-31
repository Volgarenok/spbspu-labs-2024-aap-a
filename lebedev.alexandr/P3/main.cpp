#include <iostream>
#include <cstdlib>
#include <fstream>
#include "matrix.hpp"

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

  if (argv[1][0] == '\0')
  {
    std::cerr << "First parameter is empty\n";
    return 1;
  }
  if (argv[1][1] != '\0' || (argv[1][0] != '1' && argv[1][0] != '2'))
  {
    std::cerr << "Incorrect first parameter!\n";
    return 1;
  }
  int num = std::atoi(argv[1]);

  std::ifstream inputFile(argv[2]);
  size_t m = 0, n = 0;
  inputFile >> m >> n;
  if (!inputFile || n != m)
  {
    std::cerr << "Incorrect dimensions of the matrix!\n";
    return 2;
  }

  constexpr size_t fixedSize = 10000;
  int fixedArr[fixedSize];
  int* dynamicArr = nullptr;
  int* arr = nullptr;

  if (num == 2)
  {
    try
    {
      dynamicArr = new int[m * n];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Memory allocation error!\n";
      return 2;
    }
    arr = dynamicArr;
  }
  else
  {
    arr = fixedArr;
  }

  if (!lebedev::input(inputFile, arr, m))
  {
    std::cerr << "Incorrect data in the file\n";
    delete[] dynamicArr;
    return 2;
  }

  std::ofstream outputFile(argv[3]);
  outputFile << std::boolalpha << lebedev::lwrTriMtx(arr, m) << "\n";

  delete[] dynamicArr;
  return 0;
}
