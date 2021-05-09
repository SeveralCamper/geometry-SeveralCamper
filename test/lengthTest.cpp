#include "length.h"

extern "C" {
#include <ctest.h>
}

CTEST(figureSuite, lengthCheck1)
{
    int x1 = 2;
    int x2 = 6;
    int y1 = 6;
    int y2 = 9;
    const double expected = 5;
    const double result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    ASSERT_EQUAL(result, expected);
}

CTEST(figureSuite, lengthCheck2)
{
    int x1 = 2;
    int x2 = 9;
    int y1 = 7;
    int y2 = 5;
    const double expected = 7.2801;
    const double result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    ASSERT_EQUAL(result, expected);
}

CTEST(figureSuite, lengthCheck3)
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;
    const double expected = 0;
    const double result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    ASSERT_EQUAL(result, expected);
}