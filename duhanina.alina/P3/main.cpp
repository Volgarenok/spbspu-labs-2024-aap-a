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
  if (argc != 4)
  {
    std::cerr << "Incorrect amount of data entered";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoi(argv[1]);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Invalid num";
    return 1;
  }
  if (num != 1 || num != 2)
  {
    std::cerr << "Invalid value num";
    return 1;
  }
  size_t m = 0, n = 0;
  input >> m >> n;
  if (!(input >> m >> n) || m == 0 || n == 0)
  {
    std::cerr << "Invalid table size data";
    return 2;
  }
  size_t read = 0;
}
