#include <SDL2/SDL.h>
#include "window_handler.h"
#include "point_controller.h"
#include "line_renderer.h"
#include "color_helper.h"
#include "projection_handler.h"
#include "object_collection.h"
#include <iostream>

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    initialize_window("rasterizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 480, window, renderer);

    // predefined common colors, TODO: move to color_helper.h
    rgb_color red(255, 0, 0);
    rgb_color green(0, 255, 0);
    rgb_color blue(0, 0, 255);
    rgb_color yellow(255, 255, 0);
    rgb_color purple(255, 0, 255);
    rgb_color cyan(0, 255, 255);
    
    object_model cube<8, 12>({point_3d(1, 1, 1),  // index of vertices
                              point_3d(-1, 1, 1),
                              point_3d(-1, -1, 1),
                              point_3d(1, -1, 1),
                              point_3d(1, 1, -1),
                              point_3d(-1, 1, -1),
                              point_3d(-1, -1, -1),
                              point_3d(1, -1, -1)},
                              
                             {triangle_3d(point_3d(0, 1, 2), rgb_color(red)),  // triangles represented by point_3d's with the indexes of the vertices
                              triangle_3d(point_3d(0, 2, 3), rgb_color(red)),
                              triangle_3d(point_3d(4, 0, 3), rgb_color(green)),
                              triangle_3d(point_3d(4, 3, 7), rgb_color(green)),
                              triangle_3d(point_3d(5, 4, 7), rgb_color(blue)),
                              triangle_3d(point_3d(5, 7, 6), rgb_color(blue)),
                              triangle_3d(point_3d(1, 5, 6), rgb_color(yellow)),
                              triangle_3d(point_3d(1, 6, 2), rgb_color(yellow)),
                              triangle_3d(point_3d(4, 5, 1), rgb_color(purple)),
                              triangle_3d(point_3d(4, 1, 0), rgb_color(purple)),
                              triangle_3d(point_3d(2, 6, 7), rgb_color(cyan)),
                              triangle_3d(point_3d(2, 7, 3), rgb_color(cyan))});
    
    object_instance cube_1(cube, point_3d(-1, 0, 3));
    render_object(renderer, cube_1);
    
    SDL_RenderPresent(renderer);
    
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
