#include "string.h"
#include <ios>

int main()
{
  constexpr char stop = '\n';
  constexpr size_t askii_size = 128;
  size_t max_size = 100;
  char* str = nullptr;
  char* ustr1 = nullptr;
  char* ustr2 = nullptr;
  char* final_str = nullptr;

 try
  {
    str = new char[max_size + 1];
    ustr1 = new char[askii_size + 1];
    ustr2 = new char[askii_size + 1];
    final_str = new char[askii_size + 1];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    delete[] ustr1;
    delete[] ustr2;
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

  char base_str[] = "abc ef";
  ustr1 = demehin::getUniqueSymbols(str, ustr1);
  ustr2 = demehin::getUniqueSymbols(base_str, ustr2);
  final_str = demehin::unc_sym(ustr1, ustr2, final_str);
  std::cout << final_str << '\n';

  delete[] ustr1;
  delete[] str;
  delete[] ustr2;
  delete[] final_str;
}
