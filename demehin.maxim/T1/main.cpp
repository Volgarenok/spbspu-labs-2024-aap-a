#include <iostream>
#include "rectangle.hpp"
#include "shape.hpp"
#include <string>
#include "base_types.hpp"
#include <iomanip>
#include "ring.hpp"
#include "polygon.hpp"

namespace
{
  void makeIsoScale(demehin::Shape* shapes[], size_t shp_cnt, double scale_k, demehin::point_t& scale_pt)
  {
    for (size_t i = 0; i < shp_cnt; i++)
    {
      demehin::rectangle_t old_fr_rect = shapes[i]->getFrameRect();
      shapes[i]->move(scale_pt);
      demehin::rectangle_t new_fr_rect = shapes[i]->getFrameRect();
      demehin::point_t move_vector;
      move_vector.x_ = (new_fr_rect.pos_.x_ - old_fr_rect.pos_.x_) / scale_k;
      move_vector.y_ = (new_fr_rect.pos_.y_ - old_fr_rect.pos_.y_) / scale_k;
      shapes[i]->scale(scale_k);
      shapes[i]->move(move_vector.x_, move_vector.y_);
    }
  }

  double getFrRectArea(const demehin::rectangle_t& fr_rect)
  {
    return fr_rect.width_ * fr_rect.height_;
  }

  double getFrRectAreaSum(demehin::Shape* shapes[], size_t shp_cnt)
  {
    double area_sum = 0;
    for (size_t i = 0; i < shp_cnt; i++)
    {
      demehin::rectangle_t fr_rect = shapes[i]->getFrameRect();
      area_sum += getFrRectArea(fr_rect);
    }
    return area_sum;
  }

  void getFrRectCords(demehin::rectangle_t& fr_rect, double& lbx, double& lby, double& rtx, double& rty)
  {
    lbx = fr_rect.pos_.x_ - fr_rect.width_ / 2;
    lby = fr_rect.pos_.y_ - fr_rect.height_ / 2;
    rtx = fr_rect.pos_.x_ + fr_rect.width_ / 2;
    rty = fr_rect.pos_.y_ + fr_rect.height_ / 2;
  }

  void printFrRectCords(demehin::Shape* shapes[], size_t shp_cnt)
  {
    for (size_t i = 0; i < shp_cnt; i++)
    {
      double lbx = 0, lby = 0, rtx = 0, rty = 0;
      demehin::rectangle_t fr_rect = shapes[i]->getFrameRect();
      getFrRectCords(fr_rect, lbx, lby, rtx, rty);
      std::cout << lbx << " " << lby << " " << rtx << " " << rty << " ";
    }
    std::cout << "\n";
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
  while (true)
  {
    std::cin >> shape_name;
    if (std::cin.eof())
    {
      std::cerr << "error: eof\n";
      return 1;
    }
    if (shape_name == "RECTANGLE")
    {
      double lbx = 0, lby = 0;
      double rtx = 0, rty = 0;
      std::cin >> lbx;
      std::cin >> lby;
      std::cin >> rtx;
      std::cin >> rty;
      if (lbx >= rtx || lby >= rty)
      {
        is_incorrect_shp = true;
        continue;
      }

      try
      {
        shapes[shp_cnt++] = new demehin::Rectangle(lbx, lby, rtx, rty);
      }
      catch (std::bad_alloc& e)
      {
        free_shapes(shapes, shp_cnt);
        std::cerr << "bad alloc\n";
        return 1;
      }
      shape_name = "";
    }

    else if (shape_name == "RING")
    {
      double cent_x = 0, cent_y = 0, out_r = 0, in_r = 0;
      std::cin >> cent_x >> cent_y >> out_r >> in_r;
      if (out_r < in_r || out_r <= 0 || in_r <= 0)
      {
        is_incorrect_shp = true;
        continue;
      }

      try
      {
        shapes[shp_cnt++] = new demehin::Ring(cent_x, cent_y, out_r, in_r);
      }
      catch (std::bad_alloc& e)
      {
        free_shapes(shapes, shp_cnt);
        std::cerr << "bad alloc\n";
        return 1;
      }

      shape_name = "";
    }

    else if (shape_name == "POLYGON")
    {
      size_t n = 0;
      demehin::point_t vertex[10000];
      while (std::cin.peek() != '\n')
      {
        std::cin >> vertex[n].x_ >> vertex[n].y_;
        ++n;
      }
      if (n < 3)
      {
        is_incorrect_shp = true;
        continue;
      }

      try
      {
        shapes[shp_cnt++] = new demehin::Polygon(n, vertex);
      }
      catch (std::bad_alloc& e)
      {
        free_shapes(shapes, shp_cnt);
        std::cerr << "bad alloc\n";
        return 1;
      }
      shape_name = "";
    }

    else if (shape_name == "SCALE")
    {
      double x = 0;
      double y = 0;
      std::cin >> x;
      std::cin >> y;
      std::cin >> scale_k;
      if (scale_k < 0)
      {
        std::cerr << "Incorrect scale\n";
        return 1;
      }
      scale_pt.x_ = x;
      scale_pt.y_ = y;
      break;
    }
  }

  std::cout << std::fixed;
  std::cout << std::setprecision(1);
  std::cout << std::showpoint;
  double sum_area = getFrRectAreaSum(shapes, shp_cnt);
  std::cout << sum_area << " ";
  printFrRectCords(shapes, shp_cnt);

  makeIsoScale(shapes, shp_cnt, scale_k, scale_pt);

  sum_area = getFrRectAreaSum(shapes, shp_cnt);
  std::cout << sum_area << " ";
  printFrRectCords(shapes, shp_cnt);

  if (is_incorrect_shp)
  {
    std::cerr << "Incorrect shape\n";
  }

  free_shapes(shapes, shp_cnt);
}
