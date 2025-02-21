#include <iomanip>
#include <iostream>
#include <string>
#include "../common/input_string.hpp"
#include "base-types.hpp"
#include "circle.hpp"
#include "composite_shape.hpp"
#include "make_shape.hpp"
#include "rectangle.hpp"
#include "regular.hpp"
#include "ring.hpp"
#include "shape.hpp"
#include "shape_actions.hpp"
#include "specific_output.hpp"

int main()
{
  using namespace evstyunichev;
  CompositeShape compShp(4);
  std::string s;
  bool scaleFlag = 0, errorFlag = 0;
  while (std::cin >> s)
  {
    try
    {
      Shape *cur = nullptr;
      cur = make_shape(std::cin, s);
      if (cur)
      {
        compShp.pushBack(cur);
      }
      else if (s == "SCALE")
      {
        scaleFlag = 1;
        makeScale(compShp, std::cin);
        if (errorFlag)
        {
          std::cerr << "input errors!\n";
        }
      }
      else
      {
        skip_to_sign(std::cin, '\n');
      }
    }
    catch (const std::invalid_argument &e)
    {
      errorFlag = 1;
    }
    catch (const std::logic_error &e)
    {
      std::cerr << e.what() << "\n";
      return 1;
    }
    catch (const std::bad_alloc &e)
    {
      std::cerr << e.what() << '\n';
      return 2;
    }
  }
  if (compShp.empty() || !scaleFlag)
  {
    std::cout << "((\n";
    return 1;
  }
  return 0;
}
