#include "parse_arguments.hpp"
#include <stdexcept>

void kizhin::checkArgumentsCount(int argc)
{
  constexpr int expected = 4;
  if (argc < expected) {
    throw std::logic_error("Too few arguments");
  }
  if (argc > expected) {
    throw std::logic_error("Too many arguments");
  }
}

kizhin::MemoryMode kizhin::parseMemoryMode(const char* firstArgument)
{
  if (firstArgument == nullptr || firstArgument[0] == '\0' || firstArgument[1] != '\0') {
    throw std::logic_error("Memory mode must be a single character");
  }
  if (firstArgument[0] == '1') {
    return MemoryMode::stack;
  }
  if (firstArgument[0] == '2') {
    return MemoryMode::freeStore;
  }
  throw std::logic_error("Memory mode must be '1' or '2'");
}
