#include <iostream>
#include <fstream>
#include <cstdlib>
#include "matrix.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Invalid number of arguments.\n";
    return 1;
  }
  int num = std::atoi(argv[1]);
  if (num != 1 && num != 2)
  char* endptr = nullptr;
  int taskNumber = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0' || (taskNumber != 1 && taskNumber != 2))
  {
    std::cerr << "Error: Invalid task number.\n";
    return 1;
  }
  const char* inFile = argv[2];
  const char* outputFile = argv[3];
  int rows, cols;
  int** matrix = nullptr;
  bool useFixedArray = (num == 1);

  if (!cherkasov::readMatrix(inputFile, matrix, rows, cols, useFixedArray))
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
      outFile.close();
      return 0;
  }

  int result = cherkasov::processMatrix(matrix, rows, cols);
    std::ifstream inputFile(inFile);
    if (!inputFile)
    {
      std::cerr << "Error: Cannot open input file.\n";
      return 1;
    }
    if (taskNumber == 1)
    {
      matrix = fixedArray;
    }
    else
    {
      dynamicArray = new int[max];
      matrix = dynamicArray;
    }
  int result = cherkasov::readMatrix(inputFile, rows, cols,  matrix);
  if (result != 0)
  {
    delete[] dynamicArray;
    return result;
  }
  int processResult = cherkasov::processMatrix(matrix, rows, cols);
  bool isLowerTriangular = cherkasov::isLowerTriangular(matrix, rows, cols);
  std::ofstream outFile(outputFile);
  if (!outFile)
  {
    std::cerr << "Error: Cannot open output file.\n";
    cherkasov::freeMatrix(matrix, rows);
    return 3;
  }

  outFile << result << "\n";
  outFile.close();

  cherkasov::freeMatrix(matrix, rows);
  return 0;
}

