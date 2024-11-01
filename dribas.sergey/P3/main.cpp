#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char ** argv)
{
  if (argc < 4) {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4) {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  char *endptr = nullptr;
  int firstArg = std::strtol(argv[1], &endptr, 10);
  if (*endptr != '\0') {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if (firstArg > 2 || firstArg < 1) {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
 std::cout << "all is good!\n";
}
