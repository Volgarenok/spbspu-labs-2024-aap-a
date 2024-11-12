#include <cstddef>
#include <iostream>
#include <ios>
#include "changeArr.hpp"

int main()
{
  size_t arrsize = 10;
  char* arr = reinterpret_cast < char* >(malloc(sizeof(char) * arrsize));
  if (arr == nullptr) {
    std::cerr << "ERROR WITH MEMORY!!\n";
    return 1;
  }
  std::noskipws(std::cin);
  size_t i = 0;
  for (; arr[i] != '\n'; i += 1) {
    if (i == arrsize - 2) {
      arrsize += 10;
      arr = dribas::changeArr(arr, arrsize);
      if (arr == nullptr) {
        std::cerr << "ERROR WITH MEMORY!!\n";
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
  return 0;
}
