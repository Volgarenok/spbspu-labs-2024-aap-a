#include "checkChar.hpp"
#include <cctype>
#include <cstddef>

size_t dribas::checkChar(const char* str)
{
  size_t result = 0;
  if (isalpha(str[0])) {
    result += 1;
  }
  if (str[0] == '\0') {
    return 0;
  }
  for (size_t i = 1; str[i] != '\0'; i += 1) {
    if (isalpha(str[i])) {
      bool check = true;
      for (int j = i - 1; j > 0; j -= 1) {
        if (str[i] == str[j] || !(isalpha(str[i]))) {
          check = false;
          break;
        }
      }
      if (check) {
        result += 1;
      }
    }
  }
  return result;
}
