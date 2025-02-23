#include "stringFunctions.hpp"
#include <cctype>

void findUniqLetters(const char* string, char* alphabet)
{
  for (size_t i = 0; i < 26; i++)
  {
    alphabet[i] = 'a' + i;
  }
  for (size_t i = 0; string[i] != '\0'; i++)
  {
    if (std::tolower(string[i]) == alphabet[std::tolower(string[i]) - 'a'])
    {
      alphabet[std::tolower(string[i]) - 'a'] = 0;
    }
  }
}

int asafov::countUniqLetters(const char* string)
{
  char alphabet[26];
  findUniqLetters(string, alphabet);
  size_t count = 0;
  for (size_t i = 0; i < 26; i++)
  {
    if (alphabet[i] == 0)
    {
      count++;
    }
  }
  return count;
}

void asafov::getUnusedLetters(const char* string, char* unusedletters)
{
  char alphabet[26];
  findUniqLetters(string, alphabet);
  size_t lastletter = 0;
  for (size_t pos = 0; pos < 26; pos++)
  {
    if (alphabet[pos] != '\0')
    {
      unusedletters[lastletter++] = alphabet[pos];
    }
  }
}
