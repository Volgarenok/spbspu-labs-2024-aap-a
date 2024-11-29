#include "resize_line.hpp"
#include <iostream>

char * zakirov::expand_line(char const * regular_line, size_t real_lenght, size_t add_length)
{
  char * expanded_line = static_cast< char * >(malloc(real_lenght + add_length));
  if (expanded_line == nullptr)
  {
    return expanded_line;
  }

  for (size_t i = 0; i < real_lenght; ++i)
  {
    expanded_line[i] = regular_line[i];
  }

  return expanded_line;
}

void zakirov::get_segment(std::istream & in, char * line, size_t start, size_t finish)
{
  char temporary_symbol = '\0';
  for (; start < finish; ++start)
  {
    in >> temporary_symbol;
    if (temporary_symbol == '\0' || temporary_symbol == '\n')
    {
      for (; start < finish; ++start)
      {
        line[start] = '\0';
      }
      break;
    }
    else
    {
    line[start] = temporary_symbol;
    }
  }
}

char * zakirov::get_line(std::istream & in, char * line, size_t step)
{
  size_t start = 1, finish = 1;
  char last_symbol = '\0';
  in >> last_symbol;
  if (last_symbol == '\n' || last_symbol == '\0')
  {
    std::cerr << "ERROR: Empty line" << '\n';
    free(line);
    return nullptr;
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
      return nullptr;
    }

    zakirov::get_segment(in, expanded_line, start, finish);
    free(line);
    line = expanded_line;
    start += step;
    last_symbol = expanded_line[finish - 1];
  }

  return line;
}
