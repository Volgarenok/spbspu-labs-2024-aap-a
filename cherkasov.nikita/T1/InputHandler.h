#ifndef INPUTHANDLER_H
#define INPUTHANDLER_H
#include <string>
#include "shape.h"

cherkasov::Shape* parseShapeInput(const std::string& inputCommand, bool& invalidInput);
namespace cherkasov
{
  bool parseScalingInput(double& isoCenterX, double& isoCenterY, double& scalingFactor);
}
#endif
