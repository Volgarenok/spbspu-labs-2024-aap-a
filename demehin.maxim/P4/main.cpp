#include "string.h"
#include <ios>

int main()
{
  constexpr char stop = '\n';
  constexpr size_t askii_size = 128;
  size_t max_size = 100;
  char* str = nullptr;
  char* temp_str = nullptr;

 try
  {
    str = new char[max_size];
    temp_str = new char[askii_size];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    delete[] temp_str;
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
    delete[] temp_str;
    return 1;
  }

   if (str[0] == '\0')
   {
     std::cerr << "Empty string\n";
     delete[] str;
     delete[] temp_str;
     return 1;
   }


  char base_str[] = "abc ef";
  char ustr1[askii_size] = {};
  char ustr2[askii_size] = {};
  demehin::getUniqueSymbols(str, ustr1);
  demehin::getUniqueSymbols(base_str, ustr2);
  size_t final_size = 0;
  final_size = demehin::unc_sym(ustr1, ustr2, temp_str);

  char* final_str = nullptr;
  try
  {
    final_str = new char[final_size + 1];
  }
  catch (std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    delete[] final_str;
    delete[] str;
    return 1;
  }

  for (size_t i = 0; i < final_size; ++ i)
  {
    final_str[i] = temp_str[i];
  }
  final_str[final_size] = '\0';
  size_t iter = 0;
  while (final_str[iter] != '\0')
  {
    std::cout << final_str[iter++];
  }
  std::cout << '\n';

  delete[] temp_str;
  delete[] str;
  delete[] final_str;
}
