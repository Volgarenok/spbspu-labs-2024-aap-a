#include "remove_latin_letters.hpp"
#include <cctype>

void kizhin::removeLatinLetters(char* destination, const char* source)
{
  if (destination == nullptr || source == nullptr) {
    return;
  }
  for (const char* i = source; *i != '\0'; ++i) {
    if (!std::isalpha(*i)) {
      *destination = *i;
      ++destination;
    }
  }
  *destination = '\0';
}

