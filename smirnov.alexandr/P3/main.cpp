#include <iostream>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  int num = std::atoi(argv[1]);
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  for (int i = 0; argv[1][i] != '\0'; ++i)
  {
    if (!std::isdigit(argv[1][i]))
    {
      std::cerr << "First parameter is not a number\n";
    }
  }
  std::ifstream input(argv[2]);
  int rows = 0;
  int columns = 0;
  input >> rows >> columns;
  if (input.fail())
  {
    std::cerr << "Invalid matrix dimensions\n";
    return 2;
  }
  int ** matrix;
  if (num == 1)
  {
    if (rows * columns > 10000)
    {
      std::cerr << "Matrix size exceeds limit\n";
      return 2;
    }
    static int fixedMatrix[100][100];
    matrix = fixedMatrix;
  }
  else
  {
    matrix = new int * [rows];
    for (int i = 0; i < rows; i++)
    {
      matrix[i] = new int[columns];
    }
  }
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
       if (!(input >> matrix[i][j])) {
         cerr << "Invalid matrix data" << endl;
           return 2;
       }
    }
  }
}

