#include "io_utils.hpp"
#include <iomanip>
#include "shape_utils.hpp"

namespace kizhin {
  void resizeBuffer(double** buffer, size_t& capacity);
  void throwIfNotScaleOrSize(bool isScaleCommand, size_t shapesSize);
  void copy(const double*, const double*, double*);
}

std::ostream& kizhin::outputShapesInfo(std::ostream& os, const Shape* const* shapes)
{
  os << std::fixed << std::setprecision(1);
  os << computeTotalArea(shapes);
  for (const Shape* const* i = shapes; *i != nullptr; ++i) {
    outputShapeFrame(os << ' ', *i);
  }
  return os;
}

std::ostream& kizhin::outputShapeFrame(std::ostream& os, const Shape* shape)
{
  rectangle_t frame = shape->getFrameRect();
  const double x1 = frame.pos.x - frame.width / 2;
  const double x2 = frame.pos.x + frame.width / 2;
  const double y1 = frame.pos.y - frame.height / 2;
  const double y2 = frame.pos.y + frame.height / 2;
  return os << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2;
}

double* kizhin::processInput(std::istream& is, std::ostream& errs, Shape** shapes)
{
  bool isScaleCommand = false;
  std::string currentName;
  double* currentParams = nullptr;
  size_t size = 0;
  try {
    while (is) {
      currentParams = parseInputShape(is, currentName);
      if (currentName == "SCALE") {
        isScaleCommand = true;
        break;
      }
      try {
        shapes[size] = createShape(currentName, currentParams);
        ++size;
      } catch (const std::exception& e) {
        errs << "Error" << e.what() << '\n';
      }
      delete[] currentParams;
      currentParams = nullptr;
    }
    throwIfNotScaleOrSize(isScaleCommand, size);
  } catch (...) {
    delete[] currentParams;
    throw;
  }
  return currentParams;
}

void kizhin::throwIfNotScaleOrSize(bool isScaleCommand, size_t shapesSize)
{
  if (!isScaleCommand) {
    throw std::logic_error("No 'SCALE' command");
  } else if (!shapesSize) {
    throw std::logic_error("No shapes to perform 'SCALE' command");
  }
}

double* kizhin::parseInputShape(std::istream& is, std::string& nameOut)
{
  is >> nameOut;
  size_t paramsCapacity = 16;
  double* params = new double[paramsCapacity];
  params[0] = 0;
  while (is >> params[static_cast< size_t >(1 + params[0])]) {
    ++params[0];
    if (paramsCapacity == params[0] + 1) {
      resizeBuffer(&params, paramsCapacity);
    }
  }
  if (!is && !is.eof()) {
    is.clear();
  }
  return params;
}

void kizhin::resizeBuffer(double** buffer, size_t& capacity)
{
  capacity *= 2;
  double* tempBuffer = nullptr;
  try {
    tempBuffer = new double[capacity];
  } catch (const std::bad_alloc&) {
    delete[] *buffer;
    *buffer = nullptr;
    throw;
  }
  copy(*buffer, *buffer + capacity / 2, tempBuffer);
  delete[] *buffer;
  *buffer = tempBuffer;
}

void kizhin::copy(const double* first, const double* last, double* result)
{
  for (; first != last; ++first, ++result) {
    *result = *first;
  }
}
