#include <iostream>
#include <input_line.h>
#include "real_number_set.h"

int main()
{
  char* line = timofeev::input_line(std::cin);
  if (line == nullptr)
  {
    std::cerr << "Bad input\n";
    return 1;
  }
  std::cout << std::boolalpha << timofeev::is_real_number(line) << "\n";
  free(line);
  return 0;
}
