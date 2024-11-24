#include <iostream>
#include "isexpression.h"

int main()
{
  const char* str = "a+3";
  std::cout << tkach::isExpression(str) << "\n";

  return 0;
}
