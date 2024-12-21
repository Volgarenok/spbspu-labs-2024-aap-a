#include "stringFunctions.hpp"

int asafov::countUniqLetters(const char* string)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  size_t count = 0;
  for(size_t i = 0; string[i]!='\0'; i++)
  {
    if((string[i] > 'A' && string[i] < 'Z') || (string[i] > 'a' && string[i] < 'z'))
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
    if((string[i] > 'A' && string[i] < 'Z') || (string[i] > 'a' && string[i] < 'z'))
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
  while (alphabet[0] == 0)
  {
    for (size_t i = 0; i < 25; i++)
    {
      alphabet[i] = alphabet[i + 1];
    }
    alphabet[25] = '\0';
  }
  for (size_t i = 1; i < 26; i++)
  {
    if (alphabet[i] == 0)
    {
      for (size_t j = 0; j < 25; j++)
      {
        alphabet[j] = alphabet[j + 1];
      }
      alphabet[25] = '\0';
    }
  }
  for (size_t i = 0; i < 26; i++)
  {
    unusedletters[i] = alphabet[i];
  }
}
