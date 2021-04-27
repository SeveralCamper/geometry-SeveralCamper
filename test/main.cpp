#define CTEST_MAIN
#include <iostream>
#define CTEST_COLOR_OK
#define CTEST_SEGFAULT
extern "C" {
#include <ctest.h>
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}
