#include <iostream>
#include <cstdlib>
#include <fstream>
#include "upptri.hpp"

int main(int argc, char ** argv)
{
  if (!gavrilova::checkNumOfArguments(argc)) {
    return 1;
  }
  char * end;
  unsigned long int num = std::strtoul(argv[1], &end, 10);
  if (!gavrilova::checkFirstArgument(num, end)) {
    return 1;
  }

  std::ifstream input (argv[2]);
  std::ofstream output (argv[3]);

  size_t m = 0, n = 0;
  input >> m >> n;
  if (!input) {
    return 2;
  }

  size_t read = 0;

  int * mtx = nullptr;
  if (num == 2) {
    int * temp = nullptr;
    try {
      temp = new int [m*n];
    } catch (const std::bad_alloc & e) {
      return 1;
    }
    mtx = temp;
  } else if (num == 1) {
    int temp[10000] = {};
    mtx = temp;
  }
  gavrilova::input_matrix(input, mtx, m, n, read);
  if (!gavrilova::output_matrix(output, input, mtx, read, m, n)) {
    if (num == 2) {
      delete[] mtx;
    }
    return 2;
  }
  if (num == 2) {
    delete[] mtx;
  }
}


