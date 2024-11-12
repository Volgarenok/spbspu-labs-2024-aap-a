#include <cstddef>
#include <iostream>
#include <ios>
#include "changeArr.hpp"
#include "checkChar.hpp"

int main()
{
  size_t arrsize = 10;
  char* arr = static_cast < char* >(malloc(sizeof(char) * arrsize));
  if (arr == nullptr) {
    std::cerr << "ERROR WITH MEMORY!!\n";
    return 1;
  }
  arr[arrsize - 1] = '\0';
  std::noskipws(std::cin);
  size_t i = 0;
  for (; arr[i-1] != '\n'; i += 1) {
    if (i == arrsize) {
      arrsize += 10;
      arr = dribas::changeArr(arr, arrsize);
      if (arr == nullptr) {
        std::cerr << "Error with memory!!\n";
        return 1;
      }
    }
    std::cin >> arr[i];
    if (!std::cin) {
      std::cerr << "ERROR WITH ENTER!!!\n";
      free(arr);
      return 1;
    }
  }
  std::cout << dribas::checkChar(arr);
  std::cout << '\n';
  free(arr);
  return 0;
}
