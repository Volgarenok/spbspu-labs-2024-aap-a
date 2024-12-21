#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <string>
#include "shape.h"
namespace cherkasov
{
  Shape* parseShapeInput(const std::string& inputCommand, bool& invalidInput);
  bool parseScalingInput(double& isoCenterX, double& isoCenterY, double& scalingFactor);
}
#endif
