#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include "inputMtrx.hpp"
#include "countGoodColoumns.hpp"

int main(int argc, char** argv)
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

  const char* str = argv[1];

  for (size_t i = 0; i < strlen(str); i++)
  {
    if (str[i] < '0' || str[i] > '9')
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }

  char* pEnd;
  long int number = 0;
  number = std::strtol(str, &pEnd, 10);

  if (number != 1 && number != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);

  size_t cnt_row = 0;
  size_t cnt_col = 0;

  input >> cnt_row >> cnt_col;
  if (!input)
  {
    std::cerr << "Input error\n";
    return 2;
  }

  size_t sizeMtrx = cnt_row * cnt_col;

  if (argv[1][0] == 1)
  {
    int mtrx[10000];
    if (!shramko::inputMtrx(input, mtrx, sizeMtrx))
    {
      std::cerr << "ERROR!\n";
      return 2;
    }
    output << shramko::countGoodColoumns(mtrx, cnt_row, cnt_col) << "\n";
  }

  else
  {
    int* mtrx = nullptr;
    try
    {
      mtrx = new int[cnt_row * cnt_col];
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }

    if (!shramko::inputMtrx(input, mtrx, sizeMtrx))
    {
      delete[] mtrx;
      std::cerr << "ERROR!\n";
      return 2;
    }

    output << shramko::countGoodColoumns(mtrx, cnt_row, cnt_col) << "\n";
    delete[] mtrx;
  }
  return 0;
}
