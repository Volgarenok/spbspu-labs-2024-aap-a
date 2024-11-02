#include "titleMatrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Incorrect amount of data entered" << "\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoi(argv[1][0]);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Invalid num" << "\n";
    return 1;
  }
  if (num != 1 || num != 2)
  {
    std::cerr << "Invalid value num" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input)
  {
    std::cerr << "Impossible to construct a matrix";
    return 2;
  }
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!(input >> m >> n) || m == 0 || n == 0)
  {
    std::cerr << "Invalid table size data" << "\n";
    return 2;
  }
  if (num == 1)
  {
    int table[1000];
    duhanina::inputMatrix(input, table, m, n);
    if (!(duhanina::inputMatrix(input, table, m, n)) && m != 0)
    {
      std::cerr << "Invalid input" << "\n";
      return 2;
    }
    duhanina::outputAnswer(output, table, m, n);
  }
  else
  {
    int * table = nullptr;
    try
    {
      table = new int[m * n];
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Error memory";
      return 1;
    }
    duhanina::inputMatrix(input, table, m, n);
    if (!(duhanina::inputMatrix(input, table, m, n)) && m != 0)
    {
      std::cerr << "Invalid input" << "\n";
      delete[] table;
      return 2;
    }
    duhanina::outputAnswer(output, table, m, n);
    delete[] table;
  }
  return 0;
}
