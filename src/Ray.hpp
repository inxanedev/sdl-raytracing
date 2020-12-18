#pragma once
#include "Boundary.hpp"
#include "Vector2.hpp"
#include <cmath>
#include "SDL2/SDL.h"
#include <iostream>
class Ray {
    public:
        Vector2 direction;
        int counter = 0;
        Ray(float angle)
            : direction(cos(angle), sin(angle)) {}
        Ray() : direction(0, 0) {}
        Vector2 cast(const Vector2& pos, Boundary wall) {
            float x1 = wall.a.x;
            float y1 = wall.a.y;
            float x2 = wall.b.x;
            float y2 = wall.b.y;

            float x3 = pos.x;
            float y3 = pos.y;
            float x4 = pos.x + direction.x;
            float y4 = pos.y + direction.y;
            
            float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
            if (den == 0) {
                return Vector2(-1000000, -1000000);
            }
            float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
            float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
            
            if (t > 0 && t < 1 && u > 0) {
                return Vector2(x1 + t * (x2 - x1), y1 + t * (y2 - y1));
            } else {
                return Vector2(-1000000, -1000000);
            }
        }
};
