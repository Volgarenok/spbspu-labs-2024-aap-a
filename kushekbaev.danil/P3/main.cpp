#include "kushekbaev_matrix.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char * argv[]) {
  if (argc < 3)
  {
    return 0;
  }

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

  infile.close();

  int saddle_points = kushekbaev::countSaddlePoints(matrix, rows, columns);

  std::ofstream outfile(output_file);
  if (!outfile)
  {
    std::cerr << "Error while opening output file" << "\n";
    kushekbaev::deleteMatrix(matrix);
    return 1;
  }

  outfile << saddle_points << "\n";

  outfile.close();
  kushekbaev::deleteMatrix(matrix);
  std::cout << saddle_points;

  return 0;
}
