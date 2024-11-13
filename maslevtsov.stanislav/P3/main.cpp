#include <fstream>
#include <stdexcept>
#include "matrix_functions.hpp"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Error: not enough arguments in command\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Error: too many arguments in command\n";
    return 1;
  }
  if ((argv[1][0] == '1' || argv[1][0] == '2') && argv[1][1] == '\0')
  {
    std::cerr << "Error: first argument of command must be 1 or 2";
  }

  std::ifstream finput(argv[2]);
  std::ofstream foutput(argv[3]);
  size_t nRows = 0, nColumns = 0;
  finput >> nRows >> nColumns;

  if (argv[1][0] == '1')
  {
    int matrix[10000] = {0};
    if (!maslevtsov::matrixInput(finput, matrix, nRows, nColumns))
    {
      std::cerr << "Error: incorrect input\n";
      return 2;
    }

    foutput << maslevtsov::countColumnsNSM(matrix, nRows, nColumns);
    foutput << '\n';
  }
  else if (argv[1][0] == '2')
  {
    int* matrix = nullptr;
    try
    {
      matrix = new int[nRows * nColumns];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Error: memory not allocated for matrix\n";
      return 1;
    }
    if (!maslevtsov::matrixInput(finput, matrix, nRows, nColumns))
    {
      std::cerr << "Error: incorrect input\n";
      delete[] matrix;
      return 2;
    }

    foutput << maslevtsov::countColumnsNSM(matrix, nRows, nColumns);
    foutput << '\n';

    delete[] matrix;
  }
}
