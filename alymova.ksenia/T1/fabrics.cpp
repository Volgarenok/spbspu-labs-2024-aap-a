#include "fabrics.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
constexpr size_t figures_cnt = 3;
const std::string figures[figures_cnt] = {"RECTANGLE", "CIRCLE", "REGULAR"};

alymova::Creator::Creator():
  fabrics_(new AbstractCreator*[figures_cnt])
{
  try
  {
    fabrics_[0] = new CreatorRectangle();
    fabrics_[1] = new CreatorCircle();
    fabrics_[2] = new CreatorRegular();
  }
  catch (const std::bad_alloc& e)
  {
    clear();
    throw;
  }
}
alymova::Creator::~Creator()
{
  clear();
}
alymova::Shape* alymova::Creator::create(const std::string& name, std::istream& in)
{
  for (size_t i = 0; i < figures_cnt; i++)
  {
    if (name == figures[i])
    {
      return fabrics_[i]->create(in);
    }
  }
  return nullptr;
}
void alymova::Creator::clear() noexcept
{
  for (size_t i = 0; i < 3; i++)
  {
    delete fabrics_[i];
  }
  delete[] fabrics_;
}
alymova::Shape* alymova::CreatorRectangle::create(std::istream& in)
{
  const size_t cnt_params = 4;
  double params[cnt_params] = {};
  readParameters(in, params, cnt_params);
  Rectangle* shape = new Rectangle(point_t{params[0], params[1]}, point_t{params[2], params[3]});
  return shape;
}
alymova::Shape* alymova::CreatorCircle::create(std::istream& in)
{
  const size_t cnt_params = 3;
  double params[cnt_params] = {};
  readParameters(in, params, cnt_params);
  Circle* shape = new Circle(point_t{params[0], params[1]}, params[2]);
  return shape;
}
alymova::Shape* alymova::CreatorRegular::create(std::istream& in)
{
  const size_t cnt_params = 6;
  double params[cnt_params] = {};
  readParameters(in, params, cnt_params);
  Regular* shape = new Regular(point_t{params[0], params[1]}, point_t{params[2], params[3]}, point_t{params[4], params[5]});
  return shape;
}
void alymova::readParameters(std::istream& in, double* params, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    if (!(in >> params[i]))
    {
      throw std::logic_error("Input shape parameters error");
    }
  }
}
