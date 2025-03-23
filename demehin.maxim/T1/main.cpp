#include <iostream>
#include <string>
#include <iomanip>
#include "factory.hpp"

namespace
{
  void makeIsoScale(demehin::Shape** shapes, size_t shp_cnt, double scale_k, const demehin::point_t& scale_pt)
  {
    if (scale_k <= 0)
    {
      throw std::logic_error("incorrect_scale");
    }

    for (size_t i = 0; i < shp_cnt; i++)
    {
      demehin::point_t orig_pt = shapes[i]->getFrameRect().pos;
      shapes[i]->move(scale_pt);
      demehin::point_t new_pt = shapes[i]->getFrameRect().pos;
      double move_x = (new_pt.x - orig_pt.x) * scale_k;
      double move_y = (new_pt.y - orig_pt.y) * scale_k;
      demehin::point_t move_vector = {move_x, move_y};
      shapes[i]->scaleUnsafely(scale_k);
      shapes[i]->move(move_vector.x * -1, move_vector.y * -1);
    }
  }

  double getAreaSum(const demehin::Shape* const* shapes, size_t shp_cnt)
  {
    double area_sum = 0;
    for (size_t i = 0; i < shp_cnt; i++)
    {
      area_sum += shapes[i]->getArea();
    }
    return area_sum;
  }

  void getFrRectCords(const demehin::rectangle_t& fr_rect, double* frRectCords)
  {
    frRectCords[0] = fr_rect.pos.x - fr_rect.width / 2;
    frRectCords[1] = fr_rect.pos.y - fr_rect.height / 2;
    frRectCords[2] = fr_rect.pos.x + fr_rect.width / 2;
    frRectCords[3] = fr_rect.pos.y + fr_rect.height / 2;
  }

  void printShapesInfo(std::ostream& out, const demehin::Shape* const* shapes, size_t shp_cnt)
  {
    out << getAreaSum(shapes, shp_cnt);
    for (size_t i = 0; i < shp_cnt; i++)
    {
      double frRectCords[4] = {};
      demehin::rectangle_t fr_rect = shapes[i]->getFrameRect();
      getFrRectCords(fr_rect, frRectCords);
      for (size_t i = 0; i < 4; i++)
      {
        out << " " << frRectCords[i];
      }
    }
  }

  void freeShapes(demehin::Shape** shapes, size_t shp_cnt)
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
  bool is_incorrect_shp = false;

  std::string shape_name;
  while (shape_name != "SCALE")
  {
    std::cin >> shape_name;
    if (std::cin.eof())
    {
      std::cerr << "error: eof\n";
      freeShapes(shapes, shp_cnt);
      return 1;
    }

    try
    {
      shapes[shp_cnt] = demehin::createShape(std::cin, shape_name);
    }
    catch (const std::bad_alloc&)
    {
      freeShapes(shapes, shp_cnt);
      return 1;
    }
    catch (const std::logic_error&)
    {
      is_incorrect_shp = true;
    }

    if (shapes[shp_cnt] != nullptr)
    {
      shp_cnt++;
    }
  }

  double scale_pt_x = 0, scale_pt_y = 0, scale_k = 0;
  std::cin >> scale_pt_x >> scale_pt_y >> scale_k;

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
  printShapesInfo(std::cout, shapes, shp_cnt);
  std::cout << "\n";

  demehin::point_t scale_pt = {scale_pt_x, scale_pt_y};
  try
  {
    makeIsoScale(shapes, shp_cnt, scale_k, scale_pt);
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    freeShapes(shapes, shp_cnt);
    return 1;
  }

  printShapesInfo(std::cout, shapes, shp_cnt);
  std::cout << "\n";

  freeShapes(shapes, shp_cnt);
}

