#include "AreCirclesIntersecting.h"

bool AreCirclesIntersecting(
        const CircleShape coordinatesShape1,
        const CircleShape coordinatesShape2)
{
    int distSq = pow((coordinatesShape1.x - coordinatesShape2.x), 2)
            + pow((coordinatesShape1.y - coordinatesShape2.y), 2);
    int radSumSq = pow((coordinatesShape1.r + coordinatesShape2.r), 2);
    return !(distSq >= radSumSq);
}
