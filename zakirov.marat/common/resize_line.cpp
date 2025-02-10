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

double * zakirov::expand_line(const double * array, size_t size)
{
  size_t new_size = size * sizeof(double) + sizeof(double);
  double * new_array = static_cast< double * >(malloc(new_size));
  if (new_array == nullptr)
  {
    return new_array;
  }

  for (size_t i = 0; i < size; ++i)
  {
    new_array[i] = array[i];
  }

  return new_array;
}

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

char * zakirov::get_line(std::istream & in, size_t step, char interrupt_el = '\0')
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

  char last_symbol = interrupt_el;
  in >> last_symbol >> std::noskipws;
  line[0] = last_symbol;
  while (last_symbol != interrupt_el && last_symbol != '\0')
  {
    char * expanded_line = zakirov::expand_line(line, finish, step);
    finish += step;
    if (expanded_line == nullptr)
    {
      free(line);
      return nullptr;
    }

    try
    {
      get_segment(in, expanded_line, start, finish, interrupt_el);
    }
    catch (const std::logic_error &)
    {
      free(expanded_line);
      free(line);
      throw;
    }

    free(line);
    line = expanded_line;
    for (size_t i = start; i < finish; ++i)
    {
      if (line[i] == interrupt_el || line[i] == '\0')
      {
        last_symbol = line[i];
        break;
      }
    }

    last_symbol = line[finish - 1];
    start += step;
  }

  in >> std::skipws;
  return line;
}
