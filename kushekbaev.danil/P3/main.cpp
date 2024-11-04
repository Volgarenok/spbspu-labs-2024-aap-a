#include "kushekbaev_matrix.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

int main(int argc, char ** argv) {
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 2;
  }
  std::string input_filename = argv[2];
  std::string output_filename = argv[3];

  std::ifstream infile(input_filename);

  if (!infile)
  {
    std::cerr << "Error while opening input file" << "\n";
    return 1;
  }

  std::istringstream iss(line);
  size_t rows = 0, columns = 0;
  if (!(iss >> rows >> columns))
  {
    std::cerr << "Error reading matrix dimensions" << "\n";
    return 1;
  }

  infile.seekg(0, std::ios::end);
  if (infile.tellg() == 0)
  {
    std::cerr << "Input file is empty" << "\n";
    return 1;
  }
  infile.seekg(0);

  std::string line;
  if (!std::getline(infile, line) or line.empty())
  {
    std::cout << "Error reading line from file" << "\n";
    return 0;
  }

  std::istringstream isst(line);
  if (!(isst >> rows >> columns))
  {
    std::cout << "Not enough data for rows and columns" << "\n";
    return 0;
  }

  int* matrix = kushekbaev::createMatrix(rows, columns);
  if (!matrix)
  {
    std::cerr << "Error allocating memory for matrix" << "\n";
    return 1;
  }

  for (size_t i = 0; i < rows * columns; ++i)
  {
    if (!(infile >> matrix[i]))
    {
        std::cerr << "Error reading matrix data" << "\n";
        kushekbaev::deleteMatrix(matrix);
        return 1;
    }
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

  outfile << saddle_points << "\n";

  outfile.close();
  kushekbaev::deleteMatrix(matrix);

  return 0;
}
