#include <ios>
#include <iostream>
#include <stdexcept>
#include "identicalChar.h"
#include "resizeArray.h"
int main()
{
  size_t length = 3;
  char* arr = static_cast<char*>(malloc(length * sizeof(char)));
  if (arr == nullptr)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }
  size_t count = 0;
  std::noskipws(std::cin);
  if (!(std::cin >> arr[count]))
  {
    std::cerr << "Incorrect input\n";
    free(arr);
    return 1;
  }
  while (arr[count] != '\n')
  {
    count++;
    if (count == length)
    {
      size_t timeLength = length;
      length += 5;
      try
      {
        arr = kiselev::resizeArr(arr, length, timeLength);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << "Out of memory\n";
        free(arr);
        return 1;
      }
    }
    if (!(std::cin >> arr[count]))
    {
      std::cerr << "Incorrect input\n";
      free(arr);
      return 1;
    }
  }
  arr[count] = '\0';
  std::skipws(std::cin);
  const size_t secondLength = 3;
  const char secondArr[secondLength] = { 'a', 'b', 's' };
  int countIdentical = kiselev::identicalChar(arr, secondArr, length, secondLength);
  std::cout << "Identical character: " << countIdentical << "\n";
  return 0;
}
