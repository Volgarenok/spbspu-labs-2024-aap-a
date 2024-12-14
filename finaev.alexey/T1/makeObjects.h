#ifndef MAKEOBJECTS_H
#define MAKEOBJECTS_H

#include <ostream>
#include "base-types.h"
#include "rectangle.h"

namespace finaev
{
  Rectangle* makeRectangle(std::istream& in);
}

#endif
