#include <iostream>
#include <fstream>
#include "input_matrix.hpp"


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
  
  
  if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First parameter is not suitable" << "\n";
    return 1;
  }
  
  std::ifstream input(argv[2]);
  //...
  std::ofstream output(argv[3]);
}
