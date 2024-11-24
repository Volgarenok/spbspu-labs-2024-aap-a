#include "line_processing.hpp"
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

void zakirov::change_line(char * line)
{
  char alphabet[52];
  size_t location = 0;
  for (char i = 'A'; i <= 'Z'; ++i)
  {
    alphabet[location] = i;
    location += 1;
  }
  for (char i = 'a'; i <= 'z'; ++i)
  {
    alphabet[location] = i;
    location += 1;
  }

  location = 0;
  while (line[location] != '\0')
  {
    for (size_t i = 0; i < 26; ++i)
    {
      if (line[location] == alphabet[i] || line[location] == alphabet[i + 26])
      {
        alphabet[i] = ' ';
        alphabet[i + 26] = ' ';
        break;
      }
    }
    location += 1;
  }

  for (size_t i = 0; i < 52; ++i)
  {
    std::cout << alphabet[i];
  }
  std::cout << '\n';

  location = 0;
  for (size_t i = 26; i < 52; ++i)
  {
    if (alphabet[i] != ' ')
    {
      line[location] = alphabet[i];
      location += 1;
    }
  }
  line[location] = '\0';
}
