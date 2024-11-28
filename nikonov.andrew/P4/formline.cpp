#include "formline.hpp"
#include <cctype>
void nikonov::dgt_snd(char* firstStr, const char* secondStr)
{
  while (*(firstStr) != '\0')
  {
    ++firstStr;
  }
  while (*secondStr != '\0')
  {
    if (std::isdigit(*secondStr))
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
  *firstStr = '\0';
}
