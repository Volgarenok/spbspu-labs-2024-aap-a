#include <ios>
#include <iostream>
#include <stdexcept>
#include "identicalChar.h"
#include "resizeArray.h"
int main()
{
  size_t length = 3;
  char* arr = static_cast<char*>(malloc(length * sizeof(char)));
  size_t count = 0;
  std::noskipws(std::cin);
  while (arr[count] != '\n')
  {
    if (count >= length - 1)
    {
      size_t timeLenght = length;
      length += 5;
      try
      {
        arr = kiselev::resizeArr(arr, length, timeLenght);
      }
      catch (const std::logic_error& e)
      {
        std::cerr << "Out of memory\n";
        free(arr);
        return 1;
      }
    }
    if (!(std::cin >> arr))
    {
      std::cerr << "Incorrect input\n";
      return 1;
    }
    count++;
  }
  std::skipws(std::cin);
  const size_t secondLength = 3;
  const char secondArr[secondLength] = { 'a', 'b', 's' };
  if (kiselev::identicalChar(arr, secondArr, length, secondLength) == 1)
  {
    std::cout << "There are identical characters\n";
    return 1;
  }
  else
  {
    std::cout << "There are no identical characters\n";
    return 0;
  }
}
