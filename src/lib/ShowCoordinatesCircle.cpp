#include "ShowCoordinatesCircle.h"

void ShowCoordinatesCircle(const CircleShape coordinates)
{
    std::cout << ">------------------------------<" << std::endl;

    std::cout << "circle(" << coordinates.x << " " << coordinates.y << ", "
              << coordinates.r << ")" << std::endl;
}
