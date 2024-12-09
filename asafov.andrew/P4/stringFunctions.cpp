#include "stringFunctions.hpp"

bool asafov::isLetter(char ch)
{
  if((ch > 64 && ch < 91) || (ch > 96 && ch < 123))
  {
    return true;
  }
  return false;
}

int asafov::countUniqLetters(const char* string, size_t length)
{
  char* newstring = new char[length];
  int count = 0;
  for (size_t i = 0; i < length; i++)
  {
    if(isLetter(string[i]))
    {
      int a = 0;
      for(size_t j =0; j < length; j++)
      {
        if (string[i] == newstring[j] || (string[i] - 32) == newstring[j])
        {
          a++;
        }
      }
      if (a==0)
      {
        newstring[count] = string[i];
        count++;
      }
    }
  }
  delete[] newstring;
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
        if(string[i] == alphabet[j] || string[i-32] == alphabet[j])
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
