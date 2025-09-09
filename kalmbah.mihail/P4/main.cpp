#include <iostream>
#include <cstdlib>
#include "line_processing.hpp"

namespace kalmbah
{
  char* readInputLine()
  {
    const size_t chunkSize = 128;
    size_t capacity = chunkSize;
    char* buffer = new char[capacity];
    size_t length = 0;

    while (std::cin.get(buffer[length]))
    {
      if (buffer[length] == '\n') break;
      if (++length == capacity)
      {
        capacity += chunkSize;
        char* newBuffer = new char[capacity];
        std::copy(buffer, buffer + length, newBuffer);
        delete[] buffer;
        buffer = newBuffer;
      }
    }
    buffer[length] = '\0';
    return buffer;
  }
}

int main()
{
  char* input = kalmbah::readInputLine();
  if (!input || input[0] == '\0')
  {
    std::cerr << "ERROR: Empty input\n";
    delete[] input;
    return 1;
  }

  char* result = kalmbah::rearrangeWordCharacters(input);
  delete[] input;

  if (!result)
  {
    std::cerr << "ERROR: No valid words\n";
    return 1;
  }

  std::cout << result << '\n';

  delete[] result;
  return 0;
}
