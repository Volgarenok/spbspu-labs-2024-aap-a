#include <cstddef> 
#include <iostream>
#include "enterStr.hpp"
int main()
{
  //string = enterStr();
	constexpr size_t stackSize = 1000;
	char * stack[stackSize] = {} ;
	bool running = true;
	for (size_t i = 0; char* str = dribas::enterStr(std::cin); i++) {
		*(stack + i) = str;
	}
	std::cout << stack[0] << stack[1];
}
