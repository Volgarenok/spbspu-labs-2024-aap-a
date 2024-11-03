#include "matrix.hpp"

int main(int argc, char ** argv)
{
  std::ifstream input(argv[2]);
  read_matrix(std::cin);
  read_matrix(input);
  std::ofstream output(argv[3]);
  write_matrix(std::cout);
  write_matrix(output);
}
