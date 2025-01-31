#include <fstream>
#include <cctype>
#include "cnt_row_nsm.h"
#include "matrix.h"

int main(int argc, char** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }

  char* first_arg = argv[1];
  bool isDigit = std::isdigit(first_arg[0]);
  if (!isDigit)
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }

  int c = *first_arg - '0';
  if (first_arg[1] != '\0' || (c > 2))
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  size_t m = 0, n = 0;
  input >> m >> n;
  char error_msg[] = "Impossible to build matrix\n";
  if (!input)
  {
    std::cerr << error_msg;
    return 2;
  }

  size_t k = m * n;
  int* matrix2 = nullptr;
  try
  {
    matrix2 = new int[k];
  }
  catch (const std::bad_alloc & e)
  {
    std::cerr << "Out of memory\n";
    return 1;
  }

  int matrix1[10000] = {};
  int* final_matrix = nullptr;
  size_t read = 0;


  final_matrix = (c == 2) ? matrix2 : matrix1;

  if (!demehin::input_matrix(input, final_matrix, k, read) && m != 0)
  {
    std::cerr << error_msg;
    delete[] matrix2;
    return 2;
  }

  if (read != k)
  {
    std::cerr << error_msg;
    delete[] matrix2;
    return 2;
  }

  if (!std::cin)
  {
    std::cerr << error_msg;
    delete[] matrix2;
    return 2;
  }

  std::ofstream output(argv[3]);
  output << demehin::cnt_row_nsm(final_matrix, m, n);
  delete[] matrix2;
}


