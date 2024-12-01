#include "has_sam_set.h"
#include <iostream>

char* timofeev::input_line(std::istream& in)
{
  size_t capacity = 40;
  char* line = reinterpret_cast< char* >(malloc(capacity + 1));
  if (line == nullptr)
  {
    return nullptr;
  }
  line[0] = '0';
  in >> line[0];
  if (line[0] == '\0' || std::cin.eof())
  {
    free(line);
    std::skipws(in);
    return nullptr;
  }
  size_t cur_writing_lit = 1;
  char cur_sym = '\0';
  std::noskipws(in);
  while((in >> cur_sym) && (cur_sym != '\n'))
  {
    if (cur_writing_lit == capacity)
    {
      constexpr size_t memory_boost = 10;
      capacity += memory_boost;
      char* new_line = reinterpret_cast< char* >(malloc(capacity + 1));;
      if (new_line == nullptr)
      {
        free(line);
        std::skipws(in);
        return nullptr;
      }
      for (size_t i = 0; i < cur_writing_lit; i++)
      {
        new_line[i] = line[i];
      }
      free(line);
      line = new_line;
    }
    line[cur_writing_lit++] = cur_sym;
  }
  line[cur_writing_lit] = '\0';
  std::skipws(in);
  return line;
}
