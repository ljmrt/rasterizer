#include <SDL2/SDL.h>
#include "window_handler.h"
#include "point_controller.h"
#include "line_renderer.h"
#include "color_helper.h"
#include "projection_handler.h"
#include "object_collection.h"
#include <ostream>

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    initialize_window("rasterizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 480, window, renderer);

    object_model cube;
    point_3d set_vertices[] = {point_3d(1, 1, 1),  // index of vertices
                               point_3d(-1, 1, 1),
                               point_3d(-1, -1, 1),
                               point_3d(1, -1, 1),
                               point_3d(1, 1, -1),
                               point_3d(-1, 1, -1),
                               point_3d(-1, -1, -1),
                               point_3d(1, -1, -1)};
    point_3d set_triangles[] = {point_3d(0, 1, 2),  // triangles represented by point_3d's with the indexes of the vertices
                                point_3d(0, 2, 3),
                                point_3d(4, 0, 3),
                                point_3d(4, 3, 7),
                                point_3d(5, 4, 7),
                                point_3d(5, 7, 6),
                                point_3d(1, 5, 6),
                                point_3d(1, 6, 2),
                                point_3d(4, 5, 1),
                                point_3d(4, 1, 0),
                                point_3d(2, 6, 7),
                                point_3d(2, 7, 3)};
    
    cube.set_vertices(set_vertices);
    cube.set_triangles(set_triangles);
    
    object_instance cube_1(cube, point_3d(0, 0, 0));
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
