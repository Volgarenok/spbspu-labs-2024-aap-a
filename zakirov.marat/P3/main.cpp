#include <fstream>
#include "detect_exceptions.hpp"
#include "mtx_work.hpp"

int main(int argc, char ** argv)
{
  if (!zakirov::check_arg(argc, argv))
  {
    return 1;
  }

  std::ifstream file_input(argv[2]);
  std::ofstream file_output(argv[3]);
  size_t columns = 0;
  size_t rows = 0;
  file_input >> columns >> rows;
  if (columns == 0 || rows == 0)
  {
    return 0;
  }

  if (argv[1][0] == '1')
  {
    const int size = 10000;
    int mtx[size] = {0};
    if (!zakirov::input_mtx(file_input, mtx, columns, rows))
    {
      std::cerr << "The input is incorrect" << "\n";
      return 2;
    }
    zakirov::transform_mtx(mtx, columns, rows);
    zakirov::output_mtx(file_output, mtx, columns, rows);
  }
  else
  {
    int * mtx = nullptr;
    try
    {
      mtx = new int[columns * rows];
    }
    catch (const std::bad_alloc &e)
    {
      std::cout << "Not enough memory" << "\n";
      delete[] mtx;
      return 1;
    }
    if (!zakirov::input_mtx(file_input, mtx, columns, rows))
    {
      std::cerr << "The input is incorrect" << "\n";
      delete[] mtx;
      return 2;
    }
    zakirov::transform_mtx(mtx, columns, rows);
    zakirov::output_mtx(file_output, mtx, columns, rows);
    delete[] mtx;
  }
}
