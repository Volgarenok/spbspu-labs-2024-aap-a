#include <fstream>
#include <iostream>
#include "matrix_utils.hpp"
#include "parse_arguments.hpp"

int main(int argc, char** argv)
{
  enum class ExitCode { failArguments = 1, failFile = 2 };

  kizhin::MemoryMode mode;
  char* fileIn = nullptr;
  char* fileOut = nullptr;
  try {
    kizhin::checkArgumentsCount(argc);
    mode = kizhin::parseProgramMode(argv[1]);
    fileIn = argv[2];
    fileOut = argv[3];
  } catch (const std::logic_error& error) {
    std::cerr << error.what() << '\n';
    return static_cast<int>(ExitCode::failArguments);
  }

  int* matrix = nullptr;
  try {
    std::ifstream in(fileIn);
    if (!in.is_open()) {
      throw std::runtime_error("Failed to open input file");
    }
    matrix = kizhin::initializeMatrix(in, mode);

    std::ofstream out(fileOut);
    if (!out.is_open()) {
      throw std::runtime_error("Failed to open ouput file");
    }
    out << kizhin::countLocalMinimums(matrix);
  } catch (const std::exception& error) {
    std::cerr << error.what() << '\n';
    return static_cast<int>(ExitCode::failFile);
  }
  kizhin::deallocateArray(matrix, mode);
}
