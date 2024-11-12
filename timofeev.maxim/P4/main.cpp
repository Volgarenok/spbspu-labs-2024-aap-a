#include "functions.h"
#include <iostream>

int main()
{
  const char first_line[] = "abs";
  char* second_line = nullptr;
  try
  {
    second_line = timofeev::input_line(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << ("Memory error");
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
