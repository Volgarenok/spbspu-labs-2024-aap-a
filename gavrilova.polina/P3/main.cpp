#include <iostream>
#include <cstdlib>
#include <fstream>
#include "upptri.hpp"

namespace gavrilova {
  int checkNumOfArguments(int argc)
  {
    if (argc > 4) {
      std::cerr << "Too many arguments" << "\n";
      return 1;
    } else if (argc < 4) {
      std::cerr << "Not enough arguments" << "\n";
      return 1;
    } else {
      return 0;
    }
  }

  int checkFirstArgument(unsigned long int num, const char * end)
  {
    if (num > 3) {
      std::cerr << "First parametr is out of range" << "\n";
      return 1;
    } else if (num == 0) {
      std::cerr << "First parametr is not a number" << "\n";
      return 1;
    } else if (*end != 0){
      std::cerr << "First parametr is not a number" << "\n";
      return 1;
    } else {
      return 0;
    }
  }
}

int main(int argc, char ** argv)
{
  if (gavrilova::checkNumOfArguments(argc)) {
    return 1;
  }
  char * end;
  unsigned long int num = std::strtoul(argv[1], &end, 10);
  if (gavrilova::checkFirstArgument(num, end)) {
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
  int temp[10000] = {};
  if (num == 2) {
    int * temp = nullptr;
    try {
      temp = new int [m*n];
    } catch (const std::bad_alloc & e) {
      return 1;
    }
    mtx = temp;
  } else if (num == 1) {
    mtx = temp;
  }

  gavrilova::input_matrix(input, mtx, m, n, read);

  if ((!input || input.eof()) && num == 2) {
    delete[] mtx;
    return 1;
  } else if ((!input || input.eof()) && num == 1) {
    return 1;
  }

  output << gavrilova::isUpperTriangMtx(mtx, m, n) << "\n";

  if (num == 2){
    delete[] mtx;
  }
}
