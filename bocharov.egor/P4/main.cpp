#include <iostream>
#include <getline.h>
#include "processing.h"
int main()
{
  constexpr char secondstring[25] = "ahgm032uOqZni,dR(#@ )!.e";
  char * firststring = nullptr;
  char symbol = '\0';
  try
  {
    firststring = bocharov::getline(std::cin, symbol);
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
  bocharov::merge_lines(firststring, secondstring, result);
  std::cout << result << "\n";
  std::cout << bocharov::symbols_comparison(firststring, secondstring);
  std::cout << "\n";
  delete[] firststring;
}
