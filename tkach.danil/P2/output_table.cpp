#include "all.h"

void tkach::output_table(double start, double end, size_t maxkolvo, const double error, const double step)
{
  const double epcelon = 1e-6; 
  for(auto i = start; i+epcelon < end; i+=step)
  {
    tkach::output_row(i, maxkolvo, error);
  }
}
