#include <SDL2/SDL.h>
#include "window_handler.h"
#include "point_controller.h"
#include "line_renderer.h"

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    initialize_window("rasterizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 480, window, renderer);

    point_2d from_point_0(-200, -100);
    point_2d to_point_0(240, 120);
    point_2d from_point_1(-500, -200);
    point_2d to_point_1(60, 240);
    draw_line(renderer, from_point_0, to_point_0);
    draw_line(renderer, from_point_1, to_point_1);

    // keep the window open
    SDL_Event poll_event;
    while (1 < 2) {
        SDL_PollEvent(&poll_event);
        if (poll_event.key.keysym.sym == SDLK_ESCAPE) break;  // if escape key pressed
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
