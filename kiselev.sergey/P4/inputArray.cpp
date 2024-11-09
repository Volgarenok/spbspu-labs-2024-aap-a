#include "inputArray.h"
#include <iostream>
#include "transferArray.h"
char* kiselev::inputArr(char* arr, size_t k)
{
  size_t count = 0;
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
      return arr;
    }
    count++;
    return arr;
  }
}

