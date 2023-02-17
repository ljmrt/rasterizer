#include <cstdlib>
#include <iostream>
#include <SDL2/SDL.h>
#include "line_renderer.h"
#include "point_controller.h"
#include "common.h"

void draw_line(SDL_Renderer* renderer, point_2d point_0, point_2d point_1)  // TODO: refactor and implement bresenham's algorithm
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

    int x0 = point_0.get_x();
    int y0 = point_0.get_y();
    int x1 = point_1.get_x();
    int y1 = point_1.get_y();
    // if the change in x is bigger than the change in y(line is more horizontal)
    if (abs(x1 - x0) > abs(y1 - y0)) {
        // ensure x0 < x1
        if (x0 > x1) {
            std::swap(x0, x1);
        }

        std::vector<int> ys = interpolate(x0, y0, x1, y1);
        for (auto x = x0; x < x1; x++) {
            // translate coordinates to proper system
            int translated_x = (480/2) + x;
            int translated_y = (480/2) - ys.at(x - x0);
            SDL_RenderDrawPoint(renderer, translated_x, translated_y);
        }
    } else {  // line is more vertical
        // ensure y0 < y1
        if (y0 > y1) {
            std::swap(y0, y1);
        }

        std::vector<int> xs = interpolate(y0, x0, y1, x1);
        for (auto y = y0; y < y1; y++) {
            // translate coordinates to proper system
            int translated_x = (480/2) + y;
            int translated_y = (480/2) - xs.at(y - y0);
            SDL_RenderDrawPoint(renderer, translated_x, translated_y);
        }
    }
}

void draw_wireframe_triangle(SDL_Renderer* renderer, point_2d point_0, point_2d point_1, point_2d point_2)
{
    draw_line(renderer, point_0, point_1);
    draw_line(renderer, point_1, point_2);
    draw_line(renderer, point_2, point_0);
}
