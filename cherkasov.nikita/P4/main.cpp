#include <iostream>
#include <cstring>
#include "getLine.h"
#include "newLetter.h"
#include "validInput.h"

int main()
{
  char* input = nullptr;
  try
  {
    input = cherkasov::inputLine(std::cin);
    if (!input)
    {
      std::cerr << "Empty input or memory allocation failure!\n";
      return 1;
    }
    if (!cherkasov::isValidInput(input))
    {
      delete[] input;
      std::cerr << "Invalid input!\n";
      return 1;
    }
  const char oldChar = 'c';
  const char newChar = 'b';
  char* result = nullptr;
  result = cherkasov::newLetter(input, oldChar, newChar);
  if (!result)
  {
    delete[] input;
    std::cerr << "Error while creating a new string!\n";
    return 1;
  }
    std::cout << result << "\n";
    delete[] input;
    delete[] result;
    return 0;
    }
    catch (const std::exception& e)
    {
      std::cerr << "Unhandled exception: " << e.what() << "\n";
      delete[] input;
      return 1;
    }
}
