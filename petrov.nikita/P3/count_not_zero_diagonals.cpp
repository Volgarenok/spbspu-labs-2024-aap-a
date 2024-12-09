#include "process_the_matrix.hpp"

size_t getMatrixDiagonalLimit(const size_t number_of_rows, const size_t rows_length);
size_t countNotZeroDiagonalsUsingMatrixDiagonalLimit(const int * ptr_matrix, const size_t matrix_diagonal_limit);

size_t petrov::countNotZeroDiagonals(const int * ptr_matrix, const size_t number_of_rows, const size_t rows_length)
{
  size_t matrix_diagonal_limit = getMatrixDiagonalLimit(number_of_rows, rows_length);
  return countNotZeroDiagonalsUsingMatrixDiagonalLimit(ptr_matrix, matrix_diagonal_limit);
}

size_t getMatrixDiagonalLimit(const size_t number_of_rows, const size_t rows_length)
{
  if (number_of_rows != rows_length)
  {
    if (rows_length < number_of_rows)
    {
      return rows_length;
    }
    else
    {
      return number_of_rows;
    }
  }
  else
  {
    return number_of_rows;
  }
}

size_t countNotZeroDiagonalsUsingMatrixDiagonalLimit(const int * ptr_matrix, const size_t matrix_diagonal_limit)
{
  if (matrix_diagonal_limit > 1)
  {
    size_t iterations = 1;
    for (size_t i = 2; i < matrix_diagonal_limit; i++)
    {
      iterations += 2;
    }
    size_t count_with_zero = 0;
    size_t minus = 2;
    for (size_t part_1 = 0; part_1 <= iterations / 2; part_1++)
    {
      size_t i = 0;
      size_t j = matrix_diagonal_limit - minus;
      for (; j < matrix_diagonal_limit; j++)
      {
        if (ptr_matrix[i * matrix_diagonal_limit + j] == 0)
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
      for (; i < matrix_diagonal_limit; i++)
      {
        if (ptr_matrix[i * matrix_diagonal_limit + j] == 0)
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

