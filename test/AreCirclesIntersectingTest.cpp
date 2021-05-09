#include "AreCirclesIntersecting.h"

extern "C" {
#include <ctest.h>
}

CTEST(figureSuite, interceptionCheck1)
{
    CircleShape circle1;
    circle1.x = 3;
    circle1.y = 4;
    circle1.r = 5;
    CircleShape circle2;
    circle2.x = 3;
    circle2.y = 4;
    circle2.r = 5;
    const bool result = AreCirclesIntersecting(circle1, circle2);
    ASSERT_TRUE(result);
}

CTEST(figureSuite, interceptionCheck2)
{
    CircleShape circle1;
    circle1.x = 3;
    circle1.y = 4;
    circle1.r = 5;
    CircleShape circle2;
    circle2.x = 30;
    circle2.y = 40;
    circle2.r = 5;
    const bool result = AreCirclesIntersecting(circle1, circle2);
    ASSERT_FALSE(result);
}

CTEST(figureSuite, interceptionCheck3)
{
    CircleShape circle1;
    circle1.x = 3;
    circle1.y = 4;
    circle1.r = 5;
    CircleShape circle2;
    circle2.x = 12;
    circle2.y = 4;
    circle2.r = 5;
    const bool result = AreCirclesIntersecting(circle1, circle2);
    ASSERT_TRUE(result);
}