#include <iomanip>
#include <iostream>
#include <string>
#include "../common/input_string.hpp"
#include "base-types.hpp"
#include "composite_shape.hpp"
#include "make_shape.hpp"
#include "shape.hpp"
#include "shape_actions.hpp"

int main()
{
  using namespace evstyunichev;
  CompositeShape compShp(2);
  std::string command;
  bool scaleFlag = 0, errorFlag = 0;
  while (std::cin >> command)
  {
    Shape *cur = nullptr;
    try
    {
      cur = make_shape(std::cin, command);
      compShp.pushBack(cur);
      if (command == "SCALE")
      {
        scaleFlag = 1;
        makeScale(compShp, std::cin);
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
      delete cur;
      std::cerr << e.what() << '\n';
      return 2;
    }
  }
  if (errorFlag)
  {
    std::cerr << "input errors!\n";
  }
  if (compShp.empty() || !scaleFlag)
  {
    std::cout << "((\n";
    return 1;
  }
  return 0;
}
