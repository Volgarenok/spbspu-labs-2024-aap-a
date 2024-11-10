#include <iostream>
#include <stdexcept>
#include <cstddef>
#include "functions.h"

int main()
{
  size_t dl = 10;
  char* str = finaev::creature_str(dl);
  if (str == nullptr)
  {
    free(str);
    std::cerr << "Error create!\n";
    return 1;
  }
  char c = '\0';
  size_t tk_dl = 0;
  std::noskipws(std::cin);

  while ((std::cin >> c) && (c != '\n'))
  {
    if (tk_dl == dl)
    {
      char* new_str = finaev::creature_str(dl * 2);
      if (new_str == nullptr)
      {
        free(new_str);
        free(str);
        std::cerr << "Error increase!\n";
        return 1;
      }
      str = finaev::increase_str(str, new_str, dl, dl * 2);
      dl *= 2;
    }
    str[tk_dl++] = c;
  }
  if (tk_dl == 0)
  {
    free(str);
    std::cerr << "No elements!\n";
    return 1;
  }
  int res = 2;
  res = finaev::is_repeat(str, tk_dl);
  std::cout << res << "\n";
  free(str);
}
