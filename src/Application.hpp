#pragma once
#include <SDL2/SDL.h>
#include "Particle.hpp"
#include "Boundary.hpp"
#include "Ray.hpp"
#include <SDL2/SDL_render.h>
#include <cstdlib>
#include <ctime>
class Application {
    public:
        Application() {
            SDL_CreateWindowAndRenderer(600, 600, (Uint32)NULL, &window, &renderer);
            srand(time(NULL));
            int i;
            for (i = 0; i < 5; i++) {
                walls[i] = Boundary(rand() % 600, rand() % 600, rand() % 600, rand() % 600);
            }
            walls[5] = Boundary(0, 0, 600, 0);
            walls[6] = Boundary(0, 0, 0, 600);
            walls[7] = Boundary(0, 600, 600, 600);
            walls[8] = Boundary(600, 0, 600, 600);
            particle = Particle();
            particle.set_renderer(renderer);            
        }
        void loop() {
            bool running = true;
            while (running) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
                SDL_RenderClear(renderer);
                while (SDL_PollEvent(&event) > 0) {
                    switch (event.type) {
                        case SDL_QUIT:
                            running = false;
                            break;
                        case SDL_MOUSEMOTION:
                            particle.update(event.motion.x, event.motion.y);
                            break;
                        default:
                            break;
                    }
                }
                // Drawing
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                for (int i = 0; i < 5 + 4; i++) {
                    draw_line(walls[i].a.x, walls[i].a.y, walls[i].b.x, walls[i].b.y);
                }
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
                particle.look(walls, 5 + 4);
                // Update screen and delay
                SDL_RenderPresent(renderer);
                SDL_Delay(10);
            }
        }
        void draw_line(float x1, float y1, float x2, float y2) {
            SDL_RenderDrawLine(renderer, x1, y1, x2, y2); 
        }
        SDL_Renderer* get_renderer() {
            return renderer;
        }
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Event event;
        Boundary walls[5 + 4];
        Particle particle;
};
