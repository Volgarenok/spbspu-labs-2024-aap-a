#include <iostream>
#include <cstdlib>
#include <fstream>
#include "check_input.hpp"
#include "input_matrix.hpp"
#include "upptri.hpp"

int main(int argc, char ** argv)
{
  if (!checkNumOfArguments(argc)) {
    return 1;
  }
  char * end;
  unsigned long int num = std::strtoul(argv[1], &end, 10);
  if (!checkFirstArgument(num, end)) {
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

  if (num == 1) {

    int mtx1[10000] = {};

    input_matrix(input, mtx1, m, n, read);
    if (input && read == m*n){
      output << isUpperTriangMtx(mtx1, m, n) << "\n";
    } else {
      return 2;
    }

  } else if (num == 2) {

    int * mtx2 = nullptr;
    try {
      mtx2 = new int [m*n];
    } catch (const std::bad_alloc & e) {
      return 1;
    }

    input_matrix(input, mtx2, m, n, read);
    if (input && read == m*n){
      output << isUpperTriangMtx(mtx2, m, n) << "\n";
    } else {
      delete [] mtx2;
      return 2;
    }
  }
}
