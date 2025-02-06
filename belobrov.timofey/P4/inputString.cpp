#include "inputString.hpp"
#include <cstdlib>

char* belobrov::inputString(std::istream& input)
{
  size_t bufferSize = 32;
  char* buffer = static_cast< char* >(malloc(bufferSize * sizeof(char)));

  if (!buffer) {
    return nullptr;
  }

  size_t currentIndex = 0;
  std::noskipws(input);

  char currentChar = ' ';
  while (input >> currentChar && !input.eof()) {
    if (currentIndex == (bufferSize - 1)) {
      buffer[currentIndex] = '\0';
      bufferSize *= 2;

      char* newBuffer = belobrov::resizeBuffer(buffer, bufferSize);
      free(buffer);
      if (!newBuffer) {
        free(buffer);
        std::skipws(input);
        return nullptr;
      }
      buffer = newBuffer;
    }
    buffer[currentIndex++] = currentChar;
  }

  std::skipws(input);
  buffer[currentIndex] = '\0';
  return buffer;
}

char* belobrov::resizeBuffer(const char* oldBuffer, size_t newSize)
{
  char* newBuffer = static_cast< char* >(malloc(newSize * sizeof(char)));
  if (!newBuffer) {
    return nullptr;
  }

  size_t i = 0;
  while (oldBuffer[i] != '\0') {
    newBuffer[i] = oldBuffer[i];
    i++;
  }

  return newBuffer;
}
