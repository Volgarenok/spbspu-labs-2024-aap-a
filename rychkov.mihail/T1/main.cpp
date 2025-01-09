#include <iostream>
#include <iomanip>

#include <string_input.hpp>
#include <string_comparison.hpp>

#include "shapes_input.hpp"
#include "composite-shape.hpp"

namespace rychkov
{
  std::ostream& printRectangle(std::ostream& out, rectangle_t rect);
  std::ostream& printCompositionData(std::ostream& out, const CompositeShape& composition);
}

int main()
{
  std::cout << std::fixed << std::setprecision(1);

  rychkov::CompositeShape composition;
  bool allIsValid = true;
  char* command = nullptr;
  while ((command = rychkov::getline(std::cin, ' ')) && (std::cin.good()))
  {
    if (rychkov::cmpEnd(command, "SCALE") == 0)
    {
      rychkov::point_t scaleCenter{0, 0};
      double coef = 1;
      bool inputHasError = false;
      if (std::cin >> scaleCenter.x >> scaleCenter.y >> coef)
      {
        if (!allIsValid)
        {
          std::cerr << "some of figures have errors in input description\n";
        }
        if (composition.size() == 0)
        {
          std::cerr << "there are no valid shapes in input\n";
          inputHasError = true;
        }
        if (coef <= 0)
        {
          std::cerr << "scale coefficient is non-positive\n";
          inputHasError = true;
        }
        if (!inputHasError)
        {
          rychkov::printCompositionData(std::cout, composition) << '\n';
          rychkov::scale(composition, coef, scaleCenter);
          rychkov::printCompositionData(std::cout, composition) << '\n';
        }
      }
      free(command);
      return !std::cin.good() || inputHasError;
    }

    bool isUnknown = false;
    rychkov::Shape* temp = rychkov::getShape(command, std::cin, isUnknown);
    if (isUnknown)
    {
      free(rychkov::getline(std::cin));
    }
    else if (!temp)
    {
      allIsValid = false;
      std::cin.clear();
    }
    else
    {
      try
      {
        composition.push_back(temp);
      }
      catch (const std::bad_alloc&)
      {
        temp->~Shape();
        free(temp);
        free(command);
        return 2;
      }
    }
    free(command);
    command = nullptr;
  }
  free(command);
  return std::cin.fail() ? 2 : 1;
}

std::ostream& rychkov::printRectangle(std::ostream& out, rectangle_t rect)
{
  out << rect.pos.x - rect.width / 2;
  out << ' ' << rect.pos.y - rect.height / 2;
  out << ' ' << rect.pos.x + rect.width / 2;
  out << ' ' << rect.pos.y + rect.height / 2;
  return out;
}
std::ostream& rychkov::printCompositionData(std::ostream& out, const CompositeShape& composition)
{
  out << composition.getArea();
  for (size_t i = 0; i < composition.size(); i++)
  {
    printRectangle(out << ' ', composition[i]->getFrameRect());
  }
  return out;
}
