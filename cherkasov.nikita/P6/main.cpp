#include <iostream>
#include <stdexcept>
#include <getLine.h>
#include "readLine.h"
#include "validNumber.h"

int main()
{
  char* inputString = nullptr;
  try
  {
    inputString = cherkasov::readLine(std::cin);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Memory allocation error: " << e.what() << '\n';
    return 1;
  }

  if (!inputString || inputString[0] == '\0')
  {
    delete[] inputString;
    std::cerr << "Error: Input is empty\n";
    return 1;
  }

  std::cout << std::boolalpha << cherkasov::validateRealNumber(inputString) << '\n';
  delete[] inputString;
  return 0;
}
