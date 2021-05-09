#include "CirclePandS.h"

#define _USE_MATH_DEFINES

void CirclePandS(const CircleShape coordinates)
{
    double p = coordinates.r * 2 * M_PI;
    double s = pow(coordinates.r, 2) * M_PI;
    std::cout << "Perimeter is " << p << "\nSquare is " << s << std::endl;
}
