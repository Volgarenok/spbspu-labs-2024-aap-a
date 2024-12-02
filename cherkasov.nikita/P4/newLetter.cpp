#include "newLetter.h"
#include <cstddef>
#include <cstring>
#include <iostream>
#include <cstdlib>

char* cherkasov::newLetter(char* array, char oldChar, char newChar)
{
  if (!array)
  {
    std::cerr << "Ошибка: входная строка пуста.\n";
    return nullptr;
  }
  try
  {
    char* result = new char[std::strlen(array) + 1];
    const char* src = array;
    char* dest = result;
    while (*src)
    {
      *dest++ = (*src == oldChar) ? newChar : *src;
      ++src;
    }
    *dest = '\0';
    return result;
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Ошибка выделения памяти: " << e.what() << "\n";
    return nullptr;
  }
}

