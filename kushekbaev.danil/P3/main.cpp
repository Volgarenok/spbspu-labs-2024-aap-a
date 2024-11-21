#include "count_saddle_point.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 2;
  }

  std::string input_filename = argv[2];
  std::string output_filename = argv[3];

  std::ifstream infile(input_filename);
  size_t rows = 0, columns = 0;
  std::cin >> rows >> columns;

  if (!infile)
  {
    std::cerr << "Error while opening input file" << "\n";
    return 1;
  }

  if (infile.eof())
  {
    std::cerr << "Not enough elements in file" << "\n";
    return 1;
  }

  if (rows == 0 && columns == 0)
  {
    std::ofstream outfile(output_filename);
    outfile << "0" << "\n";
    return 0;
  }

  char ch = 0;
  if (!(infile >> ch))
  {
    std::cerr << "Input file is empty" << "\n";
    return 1;
  }

  if (!(infile >> rows >> columns))
  {
    std::cerr << "Error reading matrix dimensions" << "\n";
    return 1;
  }

  int* matrix = new int [rows * columns];
  if (!matrix)
  {
    std::cerr << "Error allocating memory for matrix" << "\n";
    return 1;
  }

  try
  {
    for (size_t i = 0; i < rows * columns; i++)
    {
      if (!(infile >> matrix[i]))
       {
         throw std::runtime_error("Error reading matrix data");
       }
    }

  int saddle_points = kushekbaev::countSaddlePoints(matrix, rows, columns);

  std::ofstream outfile(output_filename);
  if (!outfile.is_open())
  {
    throw std::runtime_error("Error while opening output file");
  }
  outfile << saddle_points << "\n";
  }
  catch (const std::runtime_error& e)
  {
    std::cerr << e.what() << "\n";
    delete[] matrix;
    return 1;
  }

  delete[] matrix;
  return 0;
}
