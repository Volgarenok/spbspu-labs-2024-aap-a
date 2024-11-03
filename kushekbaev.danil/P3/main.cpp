#include "kushekbaev_matrix.hpp"
#include <iostream>
#include <fstream>

int main()
{
  const std::string input_file = "input.txt";
  const std::string output_file = "output.txt";
  std::ifstream infile(input_file);

  size_t rows = 0, columns = 0;
  infile >> rows >> columns;
  if (!infile)
  {
    std::cerr << "Error while opening input file" << "\n";
    return 1;
  }

  int* matrix = kushekbaev::createMatrix(rows, columns);

  for (size_t i = 0; i < rows * columns; ++i) {
    infile >> matrix[i];
  }
  int* matrix = kushekbaev::createMatrix(rows, columns);

  for (size_t i = 0; i < rows * columns; ++i) {
      infile >> matrix[i];
  }

  infile.close();

  int saddle_points = kushekbaev::countSaddlePoints(matrix, rows, columns);
  if (!outfile)
  {
    std::cerr << "Error while opening outpur file " << "\n";
    kushekbaev::deleteMatrix(matrix);
    return 1;
  }

  std::ofstream outfile(output_file);

  outfile << saddle_points << "\n";

  outfile.close();
  kushekbaev::deleteMatrix(matrix);

  return 0;
}
