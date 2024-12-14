#include <stringinput.hpp>

char* tkach::inputStr(std::istream& in, size_t& capacity)
{
  char* str = reinterpret_cast< char* >(malloc(capacity));
  if (str == nullptr)
  {
    return nullptr;
  }
  size_t str_length = 0;
  char symbol = '\0';
  in >> std::noskipws;
  while (in >> symbol && symbol != '\n')
  {
    if (str_length + 1 == capacity)
    {
      str[str_length] = '\0';
      char* newStr = getMemoryForStr(str, capacity);
      free(str);
      if (newStr == nullptr)
      {
        return nullptr;
      }
      str = newStr;
    }
    str[str_length++] = symbol;
  }
  str[str_length] = '\0';
  return str;
}
