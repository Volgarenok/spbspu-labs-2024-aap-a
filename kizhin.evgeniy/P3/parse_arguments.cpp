#include "parse_arguments.hpp"
#include <cstring>

void kizhin::parseArguments(std::ostream& errorStream, int argc,
    char* const* argv, int* programMode, char** inputFile, char** outputFile)
{
  if (argc < 4) {
    errorStream << "Not enough arguments\n";
    exit(1);
  } else if (argc > 4) {
    errorStream << "Too many arguments\n";
    exit(1);
  }
  try {
    *programMode = parseProgrammMode(argv[1]);
  } catch (const std::invalid_argument&) {
    errorStream << "First parameter is not a number\n";
    exit(1);
  } catch (const std::out_of_range&) {
    errorStream << "First parameter is out of range\n";
    exit(1);
  }
  *inputFile = argv[2];
  *outputFile = argv[3];
}

int kizhin::parseProgrammMode(const char* string)
{
  if (string == nullptr) {
    throw std::invalid_argument("Nullptr given instead of string");
  }
  size_t length = strlen(string);
  for (size_t i = 0; i < length; ++i) {
    if (!std::isdigit(string[i])) {
      throw std::invalid_argument("Invalid character in input string");
    }
  }
  if (length != 1 || (string[0] != '1' && string[0] != '2')) {
    throw std::out_of_range("Program mode must be 1 or 2");
  } else if (string[0] == '1') {
    return 1;
  } else {
    return 2;
  }
}
