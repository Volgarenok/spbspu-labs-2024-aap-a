#include "inputStr.hpp"
#include <istream>

char* inputStr(std::istream& in)
{
  char* result_str = nullptr;
  constexpr int K = 100;
  try {
    result_str = new char [K];
  } catch (const std::bad_alloc & e) {
    return nullptr;
  }
  char c;
  size_t len = 0;
  in >> std::noskipws;
  while ((in >> c)) {
    if (c == '\n'){
      break;
    }
    if (len < K - 1) {
      result_str[len++] = c;
    } else {
      char * temp = nullptr;
      try {
        temp = new char [len + K];
      } catch (const std::bad_alloc & e) {
        delete[] result_str;
        return nullptr;
      }
      for (size_t i = 0; i < len; ++i) {
        temp[i] = result_str[i];
      }
      delete[] result_str;
      result_str = temp;
      result_str[len++] = c;
    }
  }
  result_str[len] = '\0';

  if (!in){
    delete[] result_str;
    return nullptr;
  }
  delete[] result_str;
  return result_str;
}
