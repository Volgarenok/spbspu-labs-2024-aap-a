#ifndef MATRIXINPUTANDPROCESSING_HPP
#define MATRIXINPUTANDPROCESSING_HPP

#include <fstream>
#include <iostream>
namespace krylov
{
  std::istream & inputMatrix(std::istream & in, int * matrix, size_t rows, size_t columns);
  int getColumnWithMaxEquals(int * matrix, size_t rows, size_t columns);
}

#endif


