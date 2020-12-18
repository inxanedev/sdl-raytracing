#pragma once
#include <cmath>
class Vector2 {
    public:
        float x, y;
        Vector2(float x, float y) {
            set(x, y);
        }
        void set(float x, float y) {
            this->x = x;
            this->y = y;
        }
        float magSq() {
            return x * x + y * y;
        }
        float mag() {
            return sqrt(magSq());
        }
        void normalize() {
            float length = mag();
            if (length != 0) {
                x = x / length;
                y = y / length;
            }
        }
};
