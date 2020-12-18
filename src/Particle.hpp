#pragma once
#include "Vector2.hpp"
#include "Ray.hpp"
#include "Boundary.hpp"
#include <cmath>
#include "SDL2/SDL.h"
#include <iostream>


class Particle {
    public:
        Vector2 pos;
        Ray rays[360];
        SDL_Renderer* renderer;
        Particle() : pos(300, 300) {
            for (int angle = 0; angle < 360; angle++) {
                rays[angle] = Ray(angle * (3.1415926 / 180.0));
            }
        }
        void set_renderer(SDL_Renderer* renderer) {
            this->renderer = renderer;
        }
        void update(float x, float y) {
            pos.set(x, y);
        }
        void look(Boundary walls[], size_t count) {
            for (int i = 0; i < 360; i++) {
                Ray& ray = rays[i];
                Vector2 closest(-1000000, -1000000);
                float record = 100000000;
                for (int j = 0; j < count; j++) {
                    Vector2 pt = ray.cast(pos, walls[j]);
                    if (pt.x != -1000000 && pt.y != -1000000) {
                        Vector2 len = pos;
                        len.x -= pt.x;
                        len.y -= pt.y;
                        float length = len.mag();
                        if (length < record) {
                            record = length;
                            closest = pt;
                        }
                    }
                }
                if (closest.x != -1000000 && closest.y != -1000000) {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
                    SDL_RenderDrawLine(renderer, pos.x, pos.y, closest.x, closest.y);
                }
            }
        }
};
