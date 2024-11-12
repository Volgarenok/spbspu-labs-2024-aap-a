#include "functions.h"
#include <iostream>

char* timofeev::input_line(std::istream& in)
{
  size_t capacity = 40;
  char* line = nullptr;
  try
  {
    line = add_memory(capacity);
  }
  catch(const std::bad_alloc& e)
  {
    return nullptr;
  }
  size_t cur_writing_lit = 0;
  char cur_sym = '\0';
  std::noskipws(in);
  while((in >> cur_sym) && (cur_sym != '\n'))
  {
    if (cur_writing_lit == capacity)
    {
      try
      {
        line = timofeev::boost_size(line, capacity);
      }
      catch(const std::bad_alloc& e)
      {
        free(line);
        std::cerr << "Out of memory\n";
        return nullptr;
      }
    }
    line[cur_writing_lit++] = cur_sym;
  }
  std::skipws(in);
  free(line);
  return line;
}
