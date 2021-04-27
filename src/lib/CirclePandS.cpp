#include "CirclePandS.h"

#define _USE_MATH_DEFINES

void CirclePandS(const std::vector<int>& coordinates)
{
    double p = coordinates[2] * 2 * M_PI;
    double s = coordinates[2] * coordinates[2] * M_PI;
    std::cout << "Perimeter is " << p << "\nSquare is " << s << std::endl;
}
