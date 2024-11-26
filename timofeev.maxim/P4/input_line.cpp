#include "functions.h"
#include <iostream>

char* timofeev::input_line(std::istream& in)
{
  size_t capacity = 40;
  char* line = reinterpret_cast<char*>(malloc(sizeof(char) * (capacity + 1)));
  if (line == nullptr)
  {
    free(line);
    return nullptr;
  }
  line[capacity] = '\0';
  line[0] = '8';
  in >> line[0];
  if (line[0] == '\0' || std::cin.eof())
  {
    free(line);
    return nullptr;
  }
  size_t cur_writing_lit = 1;
  char cur_sym = '\0';
  std::noskipws(in);
  while((in >> cur_sym) && (cur_sym != '\n'))
  {
    if (cur_writing_lit == capacity)
    {
      try
      {
        char* new_line = timofeev::boost_size(line, capacity);
        free(line);
        line = new_line;
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
  line[cur_writing_lit] = '\0';
  std::skipws(in);
  free(line);
  return line;
}
