#include <cstddef>
#include <iostream>
#include <ios>
#include "changeArr.hpp"
#include "checkChar.hpp"

int main()
{
  size_t arrsize = 5;
  char letter = 0;
  char* arr = static_cast < char* >(malloc(sizeof(char) * arrsize));
  if (arr == nullptr) {
    std::cerr << "ERROR WITH MEMORY!!\n";
    return 1;
  }
  arr[arrsize - 1] = '\0';
  std::noskipws(std::cin);
  std::cin >>letter;
  if (letter == '\n') {
    std::cout << '0';
    return 0;
  }
  size_t i = 1;
  for (; letter != '\n'; i += 1) {
    if (i == arrsize) {
      arrsize += 10;
      arr = dribas::changeArr(arr, arrsize);
      if (arr == nullptr) {
        std::cerr << "Error with memory!!\n";
        return 1;
      }
    }
    arr[i] = letter;
    std::cin >> letter;
    if (!std::cin) {
      std::cerr << "ERROR WITH ENTER!!!\n";
      free(arr);
      return 1;
    }
  }
  arr[i+1] = '\0';
  std::cout << dribas::checkChar(arr);
  std::cout << '\n';
  free(arr);
  return 0;
}

