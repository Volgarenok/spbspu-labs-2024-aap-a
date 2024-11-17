#include <cstddef>
#include <iostream>
#include <ios>
#include "changeArr.hpp"
#include "checkChar.hpp"

int main()
{
  size_t arrsize = 1;
  char letter = 0;
  char* arr = static_cast < char* >(malloc(sizeof(char) * arrsize));
  if (arr == nullptr) {
    std::cerr << "ERROR WITH MEMORY!!\n";
    return 1;
  }
  arr[arrsize - 1] = '\0';
  std::noskipws(std::cin);
  std::cin >> letter;
  if (!std::cin) {
    free(arr);
    return 1;
  }
  for (size_t i = 0; letter!= '\n'; i+=1) {
    arrsize += 1;
    arr = dribas::changeArr(arr, arrsize);
    if (arr == nullptr) {
      free(arr);
      return 1;
    }
    arr[i] = letter;
    std::cin >> letter;
    if (!std::cin) {
      free(arr);
      return 1;
    }
  }

  std::cout << dribas::checkChar(arr);
  std::cout << '\n';
  free(arr);
  return 0;
}

