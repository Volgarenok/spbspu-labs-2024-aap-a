#include "formline.hpp"
#include <cctype>
void nikonov::add_digit_symb(char* firstStr, const char* secondStr)
{
  while (firstStr && secondStr)
  {
    if (*(firstStr) != '\0')
    {
      ++firstStr;
      continue;
    }
    else
    {
      if (*secondStr == '\0')
      {
        return;
      }
      else if (std::isdigit(*secondStr))
      {
        *(firstStr) = *(secondStr);
        ++secondStr;
        ++firstStr;
      }
      else
      {
        ++secondStr;
      }
    }
  }
}
