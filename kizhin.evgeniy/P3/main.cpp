#include <fstream>
#include <iostream>
#include "matrix_utils.hpp"
#include "parse_arguments.hpp"

int main(int argc, char** argv)
{
  kizhin::MemoryMode memoryMode;
  try {
    kizhin::checkArgumentsCount(argc);
    memoryMode = kizhin::parseMemoryMode(argv[1]);
  } catch (const std::logic_error& ex) {
    std::cerr << ex.what() << '\n';
    return 1;
  }
  const char* inputFilePath = argv[2];
  const char* outputFilePath = argv[3];

  int* memoryFreeStore = nullptr;
  try {
    std::ifstream in(inputFilePath);
    if (!in) {
      throw std::logic_error("Failed to open input file");
    }
    int rows = 0;
    int columns = 0;
    if (!(in >> rows >> columns) || rows < 0 || columns < 0) {
      throw std::logic_error("Failed to read matrix dimensions");
    }
    constexpr size_t stackBufferSize = 10'000;
    int stackBuffer[stackBufferSize];
    const size_t size = rows * columns;
    memoryFreeStore = memoryMode == kizhin::MemoryMode::stack ? nullptr : new int[size + 2];
    int* matrix = memoryMode == kizhin::MemoryMode::stack ? stackBuffer : memoryFreeStore;
    matrix[0] = rows;
    matrix[1] = columns;
    if (kizhin::readArrayValues(in, matrix + 2, size) != size) {
      throw std::logic_error("Failed to read matrix values");
    }

    std::ofstream out(outputFilePath);
    if (!out) {
      throw std::logic_error("Failed to open ouput file");
    }
    out << kizhin::countLocalMaximums(matrix);
  } catch (const std::exception& ex) {
    delete[] memoryFreeStore;
    std::cerr << ex.what() << '\n';
    return 2;
  }
  delete[] memoryFreeStore;
}
