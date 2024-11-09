#include "inputArray.h"
#include <iostream>
#include <stdexcept>
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
      kiselev::transferArr(char* arr, char* fromArr, m);
    }
    std::cin >> arr[j];
    if (std::cin >> arr[j])
    {
      return arr;
    }
    count++;
  }
}

