#include "matrix.hpp"
#include <iostream>
#include <fstream>


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
  int parameter = 0;
  parametr = argv[1];
  if (!(parametr))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  if ((parametr < 1) || (parametr > 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  int long long m = -1, n = -1;
  input >> m >> n;
  if (input.eof())
  {
    std::cerr << "Not enough elements in file\n";
    return 2;
  }
  if ((m < 0) || (n < 0))
  {
    std::cerr << "Non-correct matrix parameters\n";
    return 2;
  }
  input_matrix(input);
  std::ofstream output(argv[3]);
  output << a;
  int ** t = alloc(m, n);
}
