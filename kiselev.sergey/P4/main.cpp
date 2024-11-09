#include <ios>
#include <iostream>
#include <stdexcept>
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
}
