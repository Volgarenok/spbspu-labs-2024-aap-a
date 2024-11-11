#include "functionMatrix.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    if (argc > 4)
    {
      std::cerr << "Too many arguments" << "\n";
    return 1;
    }
    std::cerr << "Incorrect amount of data entered" << "\n";
    return 1;
  }
  char * ch = argv[1];
  if (!std::isdigit(ch))
  {
    std::cerr << "First parameter is not a number" << "\n";
    return 1;
  }
  int num = std::atoi(ch);
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
  if (num == 1)
  {
    size_t read = 0;
    int table[10000] = {0};
    if (!duhanina::inputMatrix(input, table, m, n, read) || read != (m * n))
    {
      std::cerr << "Invalid input" << "\n";
      return 2;
    }
    output << duhanina::minSumMdg(table, m, n) << "\n";
  }
  else if (num == 2)
  {
    size_t read = 0;
    int * table = nullptr;
    try
    {
      table = new int[m * n];
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Error memory" << "\n";
      return 1;
    }
    if (!duhanina::inputMatrix(input, table, m, n, read) || read != (m * n))
    {
      std::cerr << "Invalid input" << "\n";
      delete[] table;
      return 2;
    }
    output << duhanina::minSumMdg(table, m, n) << "\n";
    delete[] table;
  }
  return 0;
}
