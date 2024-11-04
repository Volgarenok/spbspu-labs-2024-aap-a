#include <iostream>
#include <fstream>
#include <stdexcept>
#include "fileIO.hpp"
#include "matrixUtils.hpp"

int main(int argc, char** argv)
{
  using namespace belobrov;

  if (argc != 4) {
    std::cerr << "Incorrect number of arguments\n";
    return 1;
  }

  int mode = 0;

  try {
    mode = std::stoi(argv[1]);
  }
  catch (const std::invalid_argument&) {
    std::cerr << "Error: First parameter is not a number\n";
    return 1;
  }

  if (mode != 1 && mode != 2) {
    std::cerr << "Error: First parameter is out of range (expected 1 or 2)\n";
    return 1;
  }

  std::ifstream inputFile(argv[2]);
  if (!inputFile) {
    std::cerr << "Error: Cannot open input file\n";
    return 2;
  }

  size_t rows = 0, cols = 0;
  inputFile >> rows >> cols;
  if (!inputFile && inputFile.eof()) {
    std::cerr << "Error: Input file is empty\n";
    return 2;
  }

  if (rows == 0 && cols == 0)
  {
    std::ofstream outputFile(argv[3]);
    outputFile << "0 0\n";
    return 0;
  }

  if (rows == 0 || cols == 0)
  {
    std::cerr << "Error:Invalid matrix dimensions\n";
    return 2;
  }

  int *matrix = nullptr;
  try {
    if (mode == 1) {
      int fixedMatrix[10000];
      loadMatrix(inputFile, fixedMatrix, rows, cols);
      transformMatrix(fixedMatrix, rows, cols);
      saveMatrix(argv[3], fixedMatrix, rows, cols);
    } else {
      matrix = new int[rows * cols];
      loadMatrix(inputFile, matrix, rows, cols);
      transformMatrix(matrix, rows, cols);
      saveMatrix(argv[3], matrix, rows, cols);
      delete[] matrix;
    }
  } catch (const std::bad_alloc&) {
    std::cerr << "Error: Memory allocation failed\n";
    delete[] matrix;
    return 2;
  } catch (const std::runtime_error& e) {
    std::cerr << "Error: " << e.what() << "\n";
    delete[] matrix;
    return 2;
  }

  return 0;
}
