#include "count_saddle_point.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  else if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::string input_filename = argv[2];
  std::string output_filename = argv[3];

  std::ifstream infile(input_filename);
  size_t rows = 0, columns = 0;

  if (!infile.is_open())
  {
    std::cerr << "Error while opening input file\n";
    return 1;
  }

  infile >> rows >> columns;
  if (infile.fail())
  {
    std::cerr << "Incorrect parameters\n";
    return 2;
  }

  if (rows == 0 || columns == 0)
  {
    std::ofstream outfile(output_filename);
    outfile << "0\n";
    return 0;
  }

  int* matrix = nullptr;
  try
  {
    matrix = new int[rows * columns]();
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    return 2;
  }

  size_t count = 0;
  for (size_t row = 0; row < rows; row++)
  {
    for (size_t col = 0; col < columns; col++)
    {
      if (!(infile >> matrix[count]))
      {
        std::cerr << "Not enough elements in file at row " << row << ", column " << col << "\n";
        delete[] matrix;
        return 1;
      }
      count++;
    }
  }

  if (count != (rows * columns))
  {
    std::cerr << "Expected " << (rows * columns) << " elements, but read only " << count << "\n";
    delete[] matrix;
    return 1;
  }

  int saddle_points = kushekbaev::countSaddlePoints(matrix, rows, columns);

  std::ofstream outfile(output_filename);
  if (!outfile.is_open())
  {
    std::cerr << "Error while opening output file\n";
    delete[] matrix;
    return 1;
  }
  outfile << saddle_points << "\n";

  delete[] matrix;
  return 0;
}
