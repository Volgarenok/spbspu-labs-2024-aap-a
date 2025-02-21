#include <string>
#include "shape.hpp"
#include "shapeManipulator.hpp"
#include "makeShape.hpp"

int main()
{
  using namespace mozhegova;
  Shape * shapes[10000] = {};
  size_t count = 0;
  std::string shapeName;
  bool flag = false;
  while (shapeName != "SCALE")
  {
    if (std::cin.eof())
    {
      std::cerr << "Incorrect scale\n";
      destroy(shapes, count);
      return 1;
    }
    std::cin >> shapeName;
    try
    {
      shapes[count] = makeShape(std::cin, shapeName);
      count++;
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Out of memory\n";
      destroy(shapes, count);
      return 1;
    }
    catch (const std::invalid_argument &)
    {
      flag = true;
    }
    catch (const std::logic_error &)
    {
      continue;
    }
  }
  double p1 = 0.0, p2 = 0.0, scaleCoef = 0.0;
  std::cin >> p1 >> p2 >> scaleCoef;

  if (count == 0)
  {
    std::cerr << "There are no shapes\n";
    return 1;
  }
  std::cout << std::fixed;
  std::cout.precision(1);
  std::cout << getSumArea(shapes, count) << " ";
  printCoorRect(std::cout, shapes, count);
  std::cout << '\n';

  point_t scaleCenter = {p1, p2};
  try
  {
    scaleShapes(shapes, count, scaleCenter, scaleCoef);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << e.what() << '\n';
    destroy(shapes, count);
    return 1;
  }

  std::cout << getSumArea(shapes, count) << " ";
  printCoorRect(std::cout, shapes, count);
  std::cout << '\n';
  destroy(shapes, count);
  if (flag)
  {
    std::cerr << "There is an incorrect shape\n";
  }
}
