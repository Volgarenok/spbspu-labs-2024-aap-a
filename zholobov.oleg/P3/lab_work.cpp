#include "lab_work.hpp"

#include <fstream>

#include "min_sum_mdg.hpp"

namespace {

  void read_matrix(std::ifstream& ifs, int* matrix, size_t elements_to_read) {
    while (elements_to_read-- != 0) {
      ifs >> *matrix++;
      if (!ifs) {
        throw std::runtime_error("Error occured when reading matrix data");
      }
    }
  }

  int do_lab_work_stack(std::ifstream& ifs, size_t rows, size_t cols) {
    size_t elements_number = rows * cols;
    if (elements_number == 0) {
      return 0;
    }
    int matrix[10000] = {0};
    read_matrix(ifs, matrix, elements_number);
    return calc_min_sum_mdg(matrix, rows, cols);
  }

  int do_lab_work_dynamic(std::ifstream& ifs, size_t rows, size_t cols) {
    size_t elements_number = rows * cols;
    if (elements_number == 0) {
      return 0;
    }
    int* matrix = new int[elements_number]{};
    try {
      read_matrix(ifs, matrix, elements_number);
    } catch (const std::exception&) {
      delete[] matrix;
      throw;
    }
    int result = calc_min_sum_mdg(matrix, rows, cols);
    delete[] matrix;
    return result;
  }

}  // namespace

void do_lab_work(int num, const char* input_filename, const char* output_filename) {
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input_file(input_filename);
  input_file >> rows >> cols;
  if (!input_file) {
    throw std::runtime_error("Wrong data in input file");
  }
  std::ofstream output_file(output_filename);
  switch (num) {
    case 1:
      output_file << do_lab_work_stack(input_file, rows, cols);
      break;
    case 2:
      output_file << do_lab_work_dynamic(input_file, rows, cols);
      break;
    default:
      throw std::invalid_argument("First parameter is invalid. It should be either 1 or 2");
  }
}
