#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include "matrix.h"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Invalid number of arguments.\n";
    return 1;
  }
  char* endptr = nullptr;
  int taskNumber = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0' || (taskNumber != 1 && taskNumber != 2))
  {
    std::cerr << "Error: Invalid task number.\n";
    return 1;
  }
  const char* inputFile = argv[2];
  const char* outputFile = argv[3];
  size_t rows = 0;
  size_t cols = 0;
  constexpr size_t max = 1000;
  int fixedArray[max] = {0};
  int* matrix = nullptr;

  try
  {
  if (taskNumber == 1)
  {
    matrix = fixedArray;
  }
  else
  {
    matrix = new int[max]();
  }
  std::ifstream inFile(inputFile);
  if (!inFile)
  {
    std::cerr << "Error: Cannot open input file.\n";
    delete[] matrix;
    return 1;
  }
  if (!cherkasov::readMatrix(inFile, rows, cols, matrix))
  {
    std::cerr << "Error: Invalid matrix data.\n";
    delete[] matrix;
    return 1;
  }
  int processResult = cherkasov::processMatrix(matrix, rows, cols);
  bool lowerTriangular = cherkasov::lowerTriangular(matrix, rows, cols);
  std::ofstream outFile(outputFile);
  if (!outFile)
  {
    std::cerr << "Error: Cannot open output file.\n";
    delete[] matrix;
    return 1;
  }
    outFile << "Result: " << processResult << "\n";
    outFile << (lowerTriangular ? "The matrix is lower triangular.\n"
                                   : "The matrix is not lower triangular.\n");
  delete[] matrix;
  return 0;
  }
  catch (const std::bad_alloc&)
  {
    std::cerr << "Error: Out of memory.\n";
    delete[] matrix;
    return 1;
  }
}
