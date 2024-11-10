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
    static int temp[10000] = {};
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


int gavrilova::checkNumOfArguments(int argc)
{
  if (argc > 4) {
    std::cerr << "Too many arguments" << "\n";
    return 0;
  } else if (argc < 4) {
    std::cerr << "Not enough arguments" << "\n";
    return 0;
  } else {
    return 1;
  }
}

int gavrilova::checkFirstArgument(unsigned long int num, const char * end)
{
  if (num > 3) {
    std::cerr << "First parametr is out of range" << "\n";
    return 0;
  } else if (num == 0) {
    std::cerr << "First parametr is not a number" << "\n";
    return 0;
  } else if (*end != 0){
    std::cerr << "First parametr is not a number" << "\n";
    return 0;
  } else {
    return 1;

  }
}
