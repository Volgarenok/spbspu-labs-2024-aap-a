#include <iostream>
#include <getLine.h>
#include "replaceChar.h"

int main()
{
  size_t length = 0;
  char* input = cherkasov::inputLine(std::cin, length);
  if (!input)
  {
    std::cerr << "Error: Failed to read input or allocation failure.\n";
    return 1;
  }
  constexpr char oldChar = 'c';
  constexpr char newChar = 'b';
  char* result = nullptr;
  try
  {
    result = new char[length + 1];
  }
  catch (const std::bad_alloc&)
  {
    delete[] input;
    std::cerr << "Error: Memory allocation failed.\n";
    return 1;
  }
  cherkasov::replaceChar(input, result, oldChar, newChar);
  std::cout << result << "\n";
  delete[] input;
  delete[] result;
  return 0;
}
