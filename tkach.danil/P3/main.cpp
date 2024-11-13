#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include "filemtx.h"
#include "mtxlogic.h"

int main(int argc, const char** argv)
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
  const char * number = argv[1];
  int id = 0;
  id = std::atoi(number);
  for(size_t i = 0; i < std::strlen(argv[1]); ++i)
  {
    if (!std::isdigit(argv[1][i]))
    {
       std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }
  if ((id != 1) && (id != 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  size_t column_size = 0, row_size = 0;
  input >> row_size >> column_size;
  if (!input)
  {
    std::cerr << "ERROR: incorrect row_size/column_size value\n";
    return 1;
  }
  if (column_size == 1 && column_size == 1)
  {
    std::cerr << "ERROR: no other elements\n";
    return 1;
  }
  int fixmtx[10000] = {0};
  int* mtx = fixmtx;
  if (id == 2)
  {
    try
    {
      mtx = new int[row_size * column_size];
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
  }
  if (!(tkach::inputMtx(input, mtx, row_size, column_size)))
  {
    if (id == 2)
    {
      delete[] mtx;
    }
    std::cerr << "ERROR: Invalid input\n";
    return 2;
  }
  double* mtx2 = nullptr;
  try
  {
    mtx2 = tkach::buildNewMtxWithAverageElements(mtx, row_size, column_size);
  }
  catch (const std::bad_alloc& e)
  {
    if (id == 2)
    {
      delete[] mtx;
    }
    std::cerr << "Out of memory\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  tkach::outputMtx(output, mtx2, row_size, column_size);
  output << "\n";
  if (id == 2)
  {
    delete[] mtx;
  }
  delete[] mtx2;
  return 0;
}
