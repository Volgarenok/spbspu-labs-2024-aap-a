#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <string>
#include <istream>
#include "shape.h"

cherkasov::Shape* parseShapeInput(const std::string& inputCommand, std::istream& input, bool& invalidInput);
#endif
