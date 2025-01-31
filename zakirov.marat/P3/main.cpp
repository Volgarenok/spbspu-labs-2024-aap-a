#include <fstream>
#include "mtx_work.hpp"

bool check_arg(int m_argc, char const * const * m_argv)
{
  if (m_argc < 4)
  {
    std::cerr << "Not enought arguments" << "\n";
    return true;
  }
  else if (m_argc > 4)
  {
    std::cerr << "Too many arguments" << "\n";
    return true;
  }
  else if ((m_argv[1][0] != '1' && m_argv[1][0] != '2') || m_argv[1][1] != '\0')
  {
    std::cerr << "First argument isn't 1 or 2";
    return true;
  }

  return false;
}

int main(int argc, char ** argv)
{
  if (check_arg(argc, argv))
  {
    return 1;
  }

  size_t columns = 0;
  size_t rows = 0;
  std::ifstream file_input(argv[2]);
  std::ofstream file_output(argv[3]);
  file_input >> columns >> rows;
  if (file_input.eof())
  {
    std::cerr << "Empty file" << "\n";
  }
  else if (!file_input)
  {
    std::cerr << "The input is incorrect" << "\n";
    return 2;
  }
  else if (columns == 0 || rows == 0)
  {
    file_output << "0" << " " << "0" << "\n";
    return 0;
  }

  int s_mtx[10000] = {0};
  int * d_mtx = nullptr;
  if (argv[1][0] == '2')
  {
    try
    {
      d_mtx = new int[columns * rows];
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << "Not enough memory" << "\n";
      delete[] d_mtx;
      return 1;
    }
  }

  int * u_mtx = (argv[1][0] == '1') ? s_mtx : d_mtx;
  if (!zakirov::input_mtx(file_input, u_mtx, columns, rows))
  {
    std::cerr << "The input is incorrect" << "\n";
    delete[] d_mtx;
    return 2;
  }

  zakirov::mtx_spiral_decrease(u_mtx, columns, rows);
  zakirov::output_mtx(file_output, u_mtx, columns, rows);
  delete[] d_mtx;
}
