#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
  int k = argc;
  std::cout << argv[1] << "\n";
  std::ifstream input(argv[1]);
  int a = 0;
  input >> a;
  std::cout << a << "\n";
  std::cout << k << "\n";
}


