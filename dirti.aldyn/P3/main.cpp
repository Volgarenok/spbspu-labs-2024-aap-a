#include <iostream>
#include <fstream>


int main(int argc, char ** argv)
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
  
  if (argc < 4)
  {
    std::cerr << "Not enough arguments" << "\n";
    return 1;
  }
  
  if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  
  std::cout << argv[1] << "\n";
  
  std::ifstream input(argv[2]);
  //...
  std::ofstream output(argv[3]);
}
