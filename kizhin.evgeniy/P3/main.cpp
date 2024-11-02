#include "matrix_utils.hpp"
#include "memory_utils.hpp"
#include "parse_arguments.hpp"
#include <fstream>
#include <iostream>

int main(int argc, char** argv)
{
  enum class ExitCode { failArguments = 1, failFile = 2 };

  kizhin::MemoryMode mode = kizhin::MemoryMode::null;
  char* fileIn = nullptr;
  char* fileOut = nullptr;
  try {
    kizhin::checkArgumentsCount(argc);
    mode = kizhin::parseProgrammMode(argv[1]);
    fileIn = argv[2];
    fileOut = argv[3];
  } catch (const std::logic_error& error) {
    std::cerr << error.what() << '\n';
    return static_cast<int>(ExitCode::failArguments);
  }

  std::ifstream in(fileIn);
  if (!in.is_open()) {
    std::cerr << "Can't open file: " << fileIn << '\n';
    return static_cast<int>(ExitCode::failFile);
  }
  size_t rows = 0;
  size_t columns = 0;

  in >> rows >> columns;
  int* matrix = kizhin::allocateArray(rows * columns, mode);
  kizhin::readArrayValues(in, matrix, rows * columns);
  if (!in.good()) {
    std::cerr << "Error during reading matrix from file\n";
    in.close();
    kizhin::deallocateArray(matrix, mode);
    return static_cast<int>(ExitCode::failFile);
  }
  in.close();

  std::ofstream out(fileOut);
  if (!out.is_open()) {
    std::cerr << "Can't open file: " << fileOut << '\n';
    kizhin::deallocateArray(matrix, mode);
    return static_cast<int>(ExitCode::failFile);
  }
  out << kizhin::countLocalMinimums(matrix, rows, columns);
  out.close();
  kizhin::deallocateArray(matrix, mode);
}
