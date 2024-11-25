#include "finding_common_elements.hpp"
#include <iostream>

void brevnov::finding_common_elements(char * answer, const char * first_line, char * second_line)
{
  while (*first_line != 0)
  {
    while (*second_line != 0)
    {
      if (*first_line == *second_line)
      {
        *second_line = '\n';
        *answer = *first_line;
        answer++;
        break;
      }
      second_line++;
    }
    first_line++;
  }
}
