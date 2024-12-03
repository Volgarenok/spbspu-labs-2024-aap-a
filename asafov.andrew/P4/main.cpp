#include <iostream>
#include "stringFunctions.hpp"
#include "inputString.hpp"

int main(){
  
  size_t lenght = 0;
  char* str = asafov::inputString(lenght);
  if(lenght == 0)
  {
    delete[] str;
    return 1;
  }
  int count = asafov::countUniqLetters(str, lenght);
  std::cout<<count<<'\n';
  char* unusedLetters = asafov::getUnusedLetters(str, lenght);
  for(size_t i = 0; unusedLetters[i] != 0; i++)
  {
    std::cout<<unusedLetters[i];
  }
  std::cout<<'\n';
  delete[] unusedLetters;
  delete[] str;

  return 0;
}
