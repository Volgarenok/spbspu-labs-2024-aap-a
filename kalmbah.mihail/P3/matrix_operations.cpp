#include "matrix_operations.h"

std::vector<std::vector<int>> createSymmetricMatrices(const std::vector<std::vector<int>>& matrix) {
  int rows = matrix.size();
  int cols = matrix[0].size();
  std::vector<std::vector<int>> result(2 * rows, std::vector<int>(2 * cols));
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      result[i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      result[2 * rows - 1 - i][j] = matrix[i][j];
    }
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      result[i][2 * cols - 1 - j] = matrix[i][j];
    }
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      result[2 * rows - 1 - i][2 * cols - 1 - j] = matrix[i][j];
    }
  }
  return result;
}
