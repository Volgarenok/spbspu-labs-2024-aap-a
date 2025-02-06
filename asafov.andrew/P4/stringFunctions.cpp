#include "stringFunctions.hpp"
#include <cctype>

int findUniqLetters(const char* string, char* alphabet)
{
  size_t count = 0;
  for(size_t i = 0; string[i]!='\0'; i++)
  {
    for(int j = 0; j < 26; j++)
    {
      if(string[(i>96) ? (i) : (i - 32)] == alphabet[j])
      {
        alphabet[j] = 0;
        count++;
      }
    }
  }
  return count;
}

int asafov::countUniqLetters(const char* string)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  size_t count = findUniqLetters(string, alphabet);
  return count;
}

void asafov::getUnusedLetters(const char* string, char* unusedletters)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  size_t count = 26 - findUniqLetters(string, alphabet);
  size_t lastletter = 0;
  for (size_t pos = 0; pos <=26; pos++)
  {
    if (alphabet[pos] != '\0' && lastletter != pos)
    {
      alphabet[lastletter] = alphabet[pos];
      alphabet[pos] = 0;
      lastletter++;
    }
    else if (alphabet[pos] != '\0')
    {
      lastletter++;
    }
  }
  for (size_t i = 0; i < count; i++)
  {
    unusedletters[i] = alphabet[i];
  }
  unusedletters[count] = '\0';
}
