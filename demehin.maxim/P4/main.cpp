#include <ios>
#include <string_utils.h>
#include "unc_sym.h"

int main()
{
  constexpr char stop = '\n';
  constexpr size_t max_size = 100;
  char* first_str = nullptr;

  try
  {
    first_str = demehin::getString(std::cin, stop, max_size);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }

  if (first_str[0] == '\0')
  {
    std::cerr << "Empty string\n";
    delete[] first_str;
    return 1;
  }

  char* final_str = nullptr;
  constexpr size_t askii_size = 128;
  try
  {
    final_str = new char[askii_size];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    delete[] first_str;
    return 1;
  }
  char second_str[] = "abc ef";
  demehin::unc_sym(first_str, second_str, final_str);
  std::cout << second_str << '\n';
  std::cout << final_str << '\n';
  delete[] first_str;
  delete[] final_str;
}
