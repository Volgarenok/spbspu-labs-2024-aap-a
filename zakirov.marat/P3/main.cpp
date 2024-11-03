#include <iostream>
#include "detect_exceptions.hpp"

int main(int argc, char ** argv)
{
  if (!check_arg(argc, argv))
  {
    return 1;
  }
}
