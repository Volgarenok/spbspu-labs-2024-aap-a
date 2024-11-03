#include "detect_exceptions.hpp"
#include <iostream>

bool check_arg(int m_argc, char ** m_argv)
{
  if (m_argc < 3)
  {
    std::cerr << "Not enought arguments";
    return false;
  }
  else if (m_argc > 3)
  {
    std::cerr << "Too many arguments";
    return false;
  }
  else
  {
    size_t len = 0;
    size_t letter = 0;
    while (m_argv[1][len])
    {
      if (m_argv[1][len] > 57 || m_argv[1][len] < 48)
      {
        ++letter;
      }
      ++len;
    }
    if (!(m_argv[1] == "+1" || m_argv[1] == "+2" || m_argv[1] == "1" || m_argv[1] == "2"))
    {
      if (letter == 0 || (letter == 1 && (m_argv[1][0] == '-' || m_argv[1][0] == '+')))
      {
        std::cerr << "First parameter is out of range";
        return false;
      }
      else
      {
        std::cerr << "First parameter is not a number";
        return false;
      }
    }
  }
  return true;
}
