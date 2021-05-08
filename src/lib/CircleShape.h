#ifndef CIRCLE_SHAPE_
#define CIRCLE_SHAPE_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

class CircleShape {
public:
    int x;
    int y;
    int r;

    std::string key = "circle";

    void Set(const std::vector<int>& coordinates)
    {
        this->x = coordinates[0];
        this->y = coordinates[1];
        this->r = coordinates[2];
    }
};

#endif