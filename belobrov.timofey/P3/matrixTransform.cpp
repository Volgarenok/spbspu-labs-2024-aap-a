#include "matrixTransform.hpp"
#include <algorithm>

void belobrov::incrementMatrixLayers(int* matrix, size_t rows, size_t cols)
{
  size_t layers = std::min(rows, cols) / 2;

  for (size_t layer = 0; layer < layers; ++layer) {
    int increment = layer + 1;
    for (size_t i = layer; i < cols - layer; ++i) {
      matrix[layer * cols + i] += increment;
      matrix[(rows - layer - 1) * cols + i] += increment;
    }
    for (size_t i = layer + 1; i < rows - layer - 1; ++i) {
      matrix[i * cols + layer] += increment;
      matrix[i * cols + (cols - layer - 1)] += increment;
    }
  }

  if (rows % 2 != 0 && cols % 2 != 0) {
    size_t centerRow = rows / 2;
    size_t centerCol = cols / 2;
    matrix[centerRow * cols + centerCol] += layers + 1;
  }
}
