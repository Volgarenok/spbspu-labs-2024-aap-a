#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include "process_the_matrix.hpp"

int checkArguments(int argc, const char ** argv);

int main(int argc, const char ** argv)
{
  if (checkArguments(argc, argv) == 1)
  {
    return 1;
  }
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  if (std::atoi(argv[1]) == 1)
  {
    size_t number_of_rows = 0, rows_length = 0;
    input >> number_of_rows;
    input >> rows_length;
    if (!input)
    {
      std::cerr << "Error: Invalid data\n";
      return 2;
    }
    if (number_of_rows == 0 && rows_length == 0)
    {
      output << 0;
      return 0;
    }
    int matrix[10000] = {0};
    int * ptr_matrix = matrix;
    if ((number_of_rows == 0 && rows_length != 0) || (number_of_rows != 0 && rows_length == 0))
    {
      std::cerr << "Error: Invalid data\n";
      return 2;
    }
    else if (!petrov::inputMatrix(input, ptr_matrix, number_of_rows, rows_length))
    {
      std::cerr << "Error: Invalid data\n";
      return 2;
    }
    output << petrov::countNotZeroDiagonals(ptr_matrix, number_of_rows, rows_length);
  }
  else
  {
    size_t number_of_rows = 0, rows_length = 0;
    input >> number_of_rows;
    input >> rows_length;
    if (!input)
    {
      std::cerr << "Error: Invalid data\n";
      return 2;
    }
    if (number_of_rows == 0 && rows_length == 0)
    {
      output << 0;
      return 0;
    }
    int * ptr_matrix = nullptr;
    try
    {
      ptr_matrix = new int[number_of_rows * rows_length];
      if ((number_of_rows == 0 && rows_length != 0) || (number_of_rows != 0 && rows_length == 0))
      {
        std::cerr << "Error: Invalid data\n";
        delete[] ptr_matrix;
        return 2;
      }
      else if (!petrov::inputMatrix(input, ptr_matrix, number_of_rows, rows_length))
      {
        std::cerr << "Error: Invalid data\n";
        delete[] ptr_matrix;
        return 2;
      }
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory\n";
      return 3;
    }
    output << petrov::countNotZeroDiagonals(ptr_matrix, number_of_rows, rows_length);
    delete[] ptr_matrix;
  }
}

int checkArguments(int argc, const char ** argv)
{
  if (argc != 4)
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
  }
  size_t size_of_first_argument = std::strlen(argv[1]);
  for (size_t i = 0; i < size_of_first_argument; i++)
  {
    if (std::isdigit(argv[1][i]) == false)
    {
      std::cerr << "First parameter is not a number\n";
      return 1;
    }
  }
  int check_varuable = std::atoi(argv[1]);
  if (check_varuable != 1 && check_varuable != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  return 0;
}
