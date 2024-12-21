#include "ErrorHandler.h"
#include <string>
#include <iostream>
void cherkasov::handleError(const std::string& error)
{
  std::cerr << error << "\n";
}

