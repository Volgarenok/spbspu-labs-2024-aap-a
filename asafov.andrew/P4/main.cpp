#include <iostream>
#include "countUniqLetters.h"
#include "pull.h"

int main(){
  
  unsigned long long lenght = 0;

  char* str = asafov::inputString(lenght);
  if(lenght == 0)
  {
    delete[] str;
    return 1;
  }
  int count = asafov::countUniqLetters(str, lenght);
  std::cout<<count<<'\n';

  delete[] str;

  return 0;
}
