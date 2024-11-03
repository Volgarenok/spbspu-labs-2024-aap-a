#include "kushekbaev_matrix.hpp"
#include "createMatrix.cpp"
#include "deleteMatrix.cpp"
#include "getElement.cpp"
#include "countSaddlePoints.cpp"
#include <iostream>
#include <fstream>

int main()
{
  const std::string input_file = "input.txt";
  const std::string output_file = "output.txt";
  std::ifstream infile(input_file);

  size_t rows = 0, columns = 0;
  infile >> rows >> columns;

  int* matrix = kushekbaev::createMatrix(rows, columns);

  for (size_t i = 0; i < rows * columns; ++i) {
      infile >> matrix[i];
  }

  infile.close();

  int saddle_points = kushekbaev::countSaddlePoints(matrix, rows, columns);

  std::ofstream outfile(output_file);

  outfile << saddle_points << std::endl;

  outfile.close();
  kushekbaev::deleteMatrix(matrix);

  return 0;
}
