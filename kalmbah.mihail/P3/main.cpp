#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "matrix_operations.h"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <input_file> <output_file>\n";
    return 1;
  }
  std::ifstream inputFile(argv[1]);
  if (!inputFile) {
    std::cerr << "Error: Could not open input file.\n";
    return 2;
  }
  std::ofstream outputFile(argv[2]);
  if (!outputFile) {
    std::cerr << "Error: Could not open output file.\n";
    return 2;
  }
  std::string line;
  std::getline(inputFile, line);
  std::istringstream iss(line);
  int rows, cols;
  iss >> rows >> cols;
  std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));
  for (int i = 0; i < rows; ++i) {
    std::string rowStr;
    iss >> rowStr;
    for (int j = 0; j < cols; ++j) {
      matrix[i][j] = rowStr[j] - '0';
    }
  }
  std::vector<std::vector<int>> result = createSymmetricMatrices(matrix);
  outputFile << result.size() << " " << result[0].size() << " ";
  for (const auto& row : result) {
    for (int val : row) {
      outputFile << val;
    }
    outputFile << " ";
  }
  return 0;
}
