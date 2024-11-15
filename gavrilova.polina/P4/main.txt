#include <iostream>
#include <cctype>

char * rm_digits (const char * original, char * new_str)
{
  size_t j = 0;
  for (size_t i = 0; original[i] != '\0'; ++i) {
    if (!isdigit(original[i])) {
      new_str[j++] = original[i];
    }
  }
  new_str[j] = '\0';
  return new_str;
}

int main()
{
  char * first_str = nullptr;
  constexpr int K = 100;
  try {
    first_str = new char [K];
  } catch (const std::bad_alloc & e) {
    std::cerr << "Memory errorr\n";
    return 1;
  }
  char c = '\0';
  size_t len = 0;
  std::noskipws(std::cin);
  while ((std::cin) && c != '\n') {
    if (len < K - 1) {
      first_str[len++] = c;
    } else {
      char * temp = nullptr;
      try {
        temp = new char [len + K];
      } catch (const std::bad_alloc & e) {
        std::cerr << "Memory errorr\n";
        delete[] first_str;
        return 1;
      }
      for (size_t i = 0; i < len; ++i) {
        temp[i] = first_str[i];
      }
      delete[] first_str;
      first_str = temp;
      first_str[len++] = c;
    }
  }
  first_str[len] = '\0';

  char * result_str = nullptr;
  try {
    result_str = new char [len+1];
  } catch (const std::bad_alloc & e) {
    std::cerr << "Memory error.";
    delete[] first_str;
    return 1;
  }

  rm_digits(first_str, result_str);
  std::cout << result_str << "\n";
  delete[] result_str;
  delete[] first_str;
}
