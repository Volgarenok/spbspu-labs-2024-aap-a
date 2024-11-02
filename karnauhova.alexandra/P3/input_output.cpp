#include "input_output.hpp"
#include <fstream>

std::ifstream & karnauhova::input_matrix(std::ifstream & in, int * t, size_t m, size_t n, size_t & read)
{
  for (size_t i = 0; i < (m * n); ++i)
  {
    in >> t[i];
    read++;
  }
  return in;
}
void karnauhova::output_matrix(std::ofstream & out, float * t, size_t m, size_t n)
{
  for (size_t i = 0; (i + 1) < (m * n); ++i)
  {
    out << t[i] << ' ';
  }
  out << t[m * n - 1];
}
