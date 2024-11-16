#include <iostream>
#include <fstream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
#include "inputMtrx.hpp"
#include "countColoumnsWithNonRepeatingNumbers.hpp"

int main(const int argc, const char** argv)
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
  int fixedMtrx[10000] = {};
  int* mtrx = fixedMtrx;
  int* ptr = nullptr;
  if (argv[1][0] == '2')
  {
    try
    {
      mtrx = new int[sizeMtrx];
      ptr = mtrx;
    }
    catch (const std::bad_alloc& e)
    {
      delete[] ptr;
      std::cerr << "Out of memory\n";
      return 2;
    }
  }

  if (!shramko::inputMtrx(input, mtrx, sizeMtrx))
  {
    delete[] ptr;
    std::cerr << "Input error!\n";
    return 2;
  }

  std::ofstream output(argv[3]);
  output << shramko::countColoumnsWithNonRepeatingNumbers(mtrx, cnt_row, cnt_col) << "\n";
  delete[] ptr;
}
