#include "line_processing.hpp"
#include <iostream>

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
