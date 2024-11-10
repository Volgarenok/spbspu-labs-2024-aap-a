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
    num = std::strtol(argv[1], &endptr, 10);
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
    size_t elements_number = rows * cols;
    int result = 0;
    if (elements_number == 0) {
      output_file << "0";
    } else {
      if (num == 1) {
        int matrix[10000] = {0};
        zholobov::read_matrix(input_file, matrix, elements_number);
        result = zholobov::calc_min_sum_mdg(matrix, rows, cols);
      } else if (num == 2) {
        int* matrix = new int[elements_number]{};
        try {
          zholobov::read_matrix(input_file, matrix, elements_number);
        } catch (const std::exception&) {
          delete[] matrix;
          throw;
        }
        result = zholobov::calc_min_sum_mdg(matrix, rows, cols);
        delete[] matrix;
      } else {
        throw std::invalid_argument("First parameter is invalid. It should be either 1 or 2");
      }
      output_file << result;
    }
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception: " << e.what() << "\n";
    return 1;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
    return 2;
  }
  return 0;
}
