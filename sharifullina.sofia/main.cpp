#include <iostream>

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
  for (int i = 0; i < argc; i++)
  {
    std::cout << argv[i] << "\n"
  }
}
