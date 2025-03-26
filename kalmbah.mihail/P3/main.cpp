#include <fstream>
#include "matrix_operation.hpp"

bool checkArgs(int argc, char** argv)
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
  if (!checkArgs(argc, argv))
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
  if (input.fail())
  {
    std::cerr << "Empty file or invalid matrix size\n";
    return 2;
  }

  if (cols == 0 || rows == 0)
  {
    std::ofstream output(argv[3]);
    output << "0 0\n";
    return 0;
  }

  int* matrix = nullptr;
  int staticMatrix[10000] = {};
  int* dynamicMatrix = nullptr;

  if (argv[1][0] == '1')
  {
    if (cols * rows > 10000)
    {
      std::cerr << "Matrix size exceeds static array limit\n";
      return 2;
    }
    matrix = staticMatrix;
  }
  else
  {
    dynamicMatrix = new (std::nothrow) int[cols * rows];
    if (!dynamicMatrix)
    {
      std::cerr << "Memory allocation failed\n";
      return 1;
    }
    matrix = dynamicMatrix;
  }

  try
  {
    kalmbah::inputMtx(input, matrix, cols, rows);
  }
  catch (const std::exception&)
  {
    std::cerr << "Invalid matrix data\n";
    if (argv[1][0] == '2') delete[] dynamicMatrix;
    return 2;
  }

  const size_t newCols = cols * 2;
  const size_t newRows = rows * 2;
  int* result = new (std::nothrow) int[newCols * newRows];
  if (!result)
  {
    std::cerr << "Memory allocation failed\n";
    if (argv[1][0] == '2') delete[] dynamicMatrix;
    return 1;
  }

  kalmbah::combineMatrices(matrix, result, cols, rows);

  std::ofstream output(argv[3]);
  kalmbah::outputMtx(output, result, newCols, newRows);

  if (argv[1][0] == '2') delete[] dynamicMatrix;
  delete[] result;
  return 0;
}
