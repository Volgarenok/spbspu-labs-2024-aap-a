#include "kola.h"
#include <cmath>

double komarova::ln_Teilor(double x)
{
  return log(x + sqrt(x*x +1));
}
