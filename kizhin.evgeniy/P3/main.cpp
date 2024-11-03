#include <fstream>
#include <iostream>
#include "matrix_utils.hpp"
#include "memory_utils.hpp"
#include "parse_arguments.hpp"

int main(int argc, char** argv)
{
  enum ExitCode { failArguments = 1, failFile = 2 };
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
    return failArguments;
  }

  constexpr size_t stackSize = 10'000;
  static int stackBuffer[stackSize];
  int* matrix = nullptr;
  try {
    std::ifstream in(fileIn);
    if (!in.is_open()) {
      throw std::runtime_error("Failed to open input file");
    }
    matrix = kizhin::initializeMatrix(in, stackBuffer, stackSize, mode);
    in.close();

    std::ofstream out(fileOut);
    if (!out.is_open()) {
      throw std::runtime_error("Failed to open ouput file");
    }
    out << kizhin::countLocalMinimums(matrix);
    out.close();
  } catch (const std::exception& error) {
    kizhin::deallocateArray(matrix, mode);
    std::cerr << error.what() << '\n';
    return failFile;
  }
  kizhin::deallocateArray(matrix, mode);
}
