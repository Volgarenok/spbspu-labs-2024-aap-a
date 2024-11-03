#include "matrix.hpp"
#include <iostream>
#include <fstream>


int main(int argc, char ** argv) 
{
  int long long m = -1, n = -1;
  int parameter = 0;
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
  std::ofstream output(argv[3]);
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
  if (parametr == 1)
  {
    int * t[m*n]={};
  }
  else
  {
    try
    {
      int * t = malloc(m, n);
    }
    catch(const std::bad_alloc& e)
    {
      std::cerr << "Not enough memory\n";
      return 2;
    }
  }
  int member = input_matrix(input, t, m, n);
  if (!(member == m * n))
  {
    std::cerr << "Error matrix input\n";
    return 2;
  }
  output << osedfun(t, m, n);
  return 0;
}
