#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include "inputMtx.h"
#include "minSumMdg.h"

int main(int argc, char ** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Few arguments" << "\n";
    return 1;
  }
  if (!std::isdigit(argv[1][0]) || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  int num = std::atoi(argv[1]);
  if (!(num == 1 || num == 2))
  {
    std::cerr << "First parameter is out of range" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!input)
  {
    std::cerr << "File is empty" << "\n";
    return 2;
  }
  if (m * n == 0)
  {
    output << "0\n";
    return 0;
  }
  size_t read = 0;
  int stat_mtx[10000] = {};
  int * matrix = nullptr;
  int * dyn_mtx = nullptr;
  if (num == 1)
  {
    matrix = stat_mtx;
  }
  else if (num == 2)
  {
    try
    {
      dyn_mtx = new int[m * n];
      matrix = dyn_mtx;
    }
    catch (const std::bad_alloc & e)
    {
      delete[] dyn_mtx;
      std::cerr << "Error memory" << "\n";
      return 1;
    }
  }
  if (!duhanina::inputMatrix(input, matrix, m, n, read) || read != (m * n))
  {
    std::cerr << "Invalid input" << "\n";
    delete[] dyn_mtx;
    return 2;
  }
  output << duhanina::minSumMdg(matrix, m, n) << "\n";
  delete[] dyn_mtx;
  return 0;
}
