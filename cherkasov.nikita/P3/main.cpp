#include <iosteram>
#include <fctream>

void input_matrix(std::istream & in, int ** t, size_t m, size_t n, size_t & read);
{
// надо посчитать сколько считаллось элементов
  for (size_t i = 0; i < m; ++i)
  {
    for (size_t j = 0; j < n; ++j)
    {
      in >> t[i][j];
    }
  }
  return in;
}

int ** alloc(size_t m, size_t n);

int main (int argc, char ** argv)
{
  for (int i = 0; i < argc; ++i)
  {
    std::cout << argv[i] << "\n";
  }
  size_t m = 2, n = 3;
  int ** t = alloc(m, n);
  
  if (input_matrix(std::cin, t, m, n, read))
}
