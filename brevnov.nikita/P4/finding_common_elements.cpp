#include "finding_common_elements.hpp"
#include <iostream>

void brevnov::finding_common_elements(std::ostream& out, char * first_line, char * second_line)
{
  std::size_t element_of_first = 0;
  while (first_line[element_of_first] != 0)
  {
    std::size_t element_of_second = 0;
    while(second_line[element_of_second] != 0)
    {
      if (first_line[element_of_first] == second_line[element_of_second])
      {
        second_line[element_of_second] = '\n';
        out << first_line[element_of_first];
        break;
      }
      element_of_second++;
    }
    element_of_first++;
  }
}
