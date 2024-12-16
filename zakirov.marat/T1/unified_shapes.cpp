#include "unified_shapes.hpp"
#include <stdexcept>
#include <resize_line.hpp>
#include <string>
#include <cstddef>

namespace
{
  char * get_string(std::istream & in, size_t step, char interrupt_el)
  {
    size_t start = 1, finish = 1;
    char * line = static_cast< char * >(malloc(sizeof(char)));
    if (line == nullptr)
    {
      return line;
    }
    char last_symbol = interrupt_el;
    in >> last_symbol >> std::noskipws;
    line[0] = last_symbol;
    while (last_symbol != interrupt_el)
    {
      char * expanded_line = zakirov::expand_line(line, finish, step);
      finish += step;
      if (expanded_line == nullptr)
      {
        free(line);
        return expanded_line;
      }

      zakirov::get_segment(in, expanded_line, start, finish);
      free(line);
      line = expanded_line;
      for (size_t i = start; i < finish; ++i)
      {
        if (line[i] == interrupt_el)
        {
          last_symbol = line[i];
          break;
        }
        else if (i == finish - 1)
        {
          last_symbol = line[i];
        }
      }

      start += step;
    }

    in >> std::skipws;
    return line;
  }

  double * extra_element(double * array, size_t size)
  {
    size_t new_size = size * sizeof(double) + sizeof(double);
    double * new_array = static_cast< double * >(malloc(new_size));
    if (new_array == nullptr)
    {
      return new_array;
    }

    for (size_t i = 0; i < size; ++i)
    {
      new_array[i] = array[i];
    }

    return new_array;
  }
}

zakirov::Rectangle * zakirov::make_rectangle(double bottom_x, double bottom_y, double top_x, double top_y)
{
  point_t bottom_left, top_right;

  bottom_left.x_ = bottom_x;
  bottom_left.y_ = bottom_y;
  top_right.x_ = top_x;
  top_right.y_ = top_y;

  return new Rectangle(bottom_left, top_right);
}

zakirov::Circle * zakirov::make_circle(double center_x, double center_y, double radius)
{
  point_t center;

  center.x_ = center_x;
  center.y_ = center_y;

  return new Circle(center, radius);
}

zakirov::Ring * zakirov::make_ring(double center_x, double center_y, double in_radius, double ex_radius)
{
  point_t center;

  center.x_ = center_x;
  center.y_ = center_y;

  return new Ring(center, in_radius, ex_radius);
}

zakirov::Shape * zakirov::make_shape(const double * data)
{
  try
  {
    if (data[0] == 1.0 && data[1] == 4.0)
    {
      return make_rectangle(data[2], data[3], data[4], data[5]);
    }
    else if (data[0] == 2.0 && data[1] == 3.0)
    {
      return make_circle(data[2], data[3], data[4]);
    }
    else if (data[0] == 3.0 && data[1] == 4.0)
    {
      return make_ring(data[2], data[3], data[4], data[5]);
    }
    else
    {
      return nullptr;
    }
  }
  catch (const std::invalid_argument & e)
  {
    return nullptr;
  }
}

double * zakirov::get_data(std::istream & in)
{
  constexpr size_t step = 1;
  size_t real_size = 2;
  double * data = static_cast< double * >(malloc(real_size * sizeof(double)));
  if (data == nullptr)
  {
    return nullptr;
  }

  std::string shape = get_string(in, step, ' ');
  if (shape == "RECTANGLE ")
  {
    data[0] = 1.0;
  }
  else if (shape == "CIRCLE ")
  {
    data[0] = 2.0;
  }
  else if (shape == "RING ")
  {
    data[0] = 3.0;
  }
  else if (shape == "SCALE ")
  {
    data[0] = 4.0;
  }
  else
  {
    data[0] = 0.0;
  }

  size_t location = 2;
  double counter = 0.0;
  char * workline = get_string(in, step, '\n');
  size_t start  = 0, finish = 0;
  while (workline[start] != '\n')
  {
    data = extra_element(data, location);
    while (workline[finish] != ' ' && workline[finish] != '\n')
    {
      ++finish;
    }

    data[location++] = std::stod(workline);
    while (start != finish)
    {
      workline[start] = ' ';
      ++start;
    }

    ++counter;
    ++finish;
  }

  data[1] = counter;
  return data;
}

void zakirov::scale_from_point(Shape * mutable_shape, point_t target, double k)
{
  point_t nailed_p1 = mutable_shape -> getFrameRect().position_;
  mutable_shape -> move(target);
  point_t nailed_p2 = mutable_shape -> getFrameRect().position_;
  mutable_shape -> scale(k);

  point_t bias;
  bias.x_ = nailed_p2.x_ - nailed_p1.x_;
  bias.y_ = nailed_p2.y_ - nailed_p1.y_;

  mutable_shape -> move(-bias.x_ * k, -bias.x_ * k);
}

void zakirov::output_frame(std::ostream & out, Shape ** shapes, size_t quantity)
{
  for (size_t i = 0; i < quantity; ++i)
  {
    zakirov::rectangle_t frame = shapes[i] -> getFrameRect();

    zakirov::point_t frame_bottom_left;
    frame_bottom_left.x_ = frame.position_.x_ - frame.width_ / 2;
    frame_bottom_left.y_ = frame.position_.y_ - frame.height_ / 2;

    zakirov::point_t frame_top_right;
    frame_top_right.x_ = frame.position_.x_ + frame.width_ / 2;
    frame_top_right.y_ = frame.position_.y_ + frame.height_ / 2;

    out << ' ' << frame_bottom_left.x_ << ' ' << frame_bottom_left.y_;
    out << ' ' << frame_top_right.x_ << ' ' << frame_top_right.y_;
  }
  out << '\n';
}

void zakirov::clear_shapes(Shape ** shapes, size_t quantity)
{
  for (size_t i = 0; i < quantity; ++i)
  {
    delete shapes[i];
  }
}
