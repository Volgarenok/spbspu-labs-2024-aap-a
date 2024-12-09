#include "rm_digits.hpp"
#include <cstddef>
#include <cctype>

char* gavrilova::rm_digits(const char* original, char* new_str)
{
  if (original == nullptr || new_str == nullptr) {
    return nullptr;
  }
  for (; *original; ++original) {
    if (!std::isdigit(*original)) {
      *new_str = *original;
      ++new_str;
    }
  }
  *new_str = '\0';
  return new_str;
}
