#include "exit_codes.hpp"
#include "io_utils.hpp"
#include "matrix_utils.hpp"
#include "memory_modes.hpp"
#include "parse_arguments.hpp"
#include <cstddef>
#include <fstream>

int main(int argc, char** argv)
{
  char* inputFile = nullptr;
  char* outputFile = nullptr;
  kizhin::MemoryMode mode = kizhin::MemoryMode::null;
  kizhin::parseArguments(std::cerr, argc, argv, &mode, &inputFile, &outputFile);

  std::ifstream in(inputFile);
  if (!in.is_open()) {
    std::cerr << "Can't open file to read\n";
    return static_cast<int>(kizhin::ExitCode::failFile);
  }
  size_t rows = 0;
  size_t columns = 0;
  if (!kizhin::readMatrixDimensions(in, &rows, &columns)) {
    std::cerr << "Can't read dimensions from file\n";
    return static_cast<int>(kizhin::ExitCode::failFile);
  }

  int* matrix = kizhin::allocateMatrix(rows, columns, mode);
  if (matrix == nullptr) {
    std::cerr << "Can't allocate memory\n";
    return static_cast<int>(kizhin::ExitCode::failFile);
  }
  if (!kizhin::readArrayValues(in, matrix, rows * columns)) {
    std::cerr << "Can't read matrix values from file\n";
    return static_cast<int>(kizhin::ExitCode::failFile);
  }
  in.close();

  std::ofstream out(outputFile);
  if (!out.is_open()) {
    std::cerr << "Can't open file to write\n";
    return static_cast<int>(kizhin::ExitCode::failFile);
  }
  size_t localMinimumCount = kizhin::countLocalMinimums(matrix, rows, columns);
  if (!kizhin::writeResultToFile(out, localMinimumCount)) {
    std::cerr << "Error during file writing\n";
    return static_cast<int>(kizhin::ExitCode::failFile);
  }
  out.close();
  if (mode == kizhin::MemoryMode::freeStore) {
    delete[] matrix;
  }
}
