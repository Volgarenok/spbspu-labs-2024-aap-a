#include "has_sam_set.h"

int timofeev::same_symbols(const char* first_line, const char* second_line)
{
  for (size_t i = 0; first_line[i] != '\0'; i++)
  {
    for (const char* in_sym = second_line; *in_sym != '\0'; in_sym++)
    {
      if (first_line[i] == *in_sym)
      {
        return 1;
      }
    }
  }
  return 0;
}
