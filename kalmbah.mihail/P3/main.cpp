#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include "get_matrix_operations.h"

int main(int argc, char **argv)
{
  if (argc != 4) {
    std::cerr << "Usage: " << argv[0] << " <num> <input_file> <output_file>\n";
    return 1;
  }
  std::string numStr = argv[1];
  if (!kalmbah::isNumber(numStr)) {
    std::cerr << "Error: num must be an integer (1 or 2).\n";
    return 1;
  }
  int num = std::stoi(numStr);
  if (num != 1 && num != 2) {
    std::cerr << "Error: num must be 1 (fixed size) or 2 (dynamic size).\n";
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  if (!inputFile) {
    std::cerr << "Error: Could not open input file.\n";
    return 2;
  }
  std::ofstream outputFile(argv[3]);
  if (!outputFile) {
    std::cerr << "Error: Could not open output file.\n";
    return 2;
  }
  std::string line;
  std::getline(inputFile, line);
  std::istringstream iss(line);
  std::string token;
  int rows, cols;
  if (!(iss >> rows)) {
    std::cerr << "Error: Invalid input format. Expected integer for rows.\n";
    return 2;
  }
  if (!(iss >> cols)) {
    std::cerr << "Error: Invalid input format. Expected integer for cols.\n";
    return 2;
  }

  const int nullMatrix = 0;
  if (rows == nullMatrix || cols == nullMatrix) {
    outputFile << "0\n";
    return 0;
  }

  if (rows < nullMatrix || cols < nullMatrix) {
    std::cerr << "Error: Matrix dimensions cannot be negative.\n";
    return 2;
  }
  const int maxNumbers = 10000;
  if (num == 1 && rows * cols > maxNumbers) {
    std::cerr << "Error: Fixed size array cannot exceed 10000 elements.\n";
    return 2;
  }
  if (num == 1) {
    const int maxSize = 100;
    int matrix[maxSize][maxSize] = {0};
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (!(iss >> matrix[i][j])) {
          std::cerr << "Error: Invalid input format. Expected integer for matrix element.\n";
          return 2;
        }
        if (matrix[i][j] < std::numeric_limits<int>::min() || matrix[i][j] > std::numeric_limits<int>::max()) {
          std::cerr << "Error: Matrix element exceeds int range.\n";
          return 2;
        }
      }
    }

    std::vector<std::vector<int>> result = kalmbah::createSymmetricMatrices(matrix, rows, cols);
    outputFile << result.size() << " " << result[0].size() << " ";
    for (const auto& row : result) {
      for (int val : row) {
        outputFile << val << " ";
      }
    }
    outputFile << "\n";

  } else {
    std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
    for (int i = 0; i < rows; ++i) {
      for (int j = 0; j < cols; ++j) {
        if (!(iss >> matrix[i][j])) {
          std::cerr << "Error: Invalid input format. Expected integer for matrix element.\n";
          return 2;
        }
        if (matrix[i][j] < std::numeric_limits<int>::min() || matrix[i][j] > std::numeric_limits<int>::max()) {
          std::cerr << "Error: Matrix element exceeds int range.\n";
          return 2;
        }
      }
    }
    std::vector<std::vector<int>> result = kalmbah::createSymmetricMatrices(matrix);
    outputFile << result.size() << " " << result[0].size() << " ";
    for (const auto& row : result) {
      for (int val : row) {
        outputFile << val << " ";
      }
    }
    outputFile << "\n";
  }
  return 0;
}
