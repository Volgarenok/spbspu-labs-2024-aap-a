#include "rm_digits.hpp"
#include <cstddef>
#include <cctype>

char * rm_digits (const char * original, char * new_str)
{
  if (original == nullptr || new_str == nullptr) {
    return nullptr;
  }
  size_t j = 0;
  for (size_t i = 0; original[i] != '\0'; ++i) {
    if (!isdigit(original[i])) {
      new_str[j++] = original[i];
    }
  }
  new_str[j] = '\0';
  return new_str;
}
