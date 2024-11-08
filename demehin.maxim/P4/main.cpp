#include "string.h"
#include <iostream>
#include <ios>

int main()
{
  char base_str[] = 'strok_lit';
  size_t max_size = 5;
  char* str = nullptr;
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



  std::cout << str << '\n';
  delete[] str;
}
