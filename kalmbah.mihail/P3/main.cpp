#include <iostream>
#include <fstream>
#include <cstring>
#include "get_matrix_operations.h"
#include "input_checks.h"

int main(int argc, char ** argv)
{
  const int maxNumbArg = 4;
  if (argc != maxNumbArg)
  {
    std::cerr << "Usage: " << argv[0] << " <num> <input_file> <output_file>\n";
    return 1;
  }

  std::string numStr = argv[1];
  if (!kalmbah::isNumber(numStr))
  {
    std::cerr << "Error: num must be an integer (1 or 2).\n";
    return 1;
  }

  int num = std::stoi(numStr);
  if (num != 1 && num != 2)
  {
    std::cerr << "Error: num must be 1 (fixed size) or 2 (dynamic size).\n";
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  if (!inputFile)
  {
    std::cerr << "Error: Could not open input file.\n";
    return 2;
  }

  if (kalmbah::isInputFileEmpty(inputFile))
  {
    std::cerr << "Error: Input file is empty.\n";
    return 2;
  }

  std::ofstream outputFile(argv[3]);
  if (!outputFile)
  {
    std::cerr << "Error: Could not open output file.\n";
    return 2;
  }

  std::string line;
  std::getline(inputFile, line);

  char * token = std::strtok(const_cast<char*>(line.c_str()), " ");
  int rows = std::stoi(token);
  token = std::strtok(nullptr, " ");
  int cols = std::stoi(token);

  if (!kalmbah::isValidMatrixSize(rows, cols))
  {
    std::cerr << "Error: Matrix dimensions cannot be negative.\n";
    return 2;
  }

  const int nullMatrix = 0;
  if (rows == nullMatrix || cols == nullMatrix)
  {
    outputFile << "0\n";
    return 0;
  }

  const int fixedMaxSize = 10000;
  if (num == 1 && rows * cols > fixedMaxSize)
  {
    std::cerr << "Error: Fixed size array cannot exceed 10000 elements.\n";
    return 2;
  }

  if (num == 1)
  {
    const int maxRows = 100;
    const int maxCols = 100;
    int matrix[maxRows][maxCols] = {0};
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        token = std::strtok(nullptr, " ");
        if (!token)
        {
          std::cerr << "Error: Invalid input format. Expected integer for matrix element.\n";
          return 2;
        }
        int value = std::stoi(token);
        if (!kalmbah::isValidMatrixElement(value))
        {
          std::cerr << "Error: Matrix element exceeds int range.\n";
          return 2;
        }
        matrix[i][j] = value;
      }
    }

    int result[200][200];
    kalmbah::createSymmetricMatrices(matrix, result, rows, cols);
    kalmbah::printMatrix(result, 2 * rows, 2 * cols, outputFile);
  }
  else
  {
    int * matrix = new int[rows * cols];
    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        token = std::strtok(nullptr, " ");
        if (!token)
        {
          std::cerr << "Error: Invalid input format. Expected integer for matrix element.\n";
          delete[] matrix;
          return 2;
        }
        int value = std::stoi(token);
        if (!kalmbah::isValidMatrixElement(value))
        {
          std::cerr << "Error: Matrix element exceeds int range.\n";
          delete[] matrix;
          return 2;
        }
        matrix[i * cols + j] = value;
      }
    }

    int * result = new int[4 * rows * cols];
    kalmbah::createSymmetricMatrices(matrix, result, rows, cols);
    kalmbah::printMatrix(result, 2 * rows, 2 * cols, outputFile);

    delete[] matrix;
    delete[] result;
  }

  return 0;
}
