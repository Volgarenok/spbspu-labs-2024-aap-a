#include <iostream>
#include "strconversion.h"

int main()
{
  if(!std::cin)
  {
    std::cerr << "No input";
    return 1;
  }
  char* istr = nullptr;
  try
  {
    istr = lanovenko::inputstring(std::cin, '\n');
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "No memory" << '\n';
    return 1;
  }
  if(istr[0] == '\0')
  {
    delete[] istr;
    std::cerr << "Empty string" << '\n';
    return 1;
  }
  std::cout << lanovenko::transformationstr(istr) << '\n';
  delete[] istr;
}
