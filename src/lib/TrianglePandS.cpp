#include "TrianglePandS.h"
#include "length.h"

void TrianglePandS(const TriangleShape coordinates)
{
    double AB = length(
            coordinates.x1, coordinates.y1, coordinates.x2, coordinates.y2);
    double BC = length(
            coordinates.x2, coordinates.y2, coordinates.x3, coordinates.y3);
    double CA = length(
            coordinates.x3, coordinates.y3, coordinates.x1, coordinates.y1);
    double p = AB + BC + CA;
    double p2 = p / 2;
    double s = sqrt(p2 * (p2 - AB) * (p2 - BC) * (p2 - CA));
    std::cout << "Perimeter is " << p << "\nSquare is " << s << std::endl;
}
