#include <iostream>
#include <fstream>


std::istream & input_matrix(std::istream & in, int * t, size_t m, size_t n, size_t & read)
{
  size_t size_table = n * m;
  for (size_t i = 0; i < size_table; ++i)
  {
    in >> t[i];
    ++read;
    if (!(in >> t[i]))
    {
      std::cerr << "Invalid input data";
      return 2;
    }
  }
  return in;
}



int main(int argc, char ** argv)
{
  for (size_t i = 0; i < argc; ++i)
  {
    
  }
  size_t m = 0, n = 0;
  input >> m >> n;
  size_t read = 0;
}
