#include "io_data.hpp"
#include <iomanip>
#include <resize_line.hpp>
#include "composite-shape.hpp"

double * zakirov::get_parameters_series(std::istream & in)
{
  constexpr size_t step = 1;
  size_t start = 0;
  size_t finish = 0;
  size_t real_size = 1;
  double size_built_in = 0.0;
  double * parameters = static_cast< double * >(malloc(real_size * sizeof(double)));
  if (!parameters)
  {
    throw std::logic_error("Error! Not enought memory.");
  }

  parameters[0] = size_built_in;
  char * workline = get_to_symbol(in, step, '\n');
  while (workline[start] != '\0')
  {
    double * expanded_parameters = extra_elements(parameters, real_size, step);
    free(parameters);
    if (!expanded_parameters)
    {
      throw std::logic_error("Error! Not enought memory.");
    }

    parameters = expanded_parameters;
    while (workline[finish] != ' ' && workline[finish] != '\0')
    {
      ++finish;
    }

    parameters[real_size++] = std::stod(workline);
    while (start < finish)
    {
      workline[start] = ' ';
      ++start;
    }
    start = finish;
    ++finish;
    parameters[0] = ++size_built_in;
  }

  free(workline);
  return parameters;
}

void zakirov::get_parameters(std::istream & in, double * array, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    double parameter = 0.0;
    in >> parameter;
    array[i] = parameter;
  }

  if (!in)
  {
    throw std::logic_error("Error in getting arguments");
  }
}

void zakirov::output_frame(std::ostream & out, const CompositeShape & shapes, size_t id)
{
  rectangle_t frame = shapes[id]->getFrameRect();
  point_t frame_bottom_left{frame.pos.x - frame.width / 2, frame.pos.y - frame.height / 2};
  point_t frame_top_right{frame.pos.x + frame.width / 2, frame.pos.y + frame.height / 2};
  out << frame_bottom_left.x << ' ' << frame_bottom_left.y << ' ';
  out << frame_top_right.x << ' ' << frame_top_right.y;
}

void zakirov::full_output(std::ostream & out, const CompositeShape & shapes)
{
  out << std::fixed << std::setprecision(1);
  out << shapes.getArea();
  for (size_t id = 0; id < shapes.size(); ++id)
  {
    std::cout << ' ';
    output_frame(out, shapes, id);
  }
}
