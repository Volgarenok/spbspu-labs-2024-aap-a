#include <iostream>
#include <fstream>
#include "matrix.h"

int main(int argc, char ** argv)
{
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  for (size_t i = 0; argv[1][i] != '\0'; ++i)
  {
    if (!std::isdigit(argv[1][i]))
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }

  const int num = std::atoi(argv[1]);
  std::ifstream inputStream(argv[2]);
  std::ofstream outputStream(argv[3]);

  size_t m = 0, n = 0;
  inputStream >> m >> n;
  if (!inputStream)
  {
    std::cout << "File text is invalid\n";
    return 2;
  }
  outputStream << m << ' ' << n;
  switch (num)
  {
  case 1:
  {
    int table[10000];
    savintsev::processMtx(inputStream, outputStream, table, m, n);
    break;
  }
  case 2:
  {
    int * table = new int[n * m];
    savintsev::processMtx(inputStream, outputStream, table, m, n);
    delete[] table;
    break;
  }
  default:
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
}
