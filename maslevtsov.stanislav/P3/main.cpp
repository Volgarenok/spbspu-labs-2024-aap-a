#include <fstream>
#include <stdexcept>
#include "input_matrix.hpp"
#include "columns_nsm.hpp"

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
  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "Error: first argument of command must be 1 or 2";
    return 1;
  }

  std::ifstream finput(argv[2]);
  std::ofstream foutput(argv[3]);
  size_t nRows = 0, nColumns = 0;
  finput >> nRows >> nColumns;

  int fixedLengthArray[10000] = {0};
  int* dynamicArray = nullptr;
  int* matrix = nullptr;
  if (argv[1][0] == '1')
  {
    matrix = fixedLengthArray;
  }
  else
  {
    try
    {
      dynamicArray = new int[nRows * nColumns];
    }
    catch (const std::bad_alloc& e)
    {
      std::cerr << "Error: memory not allocated for matrix\n";
      return 1;
    }
    matrix = dynamicArray;
  }

  if (!maslevtsov::inputMatrix(finput, matrix, nRows, nColumns))
  {
    std::cerr << "Error: incorrect input\n";
    delete[] dynamicArray;
    return 2;
  }

  foutput << maslevtsov::countColumnsNSM(matrix, nRows, nColumns);
  foutput << '\n';

  delete[] dynamicArray;
}
