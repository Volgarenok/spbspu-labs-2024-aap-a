#include "string_utils.h"
#include <stdexcept>

char* demehin::copyString(const char* str, size_t size)
{
  size_t temp_size = 0;
  char* new_str = new char[size];

  while (str[temp_size] != '\0')
  {
    new_str[temp_size] = str[temp_size];
    temp_size++;
  }
  new_str[temp_size] = '\0';
  return new_str;
}


std::istream& demehin::getString(std::istream& in, char** str, char stop, size_t max_size, size_t& read)
{
  *str = new char[max_size];
  (*str)[0] = '\0';
  size_t size = 0;
  char temp = '\0';
  std::noskipws(in);

  while ((in >> temp) && (temp != stop))
  {
    if (size + 1 >= max_size)
    {
      (*str)[size] = '\0';
      max_size *= 2;
      char* new_str = nullptr;

      try
      {
        new_str = copyString(*str, max_size);
      }
      catch (const std::bad_alloc& e)
      {
        std::skipws(in);
        throw;
      }

      delete[] *str;
      *str = new_str;
    }
    (*str)[size++] = temp;
    read++;
  }

  (*str)[size] = '\0';
  std::skipws(in);
  return in;
}
