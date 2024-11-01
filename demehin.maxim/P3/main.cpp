#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
  int l = argc;

  std::ifstream input(argv[1]);
  int m = 0, n = 0, k = 0;
  input >> m >> n;
  k = m * n;
  std::cout << l << "\n";
}


