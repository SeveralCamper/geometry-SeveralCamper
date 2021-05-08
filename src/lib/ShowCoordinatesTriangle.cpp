#include "ShowCoordinatesTriangle.h"

void ShowCoordinatesTriangle(const TriangleShape coordinates)
{
    std::cout << ">------------------------------<" << std::endl;

    std::cout << "triangle(" << coordinates.x1 << " " << coordinates.y1 << ", "
              << coordinates.x2 << " " << coordinates.y2 << ", "
              << coordinates.x3 << " " << coordinates.y3 << ")" << std::endl;
}
