<<<<<<< HEAD
<<<<<<< HEAD
#include <iostream>
#include "processLine.hpp"

int main()
{
  char * line = nullptr;
  line = krylov::inputLine(std::cin);
  if (line == nullptr)
  {
    std::cerr << "Memory allocation failure!\n";
    return 1;
  }
  if (line[0] == '\0')
  {
    std::cerr << "No characters to convert\n";
    delete[] line;
    return 1;
  }
}
=======
int main()
{}
>>>>>>> master
=======
int main()
{}
>>>>>>> master
