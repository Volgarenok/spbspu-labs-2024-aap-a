#include <cstddef> 
#include <iostream>
#include "enterStr.hpp"
#include "shape.hpp"

void clearStr(char** stack, size_t stackSize){
  for (size_t i = 0; *(stack+i) && i <stackSize; i++) {
    free(*(stack + i));
    } 
     }
int main()
{
  //string = enterStr();
  constexpr size_t stackSize = 1000;
  dribas::Shape * stack[stackSize] = {} ;
  for (size_t i = 0; (std::cin) && i < stackSize; i++) {
    char * str = dribas::enterStr(std::cin);
    
    
  }
  for (size_t i = 0; *(stack + i) != nullptr; i++) {
    std::cout << *(stack + i) << '\n';
  }
  if (std::cin.eof()) {
    std::cout << "EOF\n";
  }
  else if (std::cin.fail()) {
    std::cout << "Fail\n";
    return 1;
  }

}



