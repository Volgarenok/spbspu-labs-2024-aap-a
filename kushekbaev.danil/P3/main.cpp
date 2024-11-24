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

  if (!infile)
  {
    std::cerr << "Error while opening input file" << "\n";
    return 1;
    std::cout << "infile error";
  }

  if (infile.eof())
  {
    std::cerr << "Not enough elements in file" << "\n";
    return 1;
    std::cout << "infile eof";
  }

  if (infile.fail())
  {
    std::cerr << "Failed input" << "\n";
    return 1;
    std::cout << "infile fail";
  }

  char ch = 0;
  if (!(infile >> ch))
  {
    std::cerr << "Input file is empty" << "\n";
    return 1;
    std::cout << "empty file";
  }

  if (!(infile >> rows) || !(infile >> columns))
  {
    std::ofstream outfile(output_filename);
    outfile << "0" << "\n";
    return 0;
    std::cout << "0";
  }

  if (rows == 0 || columns == 0)
  {
    std::ofstream outfile(output_filename);
    outfile << "0" << "\n";
    return 0;
    std::cout << "0";
  }

  int* matrix = new int [rows * columns]();

  size_t count = 0;
  for (size_t i = 0; i < (rows * columns); i++)
  {
    if (!(infile >> matrix[i]))
    {
      std::cerr << "Not enough elements in file" << "\n";
      std::cout << "not enough elements in file";
      delete[] matrix;
      return 1;
    }
  count++;
  }

  if (count != (rows * columns))
  {
    std::cerr << "Expected " << (rows * columns) << " elements, but read only " << count << "\n";
    std::cout << "EXPECT THE UNEXPECTABLE";
    delete[] matrix;
    return 1;
  }

  int saddle_points = kushekbaev::countSaddlePoints(matrix, rows, columns);

  std::ofstream outfile(output_filename);
  if (!outfile.is_open())
  {
    std::cerr << "Error while opening output file" << "\n";
    delete[] matrix;
    return 1;
  }
  outfile << saddle_points << "\n";

  delete[] matrix;
  std::cout << "good";
  return 0;
}
