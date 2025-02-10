#include "resize_line.hpp"
#include <cstddef>

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
  for (; start < finish; ++start)
  {
    in >> line[start];
    if (in.eof())
    {
      line[start] = '\0';
      break;
    }
  }
}

char * zakirov::get_line(std::istream & in, size_t step)
{
  size_t start = 1, finish = 1;
  char * line = static_cast< char * >(malloc(sizeof(char)));
  if (line == nullptr)
  {
    return line;
  }
  char last_symbol = '\0';
  in >> last_symbol;
  line[0] = last_symbol;
  while (last_symbol != '\0')
  {
    char * expanded_line = zakirov::expand_line(line, finish, step);
    finish += step;
    if (expanded_line == nullptr)
    {
      free(line);
      return expanded_line;
    }

    zakirov::get_segment(in, expanded_line, start, finish);
    free(line);
    line = expanded_line;
    for (size_t i = start; i < finish; ++i)
    {
      if (line[i] == '\0')
      {
        last_symbol = line[i];
        break;
      }
      else if (i == finish - 1)
      {
        last_symbol = line[i];
      }
    }

    start += step;
  }

  return line;
}
