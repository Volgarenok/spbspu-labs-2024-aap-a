#include <iostream>
#include <inputStr.hpp>
#include "rm_digits.hpp"

int main()
{
  size_t len = 0;
  char* first_str = gavrilova::inputStr(std::cin, len);

  if (!first_str) {
    std::cerr << "Memory error\n";
    return 1;
  }
  if (first_str[0] == '\0') {
    std::cerr << "Empty string\n";
    delete[] first_str;
    return 1;
  }

  char* result_str = nullptr;
  try {
    result_str = new char[len + 1];
  } catch (const std::bad_alloc & e) {
    std::cerr << "Memory error\n";
    delete[] first_str;
    return 1;
  }

  gavrilova::rm_digits(first_str, result_str);
  std::cout << result_str << "\n";
  delete[] result_str;
  delete[] first_str;
}
