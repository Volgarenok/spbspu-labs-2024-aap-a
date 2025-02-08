#include "stringFunctions.hpp"
#include <cctype>

void findUniqLetters(const char* string, char* alphabet)
{
  for (size_t i = 0; string[i]!='\0'; i++)
  {
    for (size_t j = 0; j < 26; j++)
    {
      if (std::tolower(string[i]) == alphabet[j])
      {
        alphabet[j] = 0;
      }
    }
  }
}

int asafov::countUniqLetters(const char* string)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
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
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  findUniqLetters(string, alphabet);
  size_t lastletter = 0;
  for (size_t pos = 0; pos <= 26; pos++)
  {
    if (alphabet[pos] != '\0' && lastletter != pos)
    {
      alphabet[lastletter] = alphabet[pos];
      alphabet[pos] = '\0';
      lastletter++;
    }
    else if (alphabet[pos] != '\0' && lastletter == pos)
    {
      lastletter++;
    }
  }
  for (size_t i = 0; unusedletters[i] != 0; i++)
  {
    unusedletters[i] = alphabet[i];
  }
}
