#include "search_repeats.hpp"

char *sveshnikov::memory_alloc(char *str, std::size_t len)
{
  char *longer_str = nullptr;
  longer_str = new char[len];
  for (std::size_t i = 0; i < len - 100; i++)
  {
    longer_str[i] = str[i];
  }
  return longer_str;
}
