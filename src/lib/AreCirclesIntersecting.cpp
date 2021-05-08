#include "AreCirclesIntersecting.h"

bool AreCirclesIntersecting(
        const CircleShape coordinatesShape1,
        const CircleShape coordinatesShape2)
{
    int distSq = (coordinatesShape1.x - coordinatesShape2.x)
                    * (coordinatesShape1.x - coordinatesShape2.x)
            + (coordinatesShape1.y - coordinatesShape2.y)
                    * (coordinatesShape1.y - coordinatesShape2.y);
    int radSumSq = (coordinatesShape1.r + coordinatesShape2.r)
            * (coordinatesShape1.r + coordinatesShape2.r);
    return !(distSq >= radSumSq);
}
