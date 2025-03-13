#include "lungu.h"
#include <utility>

namespace lungu
{
  void processFixedSizeMatrix(const std::string &inputFilename, const std::string &outputFilename)
  {
    const int maxSize = 10000;
    int matrix[maxSize];

    std::pair<int, int> dimensions = readMatrixFromFile(inputFilename, matrix, maxSize);
    int rows = dimensions.first;
    int cols = dimensions.second;

    transformMatrix(matrix, rows, cols);

    writeMatrixToFile(outputFilename, matrix, rows, cols);
  }
}
