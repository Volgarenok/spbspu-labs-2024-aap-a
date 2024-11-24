#include <stdexcept>
#include "search_repeats.hpp"

int main()
{
  char *str = nullptr;
  try
  {
    str = sveshnikov::read_str(std::cin);
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
  std::size_t len_new_str = 0;
  for (char *i = str; *i != '\0'; i++)
  {
    len_new_str++;
  }
  const int LEN = len_new_str;
  char new_str[LEN] = {};
  std::cout << sveshnikov::rep_sym(str, new_str) << "\n";
  delete[] str;
  return 0;
}
