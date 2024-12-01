#include "line_processing.hpp"
#include <iostream>

void zakirov::get_missing_letters(char * line)
{
  constexpr size_t alphabet_lenght = 26;
  char big_letters[alphabet_lenght];
  char small_letters[alphabet_lenght];
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
    for (size_t i = 0; i < alphabet_lenght; ++i)
    {
      if (line[location] == big_letters[i] || line[location] == small_letters[i])
      {
        big_letters[i] = ' ';
        small_letters[i] = ' ';
        break;
      }
    }
    location += 1;
  }

  location = 0;
  for (size_t i = 0; i < alphabet_lenght; ++i)
  {
    if (small_letters[i] != ' ')
    {
      line[location] = small_letters[i];
      location += 1;
    }
  }
  line[location] = '\0';
}
