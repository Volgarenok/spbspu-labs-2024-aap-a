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
    std::cerr << "Failed to read input or memory allocation error.\n";
    return 1;
  }
  if (!cherkasov::isValidInput(input))
  {
    std::cerr << "Invalid input provided.\n";
    delete[] input;
    return 0;
  }
  const char oldChar = 'c';
  const char newChar = 'b';
  char* result = nullptr;
  result = new char[std::strlen(input) + 1];
  if (!result)
  {
    std::cerr << "Memory allocation error for result buffer.\n";
    delete[] input;
    return 1;
  }
  cherkasov::newLetter(result, input, oldChar, newChar);
  std::cout << result << "\n";
  delete[] input;
  delete[] result;
  return 0;
}
