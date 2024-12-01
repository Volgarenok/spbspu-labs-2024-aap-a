#include <stdexcept>
#include <getline.hpp>
#include "search_repeats.hpp"

int main()
{
  char *str = nullptr;
  std::size_t len = 0;
  try
  {
    str = sveshnikov::read_str(std::cin, len);
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "ERROR: BAD_ALLOC! " << e.what() << '\n';
    return 1;
  }
  if (str[0] == '\0')
  {
    std::cerr << "ERROR: EMPTY INPUT\n";
    delete[] str;
    return 1;
  }
  char *new_str = nullptr;
  try
  {
    new_str = new char[len + 1];
    new_str[0] = '\0';
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << "ERROR: BAD_ALLOC! " << e.what() << '\n';
    delete[] str;
    return 1;
  }
  std::cout << sveshnikov::rep_sym(str, new_str) << "\n";
  delete[] new_str;
  delete[] str;
  return 0;
}
