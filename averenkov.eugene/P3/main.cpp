#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstring>
#include <cctype>
#include <algorithm>
#include "matrixFunc.h"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "too many arguments\n";
    return 1;
  }
  if (!std::isdigit(argv[1][0]))
  {
    std::cerr << "not a number or beyond the limit\n";
    return 1;
  }
  if (std::strcmp(argv[1], "1") != 0 && std::strcmp(argv[1], "2") != 0)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t m = 0, n = 0, read = 0;
  input >> m;
  input >> n;
  int* dynarray = nullptr;
  if (std::atoi(argv[1]) == 1)
  {
    int matrix[10000] = {0};
    if (!averenkov::input_matrix(input, matrix, m, n, read) || read != m * n)
    {
      std::cerr << "Read fail\n";
      return 2;
    }
    averenkov::output_answer(output, matrix, m, n);
  }
  else
  {
    int* matrix = nullptr;
    try
    {
      dynarray = new int[m * n];
      matrix = dynarray;
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Memory error\n";
      return 1;
    }
    if (!averenkov::input_matrix(input, matrix, m, n, read) || read != m * n)
    {
      std::cerr << "Read fail\n";
      delete[] dynarray;
      return 2;
    }
    averenkov::output_answer(output, matrix, m, n);
  }
  delete[] dynarray;
  return 0;
}

