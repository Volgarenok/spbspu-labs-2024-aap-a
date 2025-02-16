#include <iostream>
#include <string>
#include "shape.hpp"
#include "string_manipulations.hpp"
#include "delete_shape.hpp"
#include "scale_functions.hpp"


int main()
{
  using namespace lanovenko;
	bool scale = false;
	bool errors = false;
	size_t res = 0;
	Shape* shapeArray[10000] = { nullptr };
	while (scale != true)
	{
		std::string str = "";
		Shape* currentFigure = nullptr;
		try
		{
			str = inputStr(std::cin);
		}
		catch (const std::runtime_error& e)
		{
			deleteShape(shapeArray, res);
			std::cerr << e.what() << "\n";
			return 1;
		}
		if (str.find("SCALE") == std::string::npos)
		{
			try
			{
				currentFigure = parseShape(str);
				if (currentFigure != nullptr)
				{
					shapeArray[res++] = currentFigure;
				}
				else
				{
					errors = true;
				}
			}
			catch (const std::bad_alloc& e)
			{
				deleteShape(shapeArray, res);
				std::cerr << "Out of memmory!\n";
				return 1;
			}
		}
		if (str.find("SCALE") != std::string::npos)
		{
			scale = true;
			double* scaleParametrs = nullptr;
			scaleParametrs = paraseScale(str);
			try
			{
				scaleShapes(shapeArray, scaleParametrs, std::cout, res);
			}
			catch (const std::invalid_argument& e)
			{
				deleteShape(shapeArray, res);
				delete[] scaleParametrs;
				std::cerr << e.what() << "\n";
				return 1;
			}
			delete[] scaleParametrs;
		}
	}
	if (errors == true)
	{
		std::cerr << "Some figures are incorrectly described!\n";
	}
	deleteShape(shapeArray, res);
}
