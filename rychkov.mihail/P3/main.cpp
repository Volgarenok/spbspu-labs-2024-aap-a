#include <iostream>
#include <fstream>

#include "sum_sdg.hpp"
#include "get_matrix.hpp"
#include "arguments_parsing.hpp"

int main(int argc, char** argv)
{
  int testMode = 0;
  int parsingErrCode = rychkov::parseArguments(std::cerr, argc, argv, testMode);
  if (parsingErrCode != 0)
  {
    return parsingErrCode;
  }

  std::ifstream in(argv[2]);
  if (!in.is_open())
  {
    std::cerr << "failed to open input file\n";
    return 1;
  }
  std::ofstream out(argv[3]);
  if (!out.is_open())
  {
    std::cerr << "failed to open output file\n";
    return 1;
  }

  size_t height = 0, width = 0;
  if (!(in >> height >> width))
  {
    std::cerr << "failed to read matrix size\n";
    return 2;
  }

  constexpr size_t staticMatrixSize = 10'000;
  int staticMatrix[staticMatrixSize];
  int* matrix = staticMatrix;
  if (testMode == 2)
  {
    try
    {
      matrix = new int[height * width];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "failed to allocate memory\n";
      return 2;
    }
  }
  else
  {
    if (height * width > staticMatrixSize)
    {
      std::cerr << "matrix size is too big for task 1\n";
      return 1;
    }
  }

  size_t wereRead = 0;
  if (!rychkov::getMatrix(in, matrix, height, width, wereRead))
  {
    std::cerr << "failed to read matrix\n";
    if (testMode == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  std::cout << rychkov::getMaxSumSdg(matrix, height, width) << '\n';

  if (testMode == 2)
  {
    delete[] matrix;
  }
}
