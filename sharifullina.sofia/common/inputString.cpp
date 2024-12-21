#include "inputString.hpp"

char * sharifullina::inputstring(std::istream & in, char stop)
{
  size_t capacity = 10;
  char * str = new char[capacity];
  size_t size = 0;
  char ch = '\0';
  std::noskipws(in);
  while ((in >> ch) && (ch != stop))
  {
    if (capacity == size)
    {
      capacity = capacity * 2;
      char * newstr = nullptr;
      try
      {
        newstr = new char[capacity];
      }
      catch (const std::bad_alloc & e)
      {
        delete[] str;
        std::skipws(in);
        throw;
      }
      for (size_t i = 0; i < size; ++i)
      {
        newstr[i] = str[i];
      }
      delete[] str;
      str = newstr;
    }
    str[size++] = ch;
  }
  str[size] = '\0';
  in >> std::skipws;
  return str;
}
namespace
{
  char * fillStringRecursive(const char* buffer, size_t index, size_t length)
  {
    if (index == length)
    {
      char * str = nullptr;
      try
      {
        str = new char[length + 1];
      }
      catch (const std::bad_alloc&)
      {
        return nullptr;
      }
      str[length] = '\0';
      return str;
    }
    char * str = fillStringRecursive(buffer, index + 1, length);
    if (str != nullptr)
    {
      str[index] = buffer[index];
    }
    return str;
  }
}

char * sharifullina::inputStringRecursive(std::istream& in, char stop)
{
  if (!in)
  {
    return nullptr;
  }
  const size_t maxSize = 1024;
  char inputBuffer[maxSize];
  size_t length = 0;
  char ch = '\0';
  std::noskipws(in);
  while ((in >> ch) && (ch != stop))
  {
    if (length >= maxSize)
    {
       return nullptr;
    }
    inputBuffer[length++] = ch;
  }
  return fillStringRecursive(inputBuffer, 0, length);
}
