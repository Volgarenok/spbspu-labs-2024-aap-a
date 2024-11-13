#include "string.h"
#include <iostream>
#include <cstring>
#include <cctype>
#include <new>

char * cherkasov::getString(const char * input, std::size_t size) noexcept
{
  if (size == 0) return nullptr;
  int counts[256] = {0};
  for (std::size_t i = 0; i < size; ++i)
  {
    unsigned char ch = static_cast < unsigned char > (input[i]);
    counts[ch]++;
  }

  std::size_t newStrSize = 0;
  for (std::size_t i = 0; i < 256; ++i)
  {
   if (counts[i] > 1) newStrSize++;
  }

  char* result = nullptr;
  try
  {
    result = new char[newStrSize + 1];
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "ERROR: failed to allocate memory\n";
      std::exit(1);
    }

  std::size_t pos = 0;
  for (std::size_t i = 0; i < 256; ++i)
  {
    if (counts[i] > 1)
    {
      result[pos++] = static_cast<char>(i);
    }
  }
    result[pos] = '\0';

    return result;
}

