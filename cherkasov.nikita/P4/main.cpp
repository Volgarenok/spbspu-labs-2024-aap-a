#include <iostream>
#include <cstring>
#include <getLine.h>
#include "newLetter.h"
#include "validInput.h"

int main()
{
  char* input = cherkasov::inputLine(std::cin);
  if (!input)
  {
    std::cerr << "Memory allocation failure!\n";
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
    std::cerr << "error in memory allocation.\n";
    delete[] input;
    return 1;
  }
    std::cout << result << "\n";
    delete[] input;
    delete[] result;
    return 0;
}
