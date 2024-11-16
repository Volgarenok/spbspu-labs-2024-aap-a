#include "string.h"
#include <ios>

int main()
{
  constexpr char stop = '\n';
  constexpr size_t askii_size = 128;
  size_t max_size = 100;
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

  std::noskipws(std::cin);
  try
  {
    str = demehin::getString(std::cin, stop, str, max_size);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }

  if (str == nullptr)
  {
    delete[] str;
    delete[] final_str;
    return 1;
  }


  char base_str[] = "abc ef";
  char ustr1[askii_size] = {};
  char ustr2[askii_size] = {};
  demehin::getUniqueSymbols(str, ustr1);
  demehin::getUniqueSymbols(base_str, ustr2);
  final_str = demehin::unc_sym(ustr1, ustr2, final_str);
  std::cout << final_str << '\n';

  delete[] str;
  delete[] final_str;
}
