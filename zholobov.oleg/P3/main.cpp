#include <cstdlib>
#include <iostream>
#include <fstream>
#include "min_sum_mdg.hpp"

int main(int argc, char** argv)
{
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return 1;
  } else if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  long num = 0;
  try {
    char* endptr = nullptr;
    num = std::strtol(argv[1], std::addressof(endptr), 10);
    if (*endptr != 0) {
      throw std::runtime_error("Not a number");
    }
    if (num != 1 && num != 2) {
      throw std::invalid_argument("Out of range");
    }
  } catch (const std::runtime_error&) {
    std::cerr << "First parameter is not a number\n";
    return 1;
  } catch (const std::invalid_argument&) {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  try {
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input_file(argv[2]);
    input_file >> rows >> cols;
    if (!input_file) {
      throw std::runtime_error("Wrong data in input file");
    }
    std::ofstream output_file(argv[3]);
    int matrix[10000] = {0};
    int* matrix_ptr = nullptr;
    size_t elements_number = rows * cols;
    int result = 0;
    if (elements_number > 0) {
      if (num == 1) {
        matrix_ptr = matrix;
      } else if (num == 2) {
        matrix_ptr = new int[elements_number]{};
      }
      try {
        zholobov::read_matrix(input_file, matrix_ptr, elements_number);
      } catch (const std::exception&) {
        if (num == 2) {
          delete[] matrix_ptr;
        }
        throw;
      }
      result = zholobov::calc_min_sum_mdg(matrix_ptr, rows, cols);
      if (num == 2) {
        delete[] matrix_ptr;
      }
    }
    output_file << result;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
    return 2;
  }
  return 0;
}
