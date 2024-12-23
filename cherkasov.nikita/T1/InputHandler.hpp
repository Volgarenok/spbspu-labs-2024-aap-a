#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP
#include <string>
#include <istream>
#include "shape.hpp"

cherkasov::Shape* parseShapeInput(const std::string& inputCommand, std::istream& input, bool& invalidInput);

#endif
