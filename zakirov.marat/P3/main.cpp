#include <fstream>
#include "mtx_work.hpp"

int main(int argc, char ** argv)
{
  if (argc < 4)
  {
    std::cerr << "Not enought arguments" << "\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return 1;
  }
  else if ((argv[1][0] != '1' && argv[1][0] != '2') || argv[1][1] != '\0')
  {
    std::cerr << "First argument isn't 1 or 2";
    return 1;
  }

  std::ifstream file_input(argv[2]);
  std::ofstream file_output(argv[3]);
  if (file_input.eof())
  {
    std::cerr << "Empty file" << "\n";
  }

  size_t columns = 0;
  size_t rows = 0;
  file_input >> columns >> rows;
  if (!file_input)
  {
    std::cerr << "The input is incorrect" << "\n";
    return 2;
  }
  else if (columns == 0 || rows == 0)
  {
    file_output << "0" << " " << "0" << "\n";
    return 0;
  }

  int c_mtx[10000] = {0};
  int * d_mtx = nullptr;
  if (argv[1][0] == '2')
  {
    try
    {
      d_mtx = new int[columns * rows];
    }
    catch (const std::bad_alloc &e)
    {
      std::cout << "Not enough memory" << "\n";
      delete[] d_mtx;
      return 1;
    }
  }

  int * r_mtx = argv[1][0] == '1' ? c_mtx : d_mtx;

  if (!zakirov::input_mtx(file_input, r_mtx, columns, rows))
  {
    std::cerr << "The input is incorrect" << "\n";
    delete d_mtx;
    return 2;
  }

  zakirov::mtx_spiral_decrease(r_mtx, columns, rows);
  for (size_t i = 0; i < rows * columns; ++i)
  {
    std::cout << r_mtx[i] << ' ';
  }
  std::cout << '\n';

  delete d_mtx;
}
