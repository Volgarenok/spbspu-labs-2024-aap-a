#include "functions.h"
#include <iostream>

int main()
{
  const char first_line[] = "abs";
  char* second_line = timofeev::input_line(std::in);
  if (second_line == nullptr)
  {
    free(second_line);
    return 1;
  }
  if (second_line[0] == '\0')
  {
    std::cerr << "Empty input";
    free(second_line);
    return 1;
  }
  std::cout << timofeev::same_symbols(first_line, second_line);
  free(second_line);
}
