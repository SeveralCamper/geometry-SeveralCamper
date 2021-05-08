#ifndef TRIANGLE_SHAPE_
#define TRIANGLE_SHAPE_

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>

class TriangleShape {
public:
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    int ID;

    std::string key = "triangle";

    void Set(const std::vector<int>& coordinates)
    {
        this->x1 = coordinates[0];
        this->y1 = coordinates[1];
        this->x2 = coordinates[2];
        this->y2 = coordinates[3];
        this->x3 = coordinates[4];
        this->y3 = coordinates[5];
    }
};

#endif