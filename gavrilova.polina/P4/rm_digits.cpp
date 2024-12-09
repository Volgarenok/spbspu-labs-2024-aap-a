#include "rm_digits.hpp"
#include <cstddef>
#include <cctype>

char* gavrilova::rm_digits(const char* original, char* new_str)
{
  if (original == nullptr || new_str == nullptr) {
    return nullptr;
  }
  size_t ind_new_str = 0;
  for (size_t i = 0; *(original + i) != '\0'; ++i) {
    if (!isdigit(*(original + i))) {
      *(new_str + ind_new_str) = *(original + i);
      ++ind_new_str;
    }
  }
  new_str[ind_new_str] = '\0';
  return new_str;
}
