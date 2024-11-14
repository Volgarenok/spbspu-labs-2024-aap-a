#include <iostream>
#include <fstream>
#include <istream>
#include <cstddef>
#include <stdexcept>
#include "is3Angle.hpp"
#include "enterMTX.hpp"

namespace dribas
{
  bool checkEnter(char* const* const argv, int argc, long int& secondArg);
}

bool dribas::checkEnter(char* const* const argv, int argc, long int& secondArg)
{
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return true;
  }
  if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return true;
  }
  char *endptr = nullptr;
  secondArg = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0') {
    std::cerr << "First parameter is not a number\n";
    return true;
  }
  if (secondArg > 2 || secondArg < 1) {
    std::cerr << "First parameter is out of range\n";
    return true;
  }
  return false;
}

int main(int argc, char ** argv)
{
  long int secondArg = -1;
  if (dribas::checkEnter(argv, argc, secondArg)) {
    return 1;
  }
  size_t m = 0, n = 0;
  std::ifstream input(argv[2]);
  input >> m >> n;
  if (!input) {
    std::cerr << "Error with matrix's size\n";
    return 2;
  }
  int* mtx = nullptr;
  int* dynamicmtx = nullptr;
  int fixedmtx[10000] = {};
  if (secondArg == 1) {
    mtx = fixedmtx;
  }
  if (secondArg == 2) {
    try {
      dynamicmtx = new int[m * n];
    } catch (const std::bad_alloc & e) {
      std::cerr << "Error with make matrix\n";
      return 2;
    }
    mtx = dynamicmtx;
  }
  size_t read = 0;
  dribas::enterMTX(input, mtx, m, n, read);
  std::ofstream output(argv[3]);
  if (input && read == m * n){
    output << std::boolalpha << dribas::is3Angle(mtx, m, n) << "\n";
  } else {
    std::cerr << "Error with enter\n";
    delete[] dynamicmtx;
    return 2;
  }
  delete[] dynamicmtx;
  return 0;
}

