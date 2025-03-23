#include "geomFunc.hpp"
#include <iostream>
#include <cmath>

namespace belobrov
{
  void deleteShapes(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i) {
      if (shapes[i] != nullptr) {
        delete shapes[i];
      }
    }
  }

  void outputFrameCoordinates(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i) {
      if (shapes[i] != nullptr) {
        try {
          rectangle_t frame = shapes[i]->getFrameRect();
          if (i > 0) {
            std::cout << " ";
          }
          std::cout << frame.pos.x - frame.width / 2 << " " << frame.pos.y - frame.height / 2;
          std::cout << " " << frame.pos.x + frame.width / 2 << " " << frame.pos.y + frame.height / 2;
        } catch (const std::invalid_argument& e) {
          std::cerr << "Invalid";
          continue;
        }
      }
    }
  }

  double calculateTotalArea(Shape** shapes, size_t count) {
    double totalArea = 0.0;
    for (size_t i = 0; i < count; ++i) {
      if (shapes[i] != nullptr) {
        totalArea += shapes[i]->getArea();
      }
    }
    return totalArea;
  }

  void applyIsoScaling(Shape** shapes, size_t count, const point_t& center, double k) {
    for (size_t i = 0; i < count; ++i) {
      if (shapes[i] != nullptr) {
        try {
          point_t isCenter = shapes[i]->getFrameRect().pos;
          shapes[i]->scale(k);
          shapes[i]->move((isCenter.x - center.x) * (k - 1), (isCenter.y - center.y) * (k - 1));
        } catch (const std::invalid_argument& e) {
          std::cerr << "Invalid";
          continue;
        }
      }
    }
  }
  bool isCorrectTriangle(point_t v1, point_t v2, point_t v3)
  {
    double sideAB = std::sqrt(std::pow((v2.x - v1.x), 2) + std::pow((v2.y - v1.y), 2));
    double sideBC = std::sqrt(std::pow((v3.x - v2.x), 2) + std::pow((v3.y - v2.y), 2));
    double sideCA = std::sqrt(std::pow((v1.x - v3.x), 2) + std::pow((v1.y - v3.y), 2));
    return (sideAB + sideBC > sideCA) && (sideAB + sideCA > sideBC) && (sideBC + sideCA > sideAB);
  }
  double calculateTriangleArea(point_t v1, point_t v2, point_t v3)
  {
    double sideAB = std::sqrt(std::pow((v2.x - v1.x), 2) + std::pow((v2.y - v1.y), 2));
    double sideBC = std::sqrt(std::pow((v3.x - v2.x), 2) + std::pow((v3.y - v2.y), 2));
    double sideCA = std::sqrt(std::pow((v1.x - v3.x), 2) + std::pow((v1.y - v3.y), 2));
    double semiPerimeter = (sideAB + sideBC + sideCA) / 2;
    return std::sqrt(semiPerimeter * (semiPerimeter - sideAB) * (semiPerimeter - sideBC) * (semiPerimeter - sideCA));
  }
  bool isPointInTriangle(point_t v1, point_t v2, point_t v3, point_t point)
  {
    double totalArea = calculateTriangleArea(v1, v2, v3);
    double area1 = calculateTriangleArea(point, v1, v2);
    double area2 = calculateTriangleArea(point, v2, v3);
    double area3 = calculateTriangleArea(point, v3, v1);
    return totalArea == (area1 + area2 + area3);
  }
}
