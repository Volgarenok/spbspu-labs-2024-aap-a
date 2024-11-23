#include <iostream>
#include "getline.hpp"
#include "finding_common_elements.hpp"

int main()
{
  constexpr char stop = '\n';
  char * first_line = nullptr;
  char second_line[] = "abc ef";
  try
  {
    first_line = brevnov::getline(std::cin, stop);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Not enough memory\n";
    return 1;
  }
  if (first_line[0] == 0)
  {
    std::cerr << "Empty input\n";
    delete[] first_line;
    return 1;
  }
  char help_array[10000] = {};
  char * answer = help_array;
  brevnov::finding_common_elements(answer, first_line, second_line);
  std::cout << answer << "\n";
  delete[] first_line;
  return 0;
}
