#include "getWord.h"

std::string aleksandrov::getWord(const std::string str, size_t numberOfWord)
{
  size_t strSize = str.size();
  size_t wordStart = 0;
  size_t wordIndex = 0;
  for (size_t i = 0; i <= strSize; ++i)
  {
    if (str[i] == ' ' || i == strSize)
    {
      if (wordStart < i)
      {
        if (wordIndex == numberOfWord - 1)
        {
          return str.substr(wordStart, i - wordStart);
        }
        ++wordIndex;
      }
      wordStart = i + 1;
    }
  }
  return "";
}
