#include "getline.hpp"

char * brevnov::getline(std::istream& in, char stop)
{
  constexpr std::size_t plus_size = 50;
  std::size_t max_size = 50;
  char * line = new char[max_size + 1];
  char * newline = nullptr;
  std::size_t current_size = 0;
  char c = '\0';
  std::noskipws(in);
  while ((in >> c) && (c != stop))
  {
    if (max_size == current_size)
    {
      try
      {
        newline = brevnov::newmemory(line, max_size, plus_size);
      }
      catch (const std::bad_alloc& e)
      {
        delete[] line;
        throw;
      }
      delete[] line;
      line = newline;
      newline = nullptr;
      max_size += plus_size;
    }
    line[current_size++] = c;
  }
  line[current_size] = 0;
  std::skipws(in);
  return line;
}

char * brevnov::newmemory(const char * line, std::size_t max_size, std::size_t plus_size)
{
  char * new_line = new char[max_size + plus_size + 1];
  for (std::size_t i = 0; i < max_size; ++i)
  {
    new_line[i] = line[i];
  }
  return new_line;
}
