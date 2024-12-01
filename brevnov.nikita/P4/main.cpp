#include <iostream>
#include "getline.hpp"
#include "finding_common_elements.hpp"

int main()
{
  constexpr char stop = '\n';
  constexpr size_t size_of_second = 7;
  char * first_line = nullptr;
  char second_line[size_of_second] = "abc ef";
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
  char help_array[size_of_second] = {};
  char * answer = help_array;
  brevnov::finding_common_elements(answer, first_line, second_line);
  std::cout << answer << "\n";
  delete[] first_line;
  return 0;
}
