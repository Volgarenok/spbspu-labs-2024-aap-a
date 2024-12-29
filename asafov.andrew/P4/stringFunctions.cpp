#include "stringFunctions.hpp"
#include <cstdlib>

int asafov::countUniqLetters(const char* string)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  size_t count = 0;
  for(size_t i = 0; string[i]!='\0'; i++)
  {
    if(std::isalpha(string[i]))
    {
      for(int j = 0; j < 26; j++)
      {
        if(string[i] == alphabet[j] || (string[i]-32) == alphabet[j])
        {
          alphabet[j] = 0;
          count++;
        }
      }
    }
  }
  return 26 - count;
}

void asafov::getUnusedLetters(const char* string, char* unusedletters)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  size_t count = 0;
  for(size_t i = 0; string[i]!='\0'; i++)
  {
    if(std::isalpha(string[i]))
    {
      for(int j = 0; j < 26; j++)
      {
        if(string[i] == alphabet[j] || (string[i]-32) == alphabet[j])
        {
          alphabet[j] = 0;
          count++;
        }
      }
    }
  }
  for (size_t i = 0; i <=26; i++)
  {
    if (alphabet[i] == '\0')
    {
      for (size_t j = 26; j > i; j--)
      {
        if (alphabet[j] != '\0' && alphabet[j - 1] == '\0')
        {
          alphabet[j - 1] = alphabet[j];
          alphabet[j] = '\0';
        }
      }
    }
  }
}
