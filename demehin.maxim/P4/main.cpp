#include "string.h"
#include <iostream>
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
  final_str = new char[askii_size];
  ustr1 = new char[askii_size];
  ustr2 = new char[askii_size];
  try
  {
    str = new char[max_size];
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }

//  size_t size = 0;
//  char temp = '\0';
  std::noskipws(std::cin);

//  while ((std::cin >> temp) && (temp != '\n'))
//  {
//    if (size == max_size)
//    {
//      max_size *= 2;
//      try
//      {
//        str = demehin::copyString(str, max_size);
//      }
//      catch (const std::bad_alloc& e)
//      {
//        std::cerr << "Out of memory\n";
//        return 1;
//      }
//    }
//    str[size++] = temp;
//  }
//  if (!std::cin)
//  {
//    std::cerr << "Input error\n";
//    return 1;
//  }

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
  std::cout << ustr1 << '\n';
  std::cout << ustr2 << '\n';
  std::cout << final_str << '\n';


  delete[] ustr1;
  delete[] str;
  delete[] ustr2;
}
