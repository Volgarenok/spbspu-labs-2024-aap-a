#include "TaylorSeries.hpp"
#include "Table.hpp"


int main()
{
   double left = 0.0, right = 0.0;
   size_t k = 0;
   std::cin >> left >> right >> k;
   if (!std::cin)
   {
     std::cerr << "The input data could not be recognized\n";
     return 1;
   }
   if (left > right)
   {
     std::cerr << "The interval is set incorrectly\n";
     return 1;
   }
   if (left <= -1.0 || right >= 1.0)
   {
     std::cerr << "The interval is not entirely within the scope of the function definition\n";
     return 1;
   }

   const double error = 0.001;
   const double step = 0.1;

   smirnov::outTable(left, right, k, error, step);
}
