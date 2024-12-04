#include <iostream>
#include "rectangle.hpp"
#include "shape.hpp"
#include <string>
#include "base_types.hpp"

int main()
{
  demehin::Shape * shapes[10000] = {};
  size_t shp_cnt = 0;
  double scale_k = 0;
  demehin::point_t scale_pt;

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
      double x = 0;
      double y = 0;
      std::cin >> x;
      std::cin >> y;
      std::cin >> scale_k;
      scale_pt.x_ = x;
      scale_pt.y_ = y;
      break;
    }
  }



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
    std::cout << old_fr_rect.pos_.x_ << "\n";
    std::cout << new_fr_rect.pos_.x_ << "\n";
  }

  for (size_t i = 0; i < shp_cnt; i++)
  {
    demehin::point_t fr_lb;
    demehin::point_t fr_rt;
    demehin::rectangle_t fr_rect = shapes[i]->getFrameRect();
    fr_rt.x_ = fr_rect.pos_.x_ + fr_rect.width_ / 2;
    fr_rt.y_ = fr_rect.pos_.y_ + fr_rect.height_ / 2;
    fr_lb.x_ = fr_rect.pos_.x_ - fr_rect.width_ / 2;
    fr_lb.y_ = fr_rect.pos_.y_ - fr_rect.width_ / 2;
    std::cout << fr_rect.pos_.x_ << "\n";
    std::cout << shapes[i]->getArea() << " " << fr_lb.x_ << " " << fr_lb.y_ << " " << fr_rt.x_ << " " << fr_rt.y_ << "\n";
  }
}
