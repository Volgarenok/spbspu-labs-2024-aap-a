#include "readLine.h"
#include <getLine.h>
#include <iostream>
#include <stdexcept>

char* cherkasov::readLine(std::istream& inputStream)
{
  size_t length = 0;
  return cherkasov::inputLine(inputStream, length);
}
