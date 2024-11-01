#include <iostream>
#include <fstream>
#include <cstdlib>

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  int mainNumber = 0;
  char* endptr = nullptr;
  long taskNumber = std::strtol(argv[1], &endptr, 10);
  if (endptr != "\0")
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if(!(taskNumber == 1 || taskNumber == 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
}
