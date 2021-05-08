#ifndef ARE_CIRCLE_AND_TRIANGLE_INTERSECTING_H_
#define ARE_CIRCLES_AND_TRIANGLE_INTERSECTING_H_

#include "CircleShape.h"
#include "TriangleShape.h"
#include <cmath>
#include <iostream>
#include <vector>

#define _USE_MATH_DEFINES

bool AreCircleAndTriangleIntersecting(
        const CircleShape coordinatesShape1,
        const TriangleShape coordinatesShape2);

#endif