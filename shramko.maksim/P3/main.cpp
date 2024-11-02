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
  char* pEnd;
  long int number = 0;
  number = str::strtol(str, &pEnd, 10)

  if (number != 1 && number != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  for (size_t i = 0; i < strlen(str); ++i)
  {
    if (str[i] < "0" || str[i] > "9")
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }

  std::ifstream finput(argv[2]);
  std::ofstream foutput(argv[3]);

  size_t count_rows = 0;
  size_t count_coloumns = 0;

  finput >> count_rows >> count_coloumns;

  if (argv[1][0] == "1")
  {
    int mtrx[10000] = {0};
    if (!shramko::inputMtrx(finput, mtrx, count_rows, count_coloumns))
    {
      std::cerr << "ERROR!\n";
      return 2;
    }

    foutput << shramko::countGoodColoumns(mtrx, count_rows, count_coloumns) << "\n";
  }

  else if (argv[1][0] == "2")
  {
    int* mtrx = nullptr;
    try
    {
      mtrx = new int[count_rows * count_coloumns];
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
    if (!shramko::inputMtrx(finput, mtrx, count_rows, count_coloumns))
    {
      delete[] mtrx;
      std::cerr << "ERROR!\n";
      return 2;
    }

    foutput << shramko::countGoodColoumns(mtrx, count_rows, count_coloumns) << "\n";

    delete[] mtrx;
  }
}
