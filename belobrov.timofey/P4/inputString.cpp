#include "inputString.hpp"
#include <cstdlib>

char * belobrov::inputString(std::istream& input)
{
  char * buffer = nullptr;
  size_t bufferSize = 32;

  buffer = static_cast<char*>(malloc(bufferSize * sizeof(char)));
  if (!buffer) {
    return nullptr;
  }

  size_t currentIndex = 0;
  std::noskips(input);

  char currentChar;
  while (input >> currentChar && !input.eof()) {
    if (currentIndex == (bufferSize - 1)) {
      buffer[currentIndex] = '\0';
      bufferSize *= 2;

      char * newBuffer = belobrov::resizeBuffer(buffer, bufferSize);
      if (!newBuffer) {
        free(buffer);
        return nullptr;
      }
      buffer = newBuffer;
    }
    buffer[currentIndex++] = currentChar;
  }

  std::skipws(input);
  buffer[currentIndex] = '\0';
  return buffer
}

char * belobrov::resizeBuffer(char * oldBuffer, size_t newSize)
{
  char * newBuffer = static_cast<char*>(realloc(oldBuffer, newSize * sizeof(char)));
  if (!newBuffer) {
    return nullptr;
  }
  return newBuffer;
}
