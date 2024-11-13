#include "string.h"
#include <iostream>
#include <cstring>
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

char * cherkasov::inpputLine(std::istream & in)
{
  char * array = nullptr;
  size_t container = 69;
  try
  {
    array = cherkasov::allocMemor(container);
    }
      catch (const std::bad_alloc & e)
      {
        return nullptr;
      }

  size_t currentElement = 0;
  std::noskipws(in);
  while (!in.eof())
  {
    if (currentElement == (container - 1))
    {
      array[currentElement] = '\0';
      container *= 3;
      try
      {
        array = cherkasov::leghtArray(array, container);
      }
        catch (const std::bad_alloc & e)
        {
          delete[] array;
          return nullptr;
        }

  }
    in >> array[currentElement++];
    }
      std::skipws(in);
      array[currentElement - 1] = '\0';
      return array;
}

char * cherkasov::allocMemor(size_t container)
{
  char * array = new char[container];
  return array;
}

char * cherkasov::leghtArray(char * oldArray, size_t newContainer)
{
  char * newArray = cherkasov::allocMemor(newContainer);
  for (size_t i = 0; oldArray[i] != '\0'; i++)
  {
    newArray[i] = oldArray[i];
  }
    delete[] oldArray;
    return newArray;
}


