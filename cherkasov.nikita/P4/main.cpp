#include <iostream>
#include <cstring>
#include <getLine.h>
#include "newLetter.h"
#include "validInput.h"

int main()
{
  char* input = nullptr;
  try
  {
    input = cherkasov::inputLine(std::cin);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Unhandled exception: " << e.what() << "\n";
     return 1;
  }
  if (!input)
  {
    std::cerr << "Memory allocation failure or empty input!\n";
    return 1;
  }
  if (!cherkasov::isValidInput(input))
  {
    delete[] input;
    return 0;
  }
  const char oldChar = 'c';
  const char newChar = 'b';
  char* result = cherkasov::newLetter(input, oldChar, newChar);
  if (!result)
  {
    std::cerr << "Error in memory allocation.\n";
    delete[] input;
    return 1;
  }
    std::cout << result << "\n";
  delete[] input;
  delete[] result;
  return 0;
}
