#include "stringFunctions.hpp"

bool asafov::isLetter(char ch)
{
  if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
  {
    return true;
  }
  return false;
}

int asafov::countUniqLetters(const char* string, size_t length)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  size_t count = 0;
  for(size_t i = 0; i < length; i++)
  {
    if(isLetter(alphabet[i]))
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
  char* unusedLetters = new char[count+1];
  count = 0;
  for(size_t i = 0; i < 26; i++)
  {
    if(alphabet[i]!=0)
    {
      unusedLetters[count]=alphabet[i];
      count++;
    }
  }
  delete[] unusedLetters;
  return count;
}

char* asafov::getUnusedLetters(const char* string, size_t length)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  size_t count = 0;
  for(size_t i = 0; i < length; i++)
  {
    if(isLetter(alphabet[i]))
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
  char* unusedLetters = new char[count+1];
  count = 0;
  for(size_t i = 0; i < 26; i++)
  {
    if(alphabet[i]!=0)
    {
      unusedLetters[count]=alphabet[i];
      count++;
    }
  }
  unusedLetters[count] = 0;
  return unusedLetters;
}
