#include <iostream>
#include <read_input_array.hpp>
#include "recursion.hpp"

int main()
{
  char * stest = "2*B*(A+4)";
  char * s1 = nullptr;
  try
  {
    s1 = kushekbaev::readInputArray(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Out of memory" << "\n";
    return 1;
  }
  if (s1 == nullptr)
  {
    std::cerr << "Failed to allocate memory" << "\n";
    return 1;
  }
  if (s1[0] == '\0')
  {
    delete[] s1;
    std::cerr << "Dry run" << "\n";
    return 1;
  }
  std::cout << kushekbaev::isValidExpression(s1) << "\n";
  std::cout << kushekbaev::isValidExpression(stest) << "\n";
  delete[] s1;
  return 0;
}
