#include <iostream>
#include "countUniqLetters.h"
#include "pull.h"

int main(){
  char* str = nullptr;
  size_t lenght = 0;

  lab::pull(str, lenght);

  int count = lab::countUniqLetters(str, lenght);
  std::cout<<count<<'\n';

  delete[] str;

  return 0;
}
