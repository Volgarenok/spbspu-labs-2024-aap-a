#include <iostream>
#include <cstdlib>
#include <resize_line.hpp>
#include "line_processing.hpp"

int main()
{
  constexpr size_t step = 1;
  char * line = zakirov::get_to_symbol(std::cin, step, '\n');
  if (!line)
  {
    std::cerr << "ERROR: Out of memory" << '\n';
    return 1;
  }
  else if (line[0] == '\0' || line[0] == '\n')
  {
    std::cerr << "ERROR: Empty line" << '\n';
    free(line);
    return 1;
  }

  zakirov::get_missing_letters(line);
  std::cout << line << '\n';
  free(line);
}
