#include <vector>
#include <SDL2/SDL.h>
#include "common.h"

std::vector<float> interpolate(int i0, float d0, int i1, float d1)
{
    if (i0 == i1) {  // ex: vertical line
        return std::vector<float>(1, d0);
    }

    std::vector<float> values;
    const float a = (d1 - d0) / (i1 - i0);  // calculate a(essentially slope)
    float d = d0;
    for (int i = i0; i < i1; i++) {
        values.push_back(d);
        d += a;
    }

    return values;
}

int canvas_draw_pixel(SDL_Renderer *renderer, int x, int y)
{
    // TODO: implement common variables(screen dimensions, background color, etc.)
    int translated_x = (480/2) + x;
    int translated_y = (480/2) - y;
    return SDL_RenderDrawPoint(renderer, translated_x, translated_y);
}
