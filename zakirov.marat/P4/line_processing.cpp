#include "line_processing.hpp"
#include <iostream>

void zakirov::change_line(char * line)
{
  char big_letters[26];
  char small_letters[26];
  size_t location = 0;
  for (char i = 'A'; i <= 'Z'; ++i)
  {
    big_letters[location] = i;
    location += 1;
  }

  location = 0;
  for (char i = 'a'; i <= 'z'; ++i)
  {
    small_letters[location] = i;
    location += 1;
  }

  location = 0;
  while (line[location] != '\0')
  {
    for (size_t i = 0; i < 26; ++i)
    {
      if (line[location] == big_letters[i])
      {
        big_letters[i] = ' ';
        small_letters[i] = ' ';
        break;
      }
      else if (line[location] == small_letters[i])
      {
        big_letters[i] = ' ';
        small_letters[i] = ' ';
        break;
      }
    }
    location += 1;
  }

  location = 0;
  for (size_t i = 0; i < 26; ++i)
  {
    if (small_letters[i] != ' ')
    {
      line[location] = small_letters[i];
      location += 1;
    }
  }
  line[location] = '\0';
}
