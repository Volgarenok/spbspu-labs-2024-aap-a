#include <ios>
#include <iostream>
#include "transferArray.h"
int main()
{
  size_t k = 3;
  char* arr = static_cast<char*>(malloc(k * sizeof(char)));
  size_t count = 0;
  std::noskipws(std::cin);
  for (size_t j = 0; j != '\n'; ++j)
  {
    if (count >= k - 1)
    {
      size_t m = k;
      k += 5;
      char* arr2 = static_cast<char*>(malloc(k * sizeof(char)));
      kiselev::transferArr(arr2, arr, m);
      free(arr);
      char* arr = static_cast<char*>(malloc(k * sizeof(char)));
      kiselev::transferArr(arr, arr2, m);
      free(arr2);
    }
    std::cin >> arr[j];
    if (!std::cin >> arr[j])
    {
      std::cerr << "Incorrect input\n";
      return 1;
    }
    count++;
  }
  std::skipws(std::cin);
}
