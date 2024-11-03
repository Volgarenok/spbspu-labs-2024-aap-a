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
  if (argv[1] == "1" || argv[1] == "+1")
  {
    const int size = 10000;
    int mtx[size] = {0};
    std::istream & input = zakirov::input_mtx(file_input, mtx, columns, rows);
    if (!input)
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
      return 1;
    }
    std::istream & input = zakirov::input_mtx(file_input, mtx, columns, rows);
    if (!input)
    {
      std::cerr << "The input is incorrect" << "\n";
      return 2;
      delete[] mtx;
    }
    zakirov::transform_mtx(mtx, columns, rows);
    zakirov::output_mtx(file_output, mtx, columns, rows);
    delete[] mtx;
  }
}
