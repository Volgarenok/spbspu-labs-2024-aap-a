#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "process_the_matrix.hpp"

int main(int argc, const char ** argv)
{
  if (petrov::check_arguments(argc, argv) == 1)
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
    else if (!petrov::input_matrix_static(input, ptr_matrix, number_of_rows, rows_length))
    {
      std::cerr << "Error: Invalid data\n";
      return 2;
    }
    output << petrov::process_matrix_data(ptr_matrix, number_of_rows, rows_length);
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
      else if (!petrov::input_matrix_dynamic(input, ptr_matrix, number_of_rows, rows_length))
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
    output << petrov::process_matrix_data(ptr_matrix, number_of_rows, rows_length);
    delete[] ptr_matrix;
  }
}

