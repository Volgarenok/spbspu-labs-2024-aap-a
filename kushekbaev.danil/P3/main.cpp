#include "kushekbaev_matrix.hpp"
#include <iostream>
#include <fstream>

int main(int argc, char ** argv) {
  if (argc < 3)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  std::string input_filename = argv[1];
  std::string output_filename = argv[2];

  std::ifstream infile(input_filename);

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

  std::ofstream outfile(output_filename);
  if (!outfile)
  {
    std::cerr << "Error while opening output file" << "\n";
    kushekbaev::deleteMatrix(matrix);
    return 1;
  }

  outfile << saddle_points << argv[saddle_points] << "\n";

  outfile.close();
  kushekbaev::deleteMatrix(matrix);

  return 0;
}
