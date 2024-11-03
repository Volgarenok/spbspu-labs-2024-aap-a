#include <fstream>
#include <iostream>
#include "matrix_utils.hpp"
#include "parse_arguments.hpp"

int main(int argc, char** argv)
{
  kizhin::MemoryMode mode;
  try {
    kizhin::checkArgumentsCount(argc);
    mode = kizhin::parseMemoryMode(argv[1]);
  } catch (const std::logic_error& error) {
    std::cerr << error.what() << '\n';
    return 1;
  }
  const char* inputFilePath = argv[2];
  const char* outputFilePath = argv[3];

  constexpr size_t stackSize = 10'000;
  static int stackBuffer[stackSize];
  int* matrix = nullptr;
  try {
    std::ifstream in(inputFilePath);
    if (!in.is_open()) {
      throw std::logic_error("Failed to open input file");
    }
    int rows = 0;
    int columns = 0;
    if (!(in >> rows >> columns) || rows < 0 || columns < 0) {
      throw std::logic_error("Failed to read matrix dimensions");
    }
    const size_t size = rows * columns;
    matrix = kizhin::allocateArray(size + 2, stackBuffer, stackSize, mode);
    matrix[0] = rows;
    matrix[1] = columns;
    if (!kizhin::readArrayValues(in, matrix + 2, size)) {
      throw std::logic_error("Failed to read matrix values");
    }

    std::ofstream out(outputFilePath);
    if (!out.is_open()) {
      throw std::logic_error("Failed to open ouput file");
    }
    out << kizhin::countLocalMaximums(matrix);
  } catch (const std::exception& error) {
    kizhin::deallocateArray(matrix, mode);
    std::cerr << error.what() << '\n';
    return 2;
  }
  kizhin::deallocateArray(matrix, mode);
}
