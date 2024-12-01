#include <iostream>
#include <cstring>
#include <getLine.h>
#include "newLetter.h"

int main() {
  char* input = cherkasov::inputLine(std::cin);
  if (!input)
  {
    std::cerr << "Memory allocation failure!\n";
    return 1;
  }
  if (input[0] == '\0')
  {
    std::cerr << "The line is empty!\n";
    delete[] input;
    return 1;
  }
  const char oldstring = 'c';
  const char newstring = 'b';
  char* result = cherkasov::newLetter(input, oldstring, newstring);
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
