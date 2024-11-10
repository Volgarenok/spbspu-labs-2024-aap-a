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
  {
    std::cerr << "Error: Invalid task number.\n";
    return 1;
  }

  const char* inputFile = argv[2];
  const char* outputFile = argv[3];
  int rows, cols;
  int** matrix = nullptr;
  bool useFixedArray = (num == 1);

  if (!cherkasov::readMatrix(inputFile, matrix, rows, cols, useFixedArray))
  {
    return 2;
  }
    int result = cherkasov::processMatrix(matrix, rows, cols);
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

