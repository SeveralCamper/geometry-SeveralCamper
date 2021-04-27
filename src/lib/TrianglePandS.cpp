#include "TrianglePandS.h"
#include "length.h"

void TrianglePandS(const std::vector<int>& coordinates)
{
    double AB = length(
            coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
    double BC = length(
            coordinates[2], coordinates[3], coordinates[4], coordinates[5]);
    double CA = length(
            coordinates[4], coordinates[5], coordinates[0], coordinates[1]);
    double p = AB + BC + CA;
    double p2 = p / 2;
    double s = sqrt(p2 * (p2 - AB) * (p2 - BC) * (p2 - CA));
    std::cout << "Perimeter is " << p << "\nSquare is " << s << std::endl;
}
