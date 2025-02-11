#include "checkString.hpp"

namespace belobrov
{
  const char* checkChar(const char* str, char target);
}

const char* belobrov::checkChar(const char* str, char target)
{
    if (!str)
    {
        return nullptr;
    }
    return (*str == target) ? (str + 1) : nullptr;
}
