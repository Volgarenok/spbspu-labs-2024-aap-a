#include <iostream>
#include <getLine.h>
#include "replaceChar.h"

int main()
{
  char* input = cherkasov::inputLine(std::cin);
  if (!input)
  {
    std::cerr << "Error: Failed to read input or allocation failure.\n";
    return 1;
  }
  constexpr char oldChar = 'c';
  constexpr char newChar = 'b';
  size_t length = 0;
  while (input[length] != '\0')
  {
    ++length;
  }
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
