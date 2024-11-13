#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include "inputMtrx.hpp"
#include "countColoumnsWithNonRepeatingNumbers.hpp"

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

  if ((argv[1][0] != '1' && argv[1][0] != '2') || (argv[1][1] != '\0'))
  {
    std::cerr << "First parameter is not the right number\n";
    return 1;
  }

  size_t cnt_col = 0, cnt_row = 0;
  std::ifstream input(argv[2]);
  input >> cnt_row >> cnt_col;
  if (!input)
  {
    std::cerr << "Input error\n";
    return 2;
  }

  size_t sizeMtrx = cnt_row * cnt_col;
  constexpr size_t statMtrxSize = 10000;
  int statMtrx[statMtrxSize];
  int* mtrx = statMtrx;
  std::ofstream output(argv[3]);
  if (argv[1][0] == '2')
  {
    try
    {
      mtrx = new int[sizeMtrx];
    }
    catch (const std::bad_alloc & e)
    {
      delete[] mtrx;
      std::cerr << "Out of memory\n";
      return 2;
    }
    if (!shramko::inputMtrx(input, mtrx, sizeMtrx))
    {
      delete[] mtrx;
      std::cerr << "Dyn error!\n";
      return 2;
    }
    output << shramko::countColoumnsWithNonRepeatingNumbers(mtrx, cnt_row, cnt_col) << "\n";
  }
  else if (argv[1][0] == '1')
  {
    if(!shramko::inputMtrx(input, mtrx, sizeMtrx))
    {
      std::cerr << "Sta error!\n";
      return 2;
    }
    output << shramko::countColoumnsWithNonRepeatingNumbers(mtrx, cnt_row, cnt_col) << "\n";
  }
}
