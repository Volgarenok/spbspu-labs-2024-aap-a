#include <iostream>
#include <memf.hpp>
#include <string_input.hpp>
#include <string_comparison.hpp>

#include "rectangle.hpp"
#include "shapes_input.hpp"

int main()
{
  size_t allocated = 8;
  rychkov::Shape** composition = static_cast< rychkov::Shape** >(malloc(allocated * sizeof(rychkov::Shape*)));
  if (!composition)
  {
    return 2;
  }

  size_t used = 0;
  char* command = nullptr;
  while (command = rychkov::getline(std::cin, ' '))
  {
    if (!command)
    {
      return std::cin.eof() ? 1 : 2;
    }
    if (used >= allocated)
    {
      rychkov::Shape** temp = reinterpret_cast< rychkov::Shape** >(
            rychkov::realloc(reinterpret_cast< char* >(composition), allocated, allocated*2));
      if (!temp)
      {
        free(composition);
        free(command);
        return 2;
      }
      composition = temp;
      allocated *= 2;
    }

    composition[used] = rychkov::getShape(command, std::cin);
    if (!composition[used])
    {
      std::cin.ignore();
      free(rychkov::getline(std::cin));
    }

    used++;
    free(command);
  }
  for (size_t i = 0; i < used; i++)
  {
    free(composition[used]);
  }
  free(composition);
}
