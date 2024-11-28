#include "formline.hpp"
#include <cctype>
void nikonov::dgt_snd(char* firstStr, const char* secondStr)
{
  while (true)
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
