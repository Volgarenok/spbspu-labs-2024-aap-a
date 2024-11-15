#include <iostream>
#include <fstream>
#include "filemtx.h"
#include "mtxlogic.h"

int main(const int argc, const char* const * const argv)
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
  int id = std::atoi(number);
  if (argv[1][0] == '\0')
  {
    std::cerr << "First parameter is empty\n";
    return 1;
  }
  if (((id != 1) && (id != 2)) || (argv[1][1] != '\0'))
  {
    std::cerr << "First parameter is wrong\n";
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
  int* memorypointer = nullptr;
  double* mtx2 = nullptr;
  try
  {
    if (id == 2)
    {
      mtx = new int[row_size * column_size];
      memorypointer = mtx;
    }
    mtx2 = new double[row_size * column_size];
  }
  catch (const std::bad_alloc & e)
  {
    delete[] memorypointer;
    std::cerr << "Out of memory\n";
    return 1;
  }
  if (!(tkach::inputMtx(input, mtx, row_size, column_size)))
  {
    delete[] memorypointer;
    delete[] mtx2;
    std::cerr << "ERROR: Invalid input\n";
    return 2;
  }
  tkach::buildNewMtxWithAverageElements(mtx, mtx2, row_size, column_size);
  std::ofstream output(argv[3]);
  tkach::outputMtx(output, mtx2, row_size, column_size);
  output << "\n";
  delete[] memorypointer;
  delete[] mtx2;
  return 0;
}
