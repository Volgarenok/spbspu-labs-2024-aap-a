#include "line_processing.hpp"
#include <iostream>

char * zakirov::expand_line(char * regular_line, size_t real_lenght, size_t add_length)
{
  char * expand_line = static_cast<char *>(malloc((sizeof(char) * real_lenght) + (sizeof(char) * add_length)));
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
    if (line[start] == '\0')
    {
      break;
    }
  }

  if (line[start] == '\0')
  {
    start += 1;
    for (; start < finish; ++start)
    {
      line[start] = '\n';
    }
  }

  return line;
}

void zakirov::change_line(char * line)
{
  char alphabet[52];
  size_t location = 0;
  for (char i = 65; i < 91; ++i)
  {
    alphabet[location] = i;
    location += 1;
  }
  for (char i = 97; i < 123; ++i)
  {
    alphabet[location] = i;
    location += 1;
  }

  location = 0;
  for (size_t i = 0; i < 26; ++i)
  {
    while(line[location] != '\0')
    {
      if (line[location] == alphabet[i] || line[location] == alphabet[i + 26])
      {
        alphabet[i] = 32;
        alphabet[i + 26] = 32;
      }
      location += 1;
    }
    location = 0;
  }
  for (size_t i = 26; i < 52; ++i)
  {
    if (alphabet[i] != 32)
    {
      line[location] = alphabet[i];
      location += 1;
    }
  }
  while (line[location] != '\0')
  {
    line[location]  = '\0';
    location += 1;
  }
}
