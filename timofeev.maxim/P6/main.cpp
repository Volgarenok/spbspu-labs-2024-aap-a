#include <iostream>
#include "real_number_set.h"
#include <all_for_input.h>

int main()
{
  char* line = nullptr;
  try
  {
    line = timofeev::input_line(std::cin);
  }
  catch(const std::bad_alloc& e)
  {
    std::cerr << ("Bad output\n");
    free(line);
    return 1;
  }
  if (line == nullptr)
  {
    std::cerr << ("Bad output\n");
    free(line);
    return 1;
  }
  std::cout << timofeev::is_real_number(line);
  free(line);
  return 0;
}
