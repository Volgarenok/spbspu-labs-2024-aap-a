#include <cstring>
#include <iostream>

#include "lab_work.hpp"
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
  int num = 0;
  try {
    size_t pos = 0;
    num = std::stoi(argv[1], &pos);
    if (pos < std::strlen(argv[1])) {
      throw std::invalid_argument("Invalid argument");
    }
  } catch (const std::exception&) {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  try {
    do_lab_work(num, argv[2], argv[3]);
  } catch (const std::invalid_argument& e) {
    std::cerr << "Exception: " << e.what() << "\n";
    return 1;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
    return 2;
  }
  return 0;
}
