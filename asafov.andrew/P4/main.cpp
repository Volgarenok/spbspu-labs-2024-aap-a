#include <iostream>
#include <cstddef>
#include "countUniqLetters.h"
#include "pull.h"

int main(){
  char* str = nullptr;
  size_t lenght = 0;

  lab::pull(str, lenght);
  if(lenght == 0)
  {
    delete[] str;
    return 1;
  }
  int count = lab::countUniqLetters(str, lenght);
  std::cout<<count<<'\n';

  delete[] str;

  return 0;
}
