#include <iostream>
<<<<<<< HEAD
#include <read_string.hpp>
=======
>>>>>>> parent of f7ab4f9b (Revert "Merge branch 'dribas.sergey/P6' into dribas.sergey/P4")
#include "exc_snd.hpp"

constexpr char exclude_characters[] = "abc";

int main()
{
  char* str = zholobov::read_string(std::cin);
  if (str == nullptr) {
    std::cerr << "Failed to read input string\n";
    return 1;
  }
<<<<<<< HEAD
  if (*str == '\0') {
    std::cerr << "Empty string was entered\n";
    std::free(str);
    return 1;
  }
=======
>>>>>>> parent of f7ab4f9b (Revert "Merge branch 'dribas.sergey/P6' into dribas.sergey/P4")
  char* result = zholobov::exc_snd(str, str, exclude_characters);
  std::cout << result << "\n";
  std::free(str);
  return 0;
}
