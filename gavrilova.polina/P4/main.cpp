#include <iostream>
#include <cctype>

char * rm_digits (const char * original, char * new_str)
{
  size_t j = 0;
  for (size_t i = 0; i != "\0"; ++i) {
    if (!isdigit) {
      new_str[j] = original[i];
    }
    ++j;
  }
  return new_str;
}

int main()
{
  size_t n = 0;
  char * first_str = nullptr;
  //input + узнать сколько символов
  char * result_str = nullptr;
  try {
    result_str = new char [n];
  } catch (const std::bad_alloc & e) {
    std::cerr << "Memory error.";
    return 1;
  }

  rm_digits(first_str, result_str);
  std::cout << result_str;
}
