#include <iostream>
#include "processing_matrix.h"
#include <fstream>
#include <cstdlib>
#include <cstring>

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Invalid number of arguments." << "\n";
    return 1;
  }
  char * endptr;
  long num = strtol(argv[1], &endptr, 10);
  if (*endptr != '\0' || num < 1 || num > 2)
  {
    std::cerr << "Error: First parameter is not a valid number or out of range." << "\n";
    return 1;
  }
  std::string inputFile = argv[2];
  std::string outputFile = argv[3];
  if (num == 1) {
  cherkasov::processFixedSizeArray(inputFile, outputFile);
  }
  else if (num == 2)
  {
  cherkasov::processDynamicArray(inputFile, outputFile);
  }
  return 0;
}
