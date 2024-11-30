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
    int taskNumber = std::strtol(argv[1], &endptr, 10);
    if (*endptr != '\0' || (taskNumber != 1 && taskNumber != 2))
    {
      std::cerr << "Error: Invalid task number.\n";
      return 1;
    }

  const char* inputFile = argv[2];
  const char* outputFile = argv[3];
  size_t rows = 0, cols = 0;
  bool useFixedArray = (taskNumber == 1);
  constexpr size_t max = 1000;
  int fixedArray[max] = {0};
  int* dynamicArray = nullptr;
  int* matrix = (useFixedArray ? fixedArray : nullptr);
  try
  {
    if (!useFixedArray)
    {
      matrix = new int[max];
    }

  if (taskNumber == 2)
  {
    dynamicArray = new int[max];
    matrix = dynamicArray;
  }

  if (cherkasov::readMatrix(inputFile, rows, cols, taskNumber == 1, matrix) != 0)
  {
    delete[] dynamicArray;
    return 1;
  }

  int result = cherkasov::readMatrix(inputFile, rows, cols, useFixedArray, matrix);
  if (result != 0)
  {
    delete[] dynamicArray;
    return result;
  }
    int processResult = cherkasov::processMatrix(matrix, rows, cols);
    bool isLowerTriangular = cherkasov::lowerTriangul(matrix, rows, cols);
    std::ofstream outFile(outputFile);
    if (!outFile)
    {
      std::cerr << "Error: Cannot open output file.\n";
      delete[] dynamicArray;
      return 1;
    }
      outFile << "Result: " << processResult << "\n";
      if (isLowerTriangular)
      {
        outFile << "The matrix is lower triangular.\n";
      }
        else
        {
          outFile << "The matrix is not lower triangular.\n";
        }
  }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Error: Out of memory.\n";
      delete[] dynamicArray;
      return 1;
    }
      delete[] dynamicArray;
      return 0;
}
