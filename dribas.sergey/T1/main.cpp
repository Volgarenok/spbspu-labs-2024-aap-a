#include <cstddef> 
#include <iostream>
#include "enterStr.hpp"
void clearStr(char** stack, size_t stackSize){
  for (size_t i = 0; *(stack+i) && i <stackSize; i++) {
    free(*(stack + i));
    } 
     }
int main()
{
  //string = enterStr();
  constexpr size_t stackSize = 1000;
  char * stack[stackSize] = {} ;
  for (size_t i = 0; (std::cin) && i < stackSize; i++) {
    *(stack + i) = dribas::enterStr(std::cin);
  }
  for (size_t i = 0; *(stack + i) != nullptr; i++) {
    std::cout << *(stack + i) << '\n';
  }
  if (std::cin.eof()) {
    std::cout << "EOF\n";
  }
  else if (std::cin.fail()) {
    std::cout << "Fail\n";
    clearStr(stack, stackSize);
  }
}



