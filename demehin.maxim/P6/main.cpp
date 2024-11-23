#include <string.h>

int main()
{
  char* str = nullptr;
  constexpr size_t max_size = 100;
  constexpr char stop = '\n';

  try
  {
    str = demehin::getString(std::cin, stop, str, max_size);
  }
  catch (const std::bad_alloc& e)
  {
    std::cerr << "Out of memory\n";
    delete[] str;
    return 1;
  }
}
