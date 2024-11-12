#include <cctype>
#include "countUniqLetters.h"

int lab::countUniqLetters(const char* string, size_t length)
{
  char* newstring = new char[length];
  int count = 0;
  for (size_t i = 0; i < length; i++)
  {
    if(std::isupper(string[i]) || std::islower(string[i]))
    {
      int a = 0;
      for(size_t j =0; j < length; j++)
      {
        if (string[i] == newstring[j])
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
  return count;
}
