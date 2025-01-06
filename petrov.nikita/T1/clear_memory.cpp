#include "clear_memory.hpp"
void petrov::clearMemory(char * stream_massive, char * type_of_shape, char ** description, size_t created)
{
  delete[] stream_massive;
      delete[] type_of_shape;
      for (size_t i = 0; i < created; i++)
      {
        delete[] description[i];
      }
      delete[] description;
}
