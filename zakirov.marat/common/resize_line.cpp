#include "resize_line.hpp"
#include <iostream>

char * zakirov::expand_line(char * regular_line, size_t real_lenght, size_t add_length)
{
  char * expanded_line = static_cast<char *>(malloc((sizeof(char) * real_lenght) + (sizeof(char) * add_length)));
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

void zakirov::get_line(std::istream & in, char * line, size_t start, size_t finish)
{
  for (; start < finish; ++start)
  {
    in >> line[start];
    if (line[start] == '\0')
    {
      break;
    }
  }
}
