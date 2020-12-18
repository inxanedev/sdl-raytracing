#pragma once
#include "Vector2.hpp"

class Boundary {
    public:
        Vector2 a, b;
        Boundary(float x1, float y1, float x2, float y2)
            : a(x1, y1), b(x2, y2) {}
        Boundary() :a(0, 0), b(0, 0) {}
};
