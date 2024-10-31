#include <iostream>
#include <fstream>
#include <cstring>
#include "matrix.hpp"
#include "min_sum_mdg.hpp"

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

  size_t pos = 0;
  int num = 0;
  try
  {
    num = std::stoi(argv[1], &pos);
    if (pos < std::strlen(argv[1]))
    {
      throw std::invalid_argument("Invalid argument");
    }
  }
  catch (const std::exception &)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  if ((num != 1) && (num != 2))
  {
    std::cerr << "First parameter neither 1 nor 2\n";
    return 1;
  }

  std::ifstream input_file(argv[2]);
  std::ofstream output_file(argv[3]);

  size_t rows = 0;
  size_t cols = 0;
  input_file >> rows >> cols;
  if (!input_file)
  {
    std::cerr << "Wrong data in input file\n";
    return 2;
  }

  Matrix m;
  try
  {
    m.resize(rows, cols);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
    return 2;
  }
  for (size_t i = 0; i < m.get_rows(); i++)
  {
    for (size_t j = 0; j < m.get_cols(); j++)
    {
      int value = 0;
      input_file >> value;
      if (!input_file)
      {
        std::cerr << "Can't read file\n";
        return 2;
      }
      m.put_elem(i, j, value);
    }
  }
  output_file << calc_min_sum_mdg(m);
  return 0;
}
