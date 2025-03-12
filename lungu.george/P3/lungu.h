#ifndef LUNGU_H
#define LUNGU_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <utility>

namespace lungu
{
  bool validateArguments(int argc, char *argv[]);
  std::pair<int, int> readMatrixFromFile(const std::string &filename, int *matrix, int maxSize);
  void processFixedSizeMatrix(const std::string &inputFile, const std::string &outputFilename);
  void transformMatrix(int *matrix, int rows, int cols);
  void writeMatrixToFile(const std::string &filename, const int *matrix, int rows, int cols);
  void processDynamicMatrix(const std::string &inputFilename, const std::string &outputFilename);
}
#endif
