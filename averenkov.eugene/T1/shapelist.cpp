/*#include "shapelist.hpp"
#include "makeshape.hpp"
#include "rectangle.hpp"
#include "ellipse.hpp"
#include "diamond.hpp"
void averenkov::rectangleAdd(averenkov::Shape** shapes, size_t shapeC, std::istream& input, averenkov::Rectangle* (*foo)(std::istream&))
{
  averenkov::Rectangle shap;
  try
  {
    shap = foo(input);
  }
  catch
  {
    delete shap;
    return;
  }
  shapes[shapeC++] = shap;
  return;
}

void averenkov::ellipseAdd(averenkov::Shape** shapes, size_t shapeC, std::istream& input, averenkov::Ellipse* (*foo)(std::istream&))
{
  averenkov::Ellipse shap;
  try
  {
    shap = foo(input);
  }
  catch
  {
    delete shap;
    return;
  }
  shapes[shapeC++] = shap;
  return;
}
void averenkov::diamondAdd(averenkov::Shape** shapes, size_t shapeC, std::istream& input, averenkov::Diamond* (*foo)(std::istream&))
{
  averenkov::Diamond shap;
  try
  {
    shap = foo(input);
  }
  catch
  {
    delete shap;
    return;
  }
  shapes[shapeC++] = shap;
  return;
}


*/
