#include <cmath>
#include "geomFun.hpp"

namespace maslovskiy
{
  bool isCorrectTriangle(point_t vertexA, point_t vertexB, point_t vertexC)
  {
    double sideAB = std::sqrt(std::pow((vertexB.x - vertexA.x), 2) + std::pow((vertexB.y - vertexA.y), 2));
    double sideBC = std::sqrt(std::pow((vertexC.x - vertexB.x), 2) + std::pow((vertexC.y - vertexB.y), 2));
    double sideCA = std::sqrt(std::pow((vertexA.x - vertexC.x), 2) + std::pow((vertexA.y - vertexC.y), 2));
    return (sideAB + sideBC > sideCA) && (sideAB + sideCA > sideBC) && (sideBC + sideCA > sideAB);
  }
  double calculateTriangleArea(point_t vertexA, point_t vertexB, point_t vertexC)
  {
    double sideAB = std::sqrt(std::pow((vertexB.x - vertexA.x), 2) + std::pow((vertexB.y - vertexA.y), 2));
    double sideBC = std::sqrt(std::pow((vertexC.x - vertexB.x), 2) + std::pow((vertexC.y - vertexB.y), 2));
    double sideCA = std::sqrt(std::pow((vertexA.x - vertexC.x), 2) + std::pow((vertexA.y - vertexC.y), 2));
    double semiPerimeter = (sideAB + sideBC + sideCA) / 2;
    return std::sqrt(semiPerimeter * (semiPerimeter - sideAB) * (semiPerimeter - sideBC) * (semiPerimeter - sideCA));
  }
  bool isPointInTriangle(point_t vertexA, point_t vertexB, point_t vertexC, point_t point)
  {
    double totalArea = calculateTriangleArea(vertexA, vertexB, vertexC);
    double area1 = calculateTriangleArea(point, vertexA, vertexB);
    double area2 = calculateTriangleArea(point, vertexB, vertexC);
    double area3 = calculateTriangleArea(point, vertexC, vertexA);
    return totalArea == (area1 + area2 + area3);
  }
  bool isPointInQuad(point_t vertexA, point_t vertexB, point_t vertexC, point_t vertexD, point_t pos)
  {
    int sideA = (vertexA.x - pos.x) * (vertexD.y - vertexA.y) - (vertexD.x - vertexA.x) * (vertexA.y - pos.y);
    int sideB = (vertexD.x - pos.x) * (vertexB.y - vertexD.y) - (vertexB.x - vertexD.x) * (vertexD.y - pos.y);
    int sideC = (vertexB.x - pos.x) * (vertexC.y - vertexB.y) - (vertexC.x - vertexB.x) * (vertexB.y - pos.y);
    int sideD = (vertexC.x - pos.x) * (vertexA.y - vertexC.y) - (vertexA.x - vertexC.x) * (vertexC.y - pos.y);
    if (sideA > 0 && sideB > 0 && sideC > 0 && sideD > 0)
    {
      return true;
    }
    else if (sideA < 0 && sideB < 0 && sideC < 0 && sideD < 0)
    {
      return true;
    }
    return false;
  }
}
