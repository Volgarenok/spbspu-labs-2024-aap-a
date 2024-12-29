#include "stringFunctions.hpp"

int asafov::countUniqLetters(const char* string)
{
  char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
  size_t count = 0;
  for(size_t i = 0; string[i]!='\0'; i++)
  {
    if(isLetter(string[i]))
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
    if((string[i]>'A' && string[i]<'Z') || (string[i]>'a' && string[i]<'z'))
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
  while(count!=0)
  {
    count=0;
    for(size_t i = 0;i<26;i++){
      if (string[i]==0 && i!=26){
        alphabet[i] = string[i+1];
        alphabet[i+1] = 0;
        count++;
      }
    }
  }
  return alphabet;
}
