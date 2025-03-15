#include "get_matrix_operations.h"

namespace kalmbah
{

bool isNumber(const std::string& str)
{
  for (char const& c : str) {
    if (!isdigit(c) && c != '-') {
      return false;
    }
  }
  return true;
}

std::vector<std::vector<int>> createSymmetricMatrices(const std::vector<std::vector<int>>& matrix)
{
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

std::vector<std::vector<int>> createSymmetricMatrices(const int matrix[100][100], int rows, int cols)
{
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

}
