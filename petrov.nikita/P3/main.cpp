#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "process_the_matrix.hpp"

int main(int argc, char ** argv)
{
  if (petrov::check_arguments(argc, argv) == 1)
  {
    return 1;
  }
  std::ifstream input(argv[2]);
  if (std::atoi(argv[1]) == 1)
  {
    size_t number_of_rows = 0, rows_length = 0;
    input >> number_of_rows;
    input >> rows_length;
    int matrix[10000] = {0};
    int * ptr_matrix = matrix;
    petrov::input_matrix_static(input, ptr_matrix, number_of_rows, rows_length);
    for (size_t i = 0; i < number_of_rows * rows_length; i++)
    {
      std::clog << matrix[i];
    }
  }
  else
  {
    size_t number_of_rows = 0, rows_length = 0;
    input >> number_of_rows;
    input >> rows_length;
    int * ptr_matrix = nullptr;
    try
    {
      ptr_matrix = new int[number_of_rows * rows_length];
      petrov::input_matrix_dynamic(input, ptr_matrix, number_of_rows, rows_length);
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Out of memory\n";
      return 3;
    }
    for (size_t i = 0; i < number_of_rows * rows_length; i++)
    {
      std::clog << ptr_matrix[i];
    }
  }
}

