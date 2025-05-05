#include <iostream>
#include <iomanip>
#include "diamond.hpp"
#include "rectangle.hpp"
#include "shape.hpp"
#include "triangle.hpp"

namespace shramko
{
  Shape* readShape(std::istream& in, const std::string& name);
  void printRectangleShapes(Shape** shapes, size_t size);
  void scaleShapes(Shape** shapes, size_t size, double k, point_t center);
  double totalArea (Shape** shapes, size_t size);
  void destroyShapes(Shape** shapes, size_t size);
}

int main()
{
  std::cout << std::fixed << std::setprecision(1);
  std::string name;
  int top = 0;
  shramko::Shape *shapes[10000] = {};
  double total_area = 0.0;
  while (std::cin >> name && name != "SCALE")
  {
    shramko::Shape* shape = nullptr;
    try
    {
      shape = shramko::readShape(std::cin, name);
      if (shape != nullptr)
      {
        total_area += shape->getArea();
        shapes[top++] = shape;
        shape = nullptr;
      }
    }
    catch (const std::exception& e)
    {
      delete shape;
      shape = nullptr;
      std::cerr << e.what() << "\n";
    }
  }
  if (name != "SCALE")
  {
    std::cerr << "scale command not found\n";
    return 1;
  }

  double x = 0.0, y = 0.0, k = 0.0;
  std::cin >> x >> y >> k;
  if (k < 0)
  {
    std::cerr << "k must be positive\n";
    return 2;
  }

  if (top == 0)
  {
    std::cerr << "Nothing to scale\n";
    return 3;
  }

  std::cout << total_area << " ";
  printRectangleShapes(shapes, top);
  std::cout << "\n";

  shramko::scaleShapes(shapes, top, k, {x, y});
  total_area = totalArea(shapes, top);
  std::cout << total_area << " ";
  shramko::printRectangleShapes(shapes, top);
  std::cout << "\n";
  destroyShapes(shapes, top);

  return 0;
}

shramko::Shape* shramko::readShape(std::istream& in, const std::string& name)
{
  shramko::Shape* shape = nullptr;
  try
  {
    if (name == "RECTANGLE")
    {
      point_t top, bottom;

      in >> bottom.x >> bottom.y >> top.x >> top.y;

      shape = new Rectangle{bottom, top};
    }
    else if (name == "TRIANGLE")
    {
      point_t one, two, three;

      in >> one.x >> one.y;
      in >> two.x >> two.y;
      in >> three.x >> three.y;

      shape = new Triangle{one, two, three};
    }
    else if (name == "DIAMOND")
    {
      point_t one, two, three;

      in >> one.x >> one.y;
      in >> two.x >> two.y;
      in >> three.x >> three.y;

      shape = new Diamond{one, two, three};
    }
  }
  catch (const std::exception& e)
  {
    delete shape;
    shape = nullptr;
    throw;
  }
  return shape;
}

void shramko::printRectangleShapes(Shape** shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    auto r = shapes[i]->getFrameRect();
    std::cout << r;
    if (i != size - 1)
    {
      std::cout << " ";
    }
  }
}

void shramko::scaleShapes(Shape** shapes, size_t size, double k, point_t new_center)
{
  for (size_t i = 0; i < size; ++i)
  {
    try
    {
      const point_t c = shapes[i]->getFrameRect().pos;
      shapes[i]->move(new_center);
      point_t new_c = shapes[i]->getFrameRect().pos;
      shapes[i]->scale(k);
      
      const point_t offset
      {
        new_c.x - c.x * k,
        new_c.y - c.y * k
      };
      shapes[i]->move(-offset.x, -offset.y);
    }
    catch (const std::exception& e)
    {
      std::cerr << "Error scaling shape " << i << ": " << e.what() << "\n";
    }
  }
}

double shramko::totalArea(Shape** shapes, size_t size)
{
  double total_area = 0.0;
  for (size_t i = 0; i < size; ++i)
  {
    total_area += shapes[i]->getArea();
  }

  return total_area;
}

void shramko::destroyShapes(Shape **shapes, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shapes[i];
  }
}
