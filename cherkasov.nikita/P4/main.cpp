#include <iostream>
#include <getLine.h>
#include "newLetter.h"

int main()
{
  char* input = cherkasov::inputLine(std::cin);
  if (!input)
  {
    std::cerr << "Error: Failed to read input or allocation failure.\n";
    return 1;
  }
  size_t length = 0;
  constexpr size_t maxLength = 1000;
  bool isValid = true;
  while (input[length] != '\0')
  {
    if (!std::isprint(input[length]))
    {
      isValid = false;
      break;
    }
      ++length;
  }
  if (!isValid || length > maxLength)
  {
    delete[] input;
    std::cerr << "Error: Invalid or too long input.\n";
    return 1;
  }
  constexpr char oldChar = 'c';
  constexpr char newChar = 'b';
  char* result = new char[length + 1];
  if (!result)
  {
    delete[] input;
    std::cerr << "Error: Memory allocation failed.\n";
    return 1;
  }
  cherkasov::newLetter(input, result, oldChar, newChar);
  std::cout << result << "\n";
  delete[] input;
  delete[] result;
  return 0;
}
