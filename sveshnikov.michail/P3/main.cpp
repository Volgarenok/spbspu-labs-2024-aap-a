#include "cnt_nzr_dig.hpp"

int main(int argc, char **argv)
{
  if (argc < 4)
  {
    std::cerr << "ERROR: Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "ERROR: Too many arguments\n";
    return 1;
  }
  for (size_t i = 0; argv[1][i] != '\0'; i++)
  {
    if (argv[1][i] < '0' || argv[1][i] > '9')
    {
      std::cerr << "ERROR: First parameter  is not a numberout\n";
      return 1;
    }
  }
  if (argv[1][1] != '\0' || !(argv[1][0] == '1' || argv[1][0] == '2'))
  {
    std::cerr << "ERROR: First parameter is out of range\n";
    return 1;
  }
  std::ifstream input(argv[2]);
  int num_rows = 0, num_columns = 0; 
  input >> num_rows, num_columns;
  if (argv[1][0] == '1' && argv[1][0] == '\0')
  {
    const size_t LEN = num_columns*num_rows;
    int matrix1[LEN] = {};
    sveshnikov::read_matrix(std::cin, matrix1, num_columns, num_rows);
    sveshnikov::read_matrix(input, matrix1, LEN);
  }
  else if (argv[1][0] == '2' && argv[1][0] == '\0')
  {
    size_t len = num_columns*num_rows;
    int *matrix2 = new int[len];
    sveshnikov::read_matrix(std::cin, matrix2, num_columns, num_rows);
    sveshnikov::read_matrix(input, matrix2, num_columns, num_rows);
  }
  else
  {
    std::cerr << "ERROR: First parameter is  is out of range\n";
    return 1;
  }
  std::ofstream output(argv[3]);
  sveshnikov::write_matrix(std::cout);
  sveshnikov::write_matrix(output);
}
