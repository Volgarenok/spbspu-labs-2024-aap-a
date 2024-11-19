#include <stdexcept>
#include "rep_sym.hpp"

int main()
{
  std::size_t len = 100;
  char *str = nullptr;
  try
  {
    str = new char[len];
    str = sveshnikov::read_str(std::cin, str, &len);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "ERROR: BAD_ALLOC! " << e.what() << '\n';
    delete[] str;
    return 1;
  }
  catch (const std::istream::failure &e)
  {
    std::cerr << "ERROR: CAN NOT READ! " << e.what() << '\n';
    delete[] str;
    return 1;
  }
  char *new_str = nullptr;
  try
  {
    new_str = new char[len + 1]{'\0'};
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "ERROR: BAD_ALLOC! " << e.what() << '\n';
    delete[] str;
    return 1;
  }
  new_str = sveshnikov::rep_sym(str, new_str);
  for (std::size_t i = 0; new_str[i] != '\0'; i++)
  {
    std::cout << new_str[i];
  }
  std::cout << "\n";
  delete[] str;
  delete[] new_str;
  return 0;
}
