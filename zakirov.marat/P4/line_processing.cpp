#include "line_processing.hpp"
#include <iostream>

char * zakirov::expand_line(char * regular_line, size_t real_lenght, size_t add_length)
{
  char * expand_line = (char *)malloc((sizeof(char) * real_lenght) + (sizeof(char) * add_length));
  for (size_t i = 0; i < real_lenght; ++i)
  {
    expand_line[i] = regular_line[i];
  }

  free(regular_line);
  return expand_line;
}

char * zakirov::get_line(std::istream & in, char * line, size_t start, size_t finish)
{
  for (; start < finish; ++start)
  {
    in >> line[start];
    if (line[start] = '\0')
    {
      break;
    }
  }

  if (line[start] = '\0')
  {
    start += 1;
    for (; start < finish; ++start)
    {
      line[start] = '\n';
    }
  }

  return line;
}

char * zakirov::change_line(char * line, char stop)
{

}
