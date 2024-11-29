#include <iostream>
#include <stdlib.h>
#include <resize_line.hpp>
#include "line_processing.hpp"

int main()
{
  constexpr size_t step = 26;
  size_t start = 1, finish = 1;
  char * line = static_cast<char *>(malloc(sizeof(char)));
  char last_symbol = '\0';
  std::cin >> last_symbol;
  if (line == nullptr)
  {
    std::cerr << "ERROR: Out of memory" << '\n';
    return 1;
  }
  else  if (last_symbol == '\n' || last_symbol == '\0')
  {
    std::cerr << "ERROR: Empty line" << '\n';
    free(line);
    return 1;
  }

  line[0] = last_symbol;
  while (last_symbol != '\0')
  {
    char * expanded_line = zakirov::expand_line(line, finish, step);
    finish += step;
    if (expanded_line == nullptr)
    {
      std::cerr << "ERROR: Out of memory" << '\n';
      free(line);
      return 1;
    }

    zakirov::get_line(std::cin, expanded_line, start, finish);
    free(line);
    line = expanded_line;
    start += step;
    last_symbol = expanded_line[finish - 1];
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
