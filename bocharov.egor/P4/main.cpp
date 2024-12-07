#include <iostream>
#include <getline.h>
#include "processing.h"
int main()
{
  constexpr char secondstring[25] = "ahgm032uOqZni,dR(#@ )!.e";
  char * firststring = nullptr;
  try
  {
    firststring = bocharov::getline(std::cin);
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Error: memory not allocated\n";
    return 1;
  }
  if (firststring[0] == '\0')
  {
    delete[] firststring;
    std::cerr << "Error: input is empty\n";
    return 1;
  }
  char result[27];
  bocharov::connect_the_lines(firststring, secondstring, result);
  std::cout << result << "\n";
  std::cout << bocharov::checking_symbols(firststring, secondstring);
  std::cout << "\n";
  delete[] firststring;
}
