#ifndef MAKEOBJECTS_H
#define MAKEOBJECTS_H

#include <fstream>
#include "base-types.h"
#include "rectangle.h"
#include "square.h"

namespace finaev
{
  Rectangle* makeRectangle(std::istream& in);
  Square* makeSquare(std::istream& in);
}

#endif
