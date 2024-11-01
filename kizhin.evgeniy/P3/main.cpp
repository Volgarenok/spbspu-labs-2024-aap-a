#include "io_utils.hpp"
#include "matrix_utils.hpp"
#include "parse_arguments.hpp"
#include <cstddef>
#include <fstream>

int main(int argc, char** argv)
{
  char* inputFile = nullptr;
  char* outputFile = nullptr;
  int programmMode = 0;
  kizhin::parseArguments(
      std::cerr, argc, argv, &programmMode, &inputFile, &outputFile);

  std::ifstream in(inputFile);
  if (!in.is_open()) {
    std::cerr << "Can't open file to read\n";
    return 1;
  }
  size_t rows = 0;
  size_t columns = 0;
  if (!kizhin::readMatrixDimensions(in, &rows, &columns)) {
    std::cerr << "Can't read dimensions from file\n";
    return 1;
  }

  int* matrix = kizhin::allocateMatrix(rows, columns, programmMode);
  if (matrix == nullptr) {
    std::cerr << "Can't allocate memory\n";
    return 1;
  }
  if (!kizhin::readArrayValues(in, matrix, rows * columns)) {
    std::cerr << "Can't read matrix values from file\n";
    return 1;
  }
  in.close();

  std::ofstream out(outputFile);
  if (!out.is_open()) {
    std::cerr << "Can't open file to write\n";
    return 1;
  }
  size_t localMinimumCount = kizhin::countLocalMinimums(matrix, rows, columns);
  if (!kizhin::writeResultToFile(out, localMinimumCount)) {
    std::cerr << "Error during file writing\n";
    return 1;
  }
  out.close();
  if (programmMode == 1) {
    delete[] matrix;
  }
}
