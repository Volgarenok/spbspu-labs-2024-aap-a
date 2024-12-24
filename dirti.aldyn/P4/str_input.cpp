#include "str_input.hpp"

char * dirti::new_storage(char * str, size_t & capacity)
{
  capacity += 1;
  char * str2 = reinterpret_cast< char * >(malloc(sizeof(char) * capacity));
  if (str2 == nullptr)
  {
    return nullptr;
  }
  for (size_t i = 0; i < (capacity - 1); ++i)
  {
    str2[i] = str[i];
  }
  return str2;
}

char * dirti::str_input(std::istream & input)
{
  char c = '\0';
  size_t capacity = 2;
  size_t size = 1;
  char * str = reinterpret_cast< char * >(malloc(sizeof(char) * capacity));
  if (str == nullptr)
  {
    return nullptr;
  }
  std::noskipws(input);
  if (input >> c)
  {
    str[0] = c;
    str[1] = '\0';
  }
  else
  {
    free(str);
    std::skipws(input);
    return nullptr;
  }
  while ((input >> c) && (c != '\n'))
  {
    char * str2 = new_storage(str, capacity);
    free(str);
    if (str2 == nullptr)
    {
      std::skipws(input);
      return nullptr;
    }
    str = str2;
    str[size++] = c;
  }
  free(str2);
  str[size] = '\0';
  std::skipws(input);
  return str;
}
