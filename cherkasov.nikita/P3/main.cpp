#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "matrix.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Invalid number of arguments.\n";
    return 1;
  }

  char* endptr;
  int num = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0' || (num != 1 && num != 2))
  {
    std::cerr << "Error: Invalid task number.\n";
    return 1;
  }

  const char* inputFile = argv[2];
  const char* outputFile = argv[3];
  size_t rows = 0, cols = 0;
  bool useFixedArray = (num == 1);

  int** matrix = cherkasov::readMatrix(inputFile, rows, cols, useFixedArray);
  if (!matrix)
  {
    if (rows == 0 && cols == 0)
    {
       return 0;
    }
    std::cerr << "Error: Invalid matrix format or dimensions.\n";
    return 2;
  }

  int result = cherkasov::processMatrix(matrix, rows, cols);
  bool isLowerTriangular = cherkasov::lowerTriangul(matrix, rows, cols);
  std::ofstream outFile(outputFile);
  if (!outFile)
  {
    std::cerr << "Error: Cannot open output file.\n";
    cherkasov::freeMatrix(matrix, rows);
    return 3;
  }

  outFile << "Result: " << result << "\n";
  if (isLowerTriangular)
  {
    outFile << "The matrix is lower triangular.\n";
  }
  else
  {
    outFile << "The matrix is not lower triangular.\n";
  }

  cherkasov::freeMatrix(matrix, rows);
  return 0;
}
