#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  char* end = nullptr;
  long num = std::strtol(argv[1], &end, 10);
  if (*end != '\0' || (num != 1 && num != 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t m = 0;
  size_t n = 0;
  input >> m >> n;
  size_t read = 0;
  if (input.fail())
  {
    std::cerr << "Failed to read matrix dimensions\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  if (m == 0 || n == 0)
  {
    output << m << " " << n << "\n";
    return 0;
  }
  int fixedLengthArr[1000] = {};
  int * dynamicArr = nullptr;
  int * array = fixedLengthArr;
  if (num == 2)
  {
    try
    {
      dynamicArr = new int[m * n];
      array = dynamicArr;
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
  }
  if (!input)
  {
    std::cerr << "Failed to read matrix dimensions\n";
    return 1;
  }
  if (!output.is_open())
  {
    std::cerr << "Failed to open output file\n";
    delete[] dynamicArr;
    return 1;
  }
  if (!sharifullina::inputMatrix(input, array, m, n, read))
  {
    std::cerr << "Invalid matrix element\n";
    delete[] dynamicArr;
    return 1;
  }
  output << sharifullina::countLocMax(array, m, n) << " ";
  output << sharifullina::countMaxSumMdg(array, m, n);
  output << "\n";
  delete[] dynamicArr;
}
