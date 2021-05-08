#include "AreCircleAndTriangleIntersecting.h"

bool AreCircleAndTriangleIntersecting(
        const CircleShape coordinatesShape1,
        const TriangleShape coordinatesShape2)
{
    float res = 0;
    float ab_l = VecLen(tr->A, tr->B);
    float ob_l = VecLen(cr->Center, tr->B);
    res = (ab_l + ob_l
           + sqrt(pow(ab_l + ob_l, 2) - abs(pow(ab_l, 2)) * pow(abs(ob_l), 2)
                  - pow(cr->Radius, 2)))
            / abs(pow(ab_l, 2));
    if (1 > res && res > 0)
        return true;
    else
        return false;
}