#include <iostream>
#include <stdlib.h>
#include <resize_line.hpp>
#include "line_processing.hpp"

int main()
{
  constexpr size_t step = 1;
  char * line = static_cast< char * >(malloc(sizeof(char)));
  if (line == nullptr)
  {
    std::cerr << "ERROR: Out of memory" << '\n';
    return 1;
  }

  line = zakirov::get_line(std::cin, line, step);
  if (line == nullptr)
  {
    return 1;
  }

  zakirov::change_line(line);
  size_t location = 0;
  while (line[location] != '\0')
  {
    std::cout << line[location];
    location += 1;
  }

  std::cout << '\n';
  free(line);
}
