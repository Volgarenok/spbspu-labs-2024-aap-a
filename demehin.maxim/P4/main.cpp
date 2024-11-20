#include <ios>
#include "string.h"

int main()
{
  constexpr char stop = '\n';
  constexpr size_t askii_size = 128;
  constexpr size_t max_size = 100;
  char* str = nullptr;
  char* final_str = nullptr;

 try
  {
    str = new char[max_size];
    final_str = new char[askii_size];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    delete[] final_str;
    delete[] str;
    return 1;
  }

  str[0] = '\0';
  try
  {
    str = demehin::getString(std::cin, stop, str, max_size);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    delete[] str;
    delete[] final_str;
    return 1;
  }

  if (str[0] == '\0')
  {
    std::cerr << "Empty string\n";
    delete[] str;
    delete[] final_str;
    return 1;
  }


  char base_str[] = "abc ef";
  demehin::unc_sym(str, base_str, final_str);
  std::cout << final_str << '\n';
  delete[] str;
  delete[] final_str;
}
