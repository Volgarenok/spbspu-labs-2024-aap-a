#include "string.h"
#include <iostream>
#include <ios>

int main()
{
  //const char base_str[] = "strok_lit";
  size_t max_size = 5;
  char* str = nullptr;
  char* ustr = nullptr;
  ustr = new char[128];
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

  //char final_str[128] = {};

  ustr = demehin::getUniqueSymbols(str, ustr);
  std::cout << ustr << '\n';
  std::cout << str << '\n';
  delete[] str;
}
