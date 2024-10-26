#include <iostream>
#include "taylors_row.hpp"
#include "print_comparison_table.hpp"

int main()
{
  rychkov::comparison::printTable(-0.5, 0.5, 0.05, 8, 5e-3);
}
