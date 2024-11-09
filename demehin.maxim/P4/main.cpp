#include "string.h"
#include <iostream>
#include <ios>

int main()
{
  char base_str[] = "strok_lit";
  size_t max_size = 5;
  char* str = nullptr;
  char* ustr1 = nullptr;
  char* ustr2 = nullptr;
  char* final_str = nullptr;
  final_str = new char[128];
  ustr1 = new char[128];
  ustr2 = new char[128];
  try
  {
    str = new char[max_size];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }

  size_t size = 0;
  char temp = '\0';
  std::noskipws(std::cin);

  while ((std::cin >> temp) && (temp != '\n'))
  {
    if (size == max_size)
    {
      max_size *= 2;
      try
      {
        str = demehin::copyString(str, max_size);
      }
      catch (const std::bad_alloc& e)
      {
        std::cerr << "Out of memory\n";
        return 1;
      }
    }
    str[size++] = temp;
  }

  

  ustr1 = demehin::getUniqueSymbols(str, ustr1);
  ustr2 = demehin::getUniqueSymbols(base_str, ustr2);
  final_str = demehin::unc_sym(ustr1, ustr2, final_str);
  std::cout << ustr1 << '\n';
  std::cout << ustr2 << '\n';
  std::cout << final_str << '\n';


  delete[] ustr1;
  delete[] str;
  delete[] ustr2;
}
