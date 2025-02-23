#include "resize_line.hpp"
#include <cstddef>

void zakirov::get_segment(std::istream & in, char * line, size_t start, size_t finish, char interrupt_el)
{
  for (; start < finish; ++start)
  {
    if (!in)
    {
      throw std::logic_error("The stream is broken");
    }

    in >> line[start];
    if (in.eof() || (line[start] == interrupt_el))
    {
      line[start] = '\0';
      break;
    }
  }
}

char * zakirov::get_to_symbol(std::istream & in, size_t step, char interrupt_symbol)
{
  size_t start = 1, finish = 1;
  char * line = static_cast< char * >(malloc(sizeof(char)));
  if (line == nullptr)
  {
    return line;
  }
  else if (!in)
  {
    free(line);
    return nullptr;
  }

  char last_symbol = interrupt_symbol;
  in >> last_symbol >> std::noskipws;
  line[0] = last_symbol;
  while (last_symbol != interrupt_symbol && last_symbol != '\0')
  {
    char * expanded_line = extra_elements(line, finish, step);
    finish += step;
    if (expanded_line == nullptr)
    {
      free(line);
      return expanded_line;
    }

    try
    {
      get_segment(in, expanded_line, start, finish, interrupt_symbol);
    }
    catch (const std::exception &)
    {
      free(expanded_line);
      free(line);
      return nullptr;
    }

    free(line);
    line = expanded_line;
    for (size_t i = start; i < finish; ++i)
    {
      last_symbol = line[i];
      if (line[i] == interrupt_symbol || line[i] == '\0')
      {
        break;
      }
    }

    start += step;
  }

  in >> std::skipws;
  return line;
}
