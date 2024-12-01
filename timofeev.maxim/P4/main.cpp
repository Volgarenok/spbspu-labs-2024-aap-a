#include <iostream>
#include "has_sam_set.h"

int main()
{
  const char first_line[] = "abs";
  char* second_line = timofeev::input_line(std::cin);
  if (second_line == nullptr)
  {
    std::cerr << ("Bad output");
    free(second_line);
    return 1;
  }
  std::cout << timofeev::same_symbols(first_line, second_line);
  free(second_line);
  return 0;
}
