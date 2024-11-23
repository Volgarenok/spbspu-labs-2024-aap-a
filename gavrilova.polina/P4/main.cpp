#include <iostream>
#include <cctype>
#include <inputStr.hpp>

char * rm_digits (const char * original, char * new_str)
{
  size_t j = 0;
  for (size_t i = 0; original[i] != '\0'; ++i) {
    if (!isdigit(original[i])) {
      new_str[j++] = original[i];
    }
  }
  new_str[j] = '\0';
  return new_str;
}

int main()
{
  first_str = inputStr(std::cin);
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
