#include <iostream>
#include "rectangle.hpp"
#include "shape.hpp"
#include <string>

int main()
{
  demehin::Shape * shapes[10000] = {};
  size_t shp_cnt = 0;

  std::string shape_name;
  while (std::cin >> shape_name)
  {
    if (shape_name == "RECTANGLE")
    {
      demehin::Rectangle* rect = new demehin::Rectangle();
      double lbx = 0, lby = 0;
      double rtx = 0, rty = 0;
      std::cin >> lbx;
      std::cin >> lby;
      std::cin >> rtx;
      std::cin >> rty;
      rect->lb_.x_ = lbx;
      rect->lb_.y_ = lby;
      rect->rt_.x_ = rtx;
      rect->rt_.y_ = rty;
      std::cout << rect->getArea() << "\n";
      shapes[shp_cnt++] = rect;
      shape_name = "";
    }
    else if (shape_name == "SCALE")
    {
      std::cout << "end\n";
      break;
    }
  }


  for (size_t i = 0; i < shp_cnt; i++)
  {
    std::cout << shapes[i]->getArea() << "\n";
  }

}
