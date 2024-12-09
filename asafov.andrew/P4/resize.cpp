#include "resize.hpp"

char* asafov::resize(char* string, const unsigned long long lenght) {
  char* new_string = new char[lenght + 8];
  char* old_string = string;
  for (unsigned long long i = 0; i < lenght; i++) {
    new_string[i] = old_string[i];
  }
  delete[] old_string;
  return new_string;
}
