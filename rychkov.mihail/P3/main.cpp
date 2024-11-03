#include <iostream>
#include <fstream>
#include <new>

#include "sum_sdg.hpp"
#include "get_matrix.hpp"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "too many arguments\n";
    return 1;
  }
  if (*argv[1] == '\0')
  {
    std::cerr << "first argument is empty\n";
    return 1;
  }
  if ((argv[1][1] != '\0') || ((argv[1][0] != '1') && (argv[1][0] != '2')))
  {
    std::cerr << "first argument is not a number of a task\n";
    return 1;
  }
  int taskNumber = argv[1][0] - '0';

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
    in.close();
    return 1;
  }

  size_t height = 0, width = 0;
  if (!(in >> height >> width))
  {
    std::cerr << "failed to read matrix size\n";
    return 1;
  }

  constexpr size_t staticMatrixSize = 10'000;
  int staticMatrix[staticMatrixSize];
  int* matrix = staticMatrix;
  if (taskNumber == 2)
  {
    try
    {
      matrix = new int[height * width];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "failed to allocate memory\n";
      in.close();
      out.close();
      return 2;
    }
  }
  else
  {
    if(height * width > staticMatrixSize)
    {
      std::cerr << "matrix size is too big for task 1\n";
      in.close();
      out.close();
      return 1;
    }
  }
  
  size_t wereRead = 0;
  if (!rychkov::getMatrix(in, matrix, height, width, wereRead))
  {
    std::cerr << "failed to read matrix\n";
    in.close();
    out.close();
    if (taskNumber == 2)
    {
      delete[] matrix;
    }
    return 1;
  }
  std::cout << rychkov::getMaxSumSdg(matrix, height, width) << '\n';

  in.close();
  out.close();
  if (taskNumber == 2)
  {
    delete[] matrix;
  }
}
