#include "enterStr.hpp"
#include <iostream>
#include <ios>
#include <cstddef>
#include "changeArr.hpp"

void dribas::enterStr(char*& str)
{
  size_t strsize = 1;
  char letter = 0;
  str = dribas::changeArr(str, strsize);
  std::noskipws(std::cin);
  std::cin >> letter;
  for (size_t i = 0; letter != '\n'; i += 1) {
    if (str == nullptr) {
      letter = '\n';
      std::cerr << "ERROR WITH MEMORY\n";
    } else if (!std::cin) {
      free(str);
      str = nullptr;
      letter = '\n';
      std::cerr << "ERROR WITH INPUT!!\n";
    } else {
      strsize += 1;
      str = dribas::changeArr(str, strsize);
      str[i] = letter;
      std::cin >> letter;
    }
  }
}
