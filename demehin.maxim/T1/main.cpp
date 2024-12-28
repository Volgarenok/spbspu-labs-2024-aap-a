#include <iostream>
#include <string>
#include <iomanip>
#include "rectangle.hpp"
#include "shape.hpp"
#include "base-types.hpp"
#include "ring.hpp"
#include "polygon.hpp"
#include "io_utils.hpp"

namespace
{
  void makeIsoScale(demehin::Shape** shapes, size_t shp_cnt, double scale_k, demehin::point_t& scale_pt)
  {
    for (size_t i = 0; i < shp_cnt; i++)
    {
      demehin::point_t orig_pt = shapes[i]->getFrameRect().pos;
      shapes[i]->move(scale_pt);
      demehin::point_t new_pt = shapes[i]->getFrameRect().pos;
      demehin::point_t move_vector;
      move_vector.x = (new_pt.x - orig_pt.x) * scale_k;
      move_vector.y = (new_pt.y - orig_pt.y) * scale_k;
      shapes[i]->scale(scale_k);
      shapes[i]->move(move_vector.x * -1, move_vector.y * -1);
    }
  }

  double getAreaSum(demehin::Shape** const shapes, size_t shp_cnt)
  {
    double area_sum = 0;
    for (size_t i = 0; i < shp_cnt; i++)
    {
      area_sum += shapes[i]->getArea();
    }
    return area_sum;
  }

  void getFrRectCords(const demehin::rectangle_t& fr_rect, double& lbx, double& lby, double& rtx, double& rty)
  {
    lbx = fr_rect.pos.x - fr_rect.width / 2;
    lby = fr_rect.pos.y - fr_rect.height / 2;
    rtx = fr_rect.pos.x + fr_rect.width / 2;
    rty = fr_rect.pos.y + fr_rect.height / 2;
  }

  void printFrRectCords(std::ostream& out, demehin::Shape** const shapes, size_t shp_cnt)
  {
    out << getAreaSum(shapes, shp_cnt) << " ";
    for (size_t i = 0; i < shp_cnt; i++)
    {
      double lbx = 0, lby = 0, rtx = 0, rty = 0;
      demehin::rectangle_t fr_rect = shapes[i]->getFrameRect();
      getFrRectCords(fr_rect, lbx, lby, rtx, rty);
      out << lbx << " " << lby << " " << rtx << " " << rty;
    }
  }

  void free_shapes(demehin::Shape** shapes, size_t shp_cnt)
  {
    for (size_t i = 0; i < shp_cnt; i++)
    {
      delete shapes[i];
    }
  }
}

int main()
{
  demehin::Shape* shapes[10000] = {};
  size_t shp_cnt = 0;
  double scale_k = 0;
  demehin::point_t scale_pt;
  bool is_incorrect_shp = false;

  std::string shape_name;
  bool is_scale = false;
  while (!is_scale)
  {
    std::cin >> shape_name;
    if (std::cin.eof())
    {
      std::cerr << "error: eof\n";
      free_shapes(shapes, shp_cnt);
      return 1;
    }

    try
    {
      demehin::createShape(shape_name, shapes, shp_cnt);
    }
    catch (const std::bad_alloc& e)
    {
      free_shapes(shapes, shp_cnt);
    }
    catch (const std::logic_error& e)
    {
      delete shapes[shp_cnt--];
      is_incorrect_shp = true;
    }

    if (shape_name == "SCALE")
    {
      double x = 0, y = 0;
      std::cin >> x >> y >> scale_k;
      if (scale_k < 0)
      {
        std::cerr << "Incorrect scale\n";
        free_shapes(shapes, shp_cnt);
        return 1;
      }
      scale_pt.x = x;
      scale_pt.y = y;
      is_scale = true;
    }
  }

  if (shp_cnt == 0)
  {
    std::cerr << "no shapes\n";
    return 1;
  }

  if (is_incorrect_shp)
  {
    std::cerr << "Incorrect shape\n";
  }


  std::cout << std::fixed << std::setprecision(1);
  printFrRectCords(std::cout, shapes, shp_cnt);
  std::cout << "\n";

  makeIsoScale(shapes, shp_cnt, scale_k, scale_pt);

  printFrRectCords(std::cout, shapes, shp_cnt);
  std::cout << "\n";

  free_shapes(shapes, shp_cnt);
}
