#include <stringinput.hpp>

char* tkach::getMemoryForStr(const char* str, size_t& capacity)
{
  char* new_str = static_cast< char* >(malloc(capacity * 2));
  if (new_str == nullptr)
  {
    return nullptr;
  }
  capacity *= 2;
  for (size_t i = 0; str[i] != '\0'; ++i)
  {
    new_str[i] = str[i];
  }
  return new_str;
}
