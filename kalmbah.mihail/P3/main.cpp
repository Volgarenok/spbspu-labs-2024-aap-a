#include <fstream>
#include "matrixOperation.hpp"

bool checkArgs(int argc, const char** argv)
{
  if (argc != 4)
  {
    std::cerr << "Usage: " << argv[0] << " <1|2> <input> <output>\n";
    return false;
  }
  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First argument must be 1 or 2\n";
    return false;
  }
  return true;
}

int main(int argc, char** argv)
{
  if (!checkArgs(argc, const_cast<const char**>(argv)))
  {
    return 1;
  }

  size_t cols = 0, rows = 0;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "Cannot open input file\n";
    return 2;
  }

  input >> cols >> rows;
  if (input.fail() || cols == 0 || rows == 0)
  {
    std::cerr << "Empty file or invalid matrix size\n";
    return 2;
  }

  int* matrix = nullptr;
  try
  {
    matrix = (argv[1][0] == '1') ? new int[10000]{} : new int[cols * rows]{};
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Memory allocation failed\n";
    return 1;
  }

  try
  {
    kalmbah::inputMtx(input, matrix, cols, rows);
  }
  catch (const std::exception&)
  {
    std::cerr << "Invalid matrix data\n";
    delete[] matrix;
    return 2;
  }

  int dummy;
  if (input >> dummy)
  {
    std::cerr << "Extra data in input file\n";
    delete[] matrix;
    return 2;
  }

  const size_t newCols = cols * 2;
  const size_t newRows = rows * 2;
  int* result = new int[newCols * newRows]{};
  kalmbah::combineMatrices(matrix, result, cols, rows);

  std::ofstream output(argv[3]);
  kalmbah::outputMtx(output, result, newCols, newRows);

  delete[] matrix;
  delete[] result;
  return 0;
}
