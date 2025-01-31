#include "getline.hpp"

char *sveshnikov::memory_alloc(const char *str, std::size_t len)
{
  char *longer_str = new char[len];
  char *element = longer_str;
  for (const char *i = str; *i != '\0'; i++)
  {
    *element = *i;
    element++;
  }
  return longer_str;
}
