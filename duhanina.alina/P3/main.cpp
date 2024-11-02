#include "titleMatrix.h"
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
  if (!duhanina::isDig(ch))
  {
    std::cerr << "First parameter is not a number" << "\n";
    return 1;
  }
  int num = atoi(ch);
  if (!(num == 1 || num == 2))
  {
    std::cerr << "First parameter is out of range" << "\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (!input)
  {
    std::cerr << "Impossible to construct a matrix" << "\n";
    return 2;
  }
  size_t read = 0;
  size_t m = 0, n = 0;
  input >> m >> n;
  if (num == 1)
  {
    int table[1000];
    duhanina::inputMatrix(input, table, m, n, read);
    if (!(duhanina::inputMatrix(input, table, m, n, read)))
    {
      std::cerr << "Invalid input" << "\n";
      return 2;
    }
    if (input && read == m * n)
    {
      output << duhanina::outputAnswer(table, m, n) << "\n";
    }
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
      std::cerr << "Error memory" << "\n";
      return 1;
    }
    duhanina::inputMatrix(input, table, m, n, read);
    if (!(duhanina::inputMatrix(input, table, m, n, read)))
    {
      std::cerr << "Invalid input" << "\n";
      delete[] table;
      return 2;
    }
    if (input && read == m * n)
    {
      output << duhanina::outputAnswer(table, m, n) << "\n";
    }
    delete[] table;
  }
  return 0;
}
