#include "parse_arguments.hpp"
#include <stdexcept>

void kizhin::checkArgumentsCount(int argc)
{
  if (argc < 4) {
    throw std::logic_error("Too few arguments: expected 4");
  }
  if (argc > 4) {
    throw std::logic_error("Too many arguments: expected 4");
  }
}

kizhin::MemoryMode kizhin::parseProgrammMode(const char* string)
{
  if (string == nullptr || string[0] == '\0' || string[1] != '\0') {
    throw std::logic_error("Program mode must be a single character");
  }
  if (string[0] == '1') {
    return MemoryMode::stack;
  }
  if (string[0] == '2') {
    return MemoryMode::freeStore;
  }
  throw std::logic_error("Promgram mode must be '1' or '2'");
}
