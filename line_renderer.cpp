#include <cstdlib>
#include <SDL2/SDL.h>
#include "line_renderer.h"
#include "point_controller.h"
#include "common.h"

void draw_line(SDL_Renderer* renderer, point_2d point_0, point_2d point_1)  // TODO: refactor and implement bresenham's algorithm
{
    SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);

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
            SDL_RenderDrawPoint(renderer, x, ys.at(x - x0));
        }
    } else {  // line is more vertical
        // ensure y0 < y1
        if (y0 > y1) {
            std::swap(y0, y1);
        }

        std::vector<int> xs = interpolate(x0, y0, x1, y1);
        for (auto y = y0; y < y1; y++) {
            SDL_RenderDrawPoint(renderer, y, xs.at(y - y0));
        }
    }
}
