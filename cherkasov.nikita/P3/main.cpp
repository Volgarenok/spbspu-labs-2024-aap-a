#include <iostream>
#include <cstdlib>
#include <fstream>
#include "matrix.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Invalid number of arguments.\n";
    return 1;
  }

  const std::string taskNumStr = argv[1];
  if (taskNumStr != "1" && taskNumStr != "2")
  {
    std::cerr << "Error: Invalid task number.\n";
    return 1;
  }

  int num = std::atoi(argv[1]);
  const char* inputFile = argv[2];
  const char* outputFile = argv[3];
  size_t rows, cols;
  bool useFixedArray = (num == 1);

  int** matrix = cherkasov::readMatrix(inputFile, rows, cols, useFixedArray);
  if (matrix == nullptr)
  {
    return 2;
  }

  if (rows == 0 || cols == 0)
  {
    std::ofstream outFile(outputFile);
    if (!outFile)
    {
      std::cerr << "Error: Cannot open output file.\n";
      return 3;
    }
    outFile << 0 << "\n";
    return 0;
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

