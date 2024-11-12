#include <iostream>
#include <stdlib.h>
#include "line_processing.hpp"

int main()
{
  size_t start = 1, finish = 1;
  constexpr size_t step = 15;
  char last_symbol = '\0';
  std::cin >> last_symbol;
  char * line = static_cast<char *>(malloc(sizeof(char)));
  if (last_symbol == '\0')
  {
    std::cerr << "ERROR: Empty line" << '\n';
    return 1;
  }
  else if (line == nullptr)
  {
    std::cerr << "ERROR: Out of memory" << '\n';
    return 1;
  }

  line[0] = last_symbol;
  while (last_symbol != '\0')
  {
    zakirov::expand_line(line, finish, step);
    if (line == nullptr)
    {
      std::cerr << "ERROR: Out of memory" << '\n';
      return 1;
    }

    finish += step;
    zakirov::get_line(std::cin, line, start, finish);
    start += step;
    last_symbol = line[finish - 1];
  }

  char * answer = zakirov::change_line(line);
  size_t location = 0;
  while (answer[location] != '\0')
  {
    std::cout << answer[location];
  }

  std::cout << '\n';
}
