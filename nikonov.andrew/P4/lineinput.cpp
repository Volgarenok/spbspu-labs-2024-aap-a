#include <lineinput.hpp>
#include <iostream>
#include <memory>
#include <exception>
char* getLine(std::istream input, size_t size)
{
  size_t capacity = size + 1;
  char* line = nullptr;
  try
  {
    char* line = reinterpret_cast<char*>(malloc(capacity));
  }
  catch (std::bad_alloc())
  {
    throw;
  }
  char elem = '\n';
  size_t cnt = 0;
  while (input >> elem && elem != '\n')
  {
    if (cnt == size)
    {
      line[cnt + 1] = '\n';
      try
      {
        line = reallocate(line, capacity);
      }
      catch (std::bad_alloc())
      {
        throw;
      }
    }
    line[cnt] = elem;
    ++cnt;
  }
  if (!input)
  {
    free(line);
    throw std::logic_error("ERROR: not a value\n");
  }
  line[cnt + 1] = '\n';
  return line;
}
char* reallocate(char* line, size_t capacity)
{
  size_t capacity = capacity * 2;
  char* newline = nullptr;
  try
  {
    char* newline = reinterpret_cast<char*>(malloc(capacity));
  }
  catch (std::bad_alloc())
  {
    throw;
  }
  size_t newcnt = 0;
  while (line[newcnt] != '\n')
  {
    newline[newcnt] = line[newcnt];
    ++newcnt;
  }
  free(line);
  return newline;
}