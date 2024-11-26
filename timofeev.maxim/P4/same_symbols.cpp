#include "functions.h"
#include <iostream>

int timofeev::same_symbols(const char* first_line, const char* second_line)
{
  for (size_t i = 0; first_line[i] != '\0'; i++)
  {
    for (*second_line != '\0'; second_line++)
    {
      if (first_line[i] == second_line[j])
      {
        return 1;
      }
    }
  }
  return 0;
}
