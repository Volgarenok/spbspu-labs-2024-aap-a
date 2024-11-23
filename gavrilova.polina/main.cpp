#include <iostream>
#include <inputStr.hpp>
#include "rm_digits.hpp"

int main()
{
  char* first_str = nullptr;
  size_t len = 0;
  first_str = inputStr(std::cin, len);
  if (!first_str) {
    std::cerr << "Memory or input error";
  }

  char * result_str = nullptr;
  try {
    result_str = new char [len+1];
  } catch (const std::bad_alloc & e) {
    std::cerr << "Memory error.";
    delete[] first_str;
    return 1;
  }

  rm_digits(first_str, result_str);
  std::cout << result_str << "\n";
  delete[] result_str;
  delete[] first_str;
}
