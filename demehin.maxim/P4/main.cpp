#include <ios>
#include <string_utils.h>
#include "unc_sym.h"

int main()
{
  constexpr char stop = '\n';
  constexpr size_t max_size = 100;
  size_t read = 0;

  char* first_str = nullptr;
  try
  {
    if (!demehin::getString(std::cin, &first_str, stop, max_size, read))
    {
      std::cerr << "istream error\n";
      delete[] first_str;
      return 1;
    }
  }
  catch (const std::bad_alloc& e)
  {
    if (read == 0)
    {
      std::cerr << "Out of memory\n";
      return 1;
    }
    else
    {
      std::cerr << "String expansion failed\n";
    }
  }

  if (read == 0)
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
  std::cout << final_str << '\n';
  delete[] first_str;
  delete[] final_str;
}
