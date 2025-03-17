#include <iostream>
#include <fstream>
#include <cstring>
#include <limits>
#include "get_matrrix_operations.h"

int main(int argc, char **argv)
{
  const int valueArg = 4;
  if (argc != valueArg)
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

  std::ofstream outputFile(argv[3]);
  if (!outputFile)
  {
    std::cerr << "Error: Could not open output file.\n";
    return 2;
  }

  std::string line;
  std::getline(inputFile, line);

  char* token = std::strtok(const_cast<char*>(line.c_str()), " ");
  int rows = std::stoi(token);
  token = std::strtok(nullptr, " ");
  int cols = std::stoi(token);

  const int nullMatrix = 0;
  if (rows == nullMatrix || cols == nullMatrix)
  {
    outputFile << "0\n";
    return 0;
  }

  if (rows < nullMatrix || cols < nullMatrix)
  {
    std::cerr << "Error: Matrix dimensions cannot be negative.\n";
    return 2;
  }

  const int maxValueMatrix = 10000;
  if (num == 1 && rows * cols > maxValueMatrix)
  {
    std::cerr << "Error: Fixed size array cannot exceed 10000 elements.\n";
    return 2;
  }

  if (num == 1)
  {
    int matrix[100][100] = {0};
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
        matrix[i][j] = std::stoi(token);
        if (matrix[i][j] < std::numeric_limits<int>::min() || matrix[i][j] > std::numeric_limits<int>::max())
        {
          std::cerr << "Error: Matrix element exceeds int range.\n";
          return 2;
        }
      }
    }

    int result[200][200];
    kalmbah::createSymmetricMatrices(matrix, result, rows, cols);

    outputFile << (2 * rows) << " " << (2 * cols) << " ";
    for (int i = 0; i < 2 * rows; ++i)
    {
      for (int j = 0; j < 2 * cols; ++j)
      {
        outputFile << result[i][j] << " ";
      }
    }
    outputFile << "\n";
  }
  else
  {
    int* matrix = new int[rows * cols];
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
        matrix[i * cols + j] = std::stoi(token);
        if (matrix[i * cols + j] < std::numeric_limits<int>::min() || matrix[i * cols + j] > std::numeric_limits<int>::max())
        {
          std::cerr << "Error: Matrix element exceeds int range.\n";
          delete[] matrix;
          return 2;
        }
      }
    }

    int* result = new int[4 * rows * cols];
    kalmbah::createSymmetricMatrices(matrix, result, rows, cols);

    outputFile << (2 * rows) << " " << (2 * cols) << " ";
    for (int i = 0; i < 2 * rows; ++i)
    {
      for (int j = 0; j < 2 * cols; ++j)
      {
        outputFile << result[i * (2 * cols) + j] << " ";
      }
    }
    outputFile <<"/n";

    delete[] matrix;
    delete[] result;
  }

  return 0;
}
