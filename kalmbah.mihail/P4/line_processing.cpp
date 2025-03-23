#include "line_processing.hpp"
#include <cctype>
#include <cstring>
#include <algorithm>

namespace kalmbah
{
  namespace
  {
    struct WordBounds
    {
      const char* start;
      const char* end;
    };

    size_t countWords(const char* line, WordBounds* words)
    {
      size_t wordCount = 0;
      const char* ptr = line;
      
      while (*ptr)
      {
        while (*ptr && !std::isalnum(*ptr)) ++ptr;
        if (!*ptr) break;
        
        words[wordCount].start = ptr;
        while (*ptr && (std::isalnum(*ptr)) ++ptr;
        words[wordCount].end = ptr;
        ++wordCount;
      }
      return wordCount;
    }

    size_t findMaxWordLength(const WordBounds* words, size_t wordCount)
    {
      size_t maxLen = 0;
      for (size_t i = 0; i < wordCount; ++i)
      {
        size_t len = words[i].end - words[i].start;
        if (len > maxLen) maxLen = len;
      }
      return maxLen;
    }
  }

  char* rearrangeWordCharacters(const char* line)
  {
    const size_t MAX_WORDS = 100;
    WordBounds words[MAX_WORDS];
    size_t wordCount = countWords(line, words);
    
    if (wordCount == 0) return nullptr;

    size_t maxLength = findMaxWordLength(words, wordCount);
    char* result = new char[wordCount * maxLength + 1];
    size_t index = 0;

    for (size_t col = 0; col < maxLength; ++col)
    {
      for (size_t row = 0; row < wordCount; ++row)
      {
        const char* pos = words[row].start + col;
        if (pos < words[row].end)
        {
          result[index++] = *pos;
        }
      }
    }
    result[index] = '\0';
    return result;
  }
}
