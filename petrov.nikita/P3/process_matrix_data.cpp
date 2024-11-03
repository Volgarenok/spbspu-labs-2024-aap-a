#include "process_the_matrix.hpp"

int petrov::process_matrix_data(int * ptr_matrix, size_t number_of_rows, size_t rows_length)
{
  size_t required_number = 0;
  if (number_of_rows != rows_length)
  {
    if (rows_length < number_of_rows)
    {
      required_number = rows_length;
    }
    else
    {
      required_number = number_of_rows;
    }
  }
  else
  {
    required_number = number_of_rows;
  }
  if (required_number > 1)
  {
    size_t iterations = 1;
    for (size_t i = 2; i < required_number; i++)
    {
      iterations += 2;
    }
    size_t count_with_zero = 0;
    size_t minus = 2;
    for (size_t part_1 = 0; part_1 <= iterations / 2; part_1++)
    {
      size_t i = 0;
      size_t j = required_number - minus;
      for (; j < required_number; j++)
      {
        if (ptr_matrix[i * required_number + j] == 0)
        {
          count_with_zero++;
          break;
        }
        i++;
      }
      minus++;
    }
    size_t plus = 1;
    for (size_t part_2 = 0; part_2 < iterations - ((iterations / 2) + 1); part_2++)
    {
      size_t i = 0 + plus;
      size_t j = 0;
      for (; i < required_number; i++)
      {
        if (ptr_matrix[i * required_number + j] == 0)
        {
          count_with_zero++;
          break;
        }
        j++;
      }
      plus++;
    }
    return iterations - count_with_zero;
  }
  else
  {
    return 0;
  }
}

