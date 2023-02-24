#include <SDL2/SDL.h>
#include "window_handler.h"
#include "point_controller.h"
#include "line_renderer.h"
#include "color_helper.h"
#include "projection_handler.h"

int main()
{
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    initialize_window("rasterizer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 480, 480, window, renderer);

    // four "front" vertices of the cube
    point_3d vertex_fa(-2, -0.5, 3);
    point_3d vertex_fb(-2, 0.5, 3);
    point_3d vertex_fc(-1, 0.5, 3);
    point_3d vertex_fd(-1, -0.5, 3);

    // four "back" vertices of the cube
    point_3d vertex_ba(-2, -0.5, 4);
    point_3d vertex_bb(-2, 0.5, 4);
    point_3d vertex_bc(-1, 0.5, 4);
    point_3d vertex_bd(-1, -0.5, 4);

    rgb_color red(255, 0, 0);
    rgb_color green(0, 255, 0);
    rgb_color blue(0, 0, 255);

    // TODO: implement wrapper function
    // "front" face
    draw_line(renderer, project_vertex(vertex_fa), project_vertex(vertex_fb), blue);
    draw_line(renderer, project_vertex(vertex_fb), project_vertex(vertex_fc), blue);
    draw_line(renderer, project_vertex(vertex_fc), project_vertex(vertex_fd), blue);
    draw_line(renderer, project_vertex(vertex_fd), project_vertex(vertex_fa), blue);

    // "back" face
    draw_line(renderer, project_vertex(vertex_ba), project_vertex(vertex_bb), red);
    draw_line(renderer, project_vertex(vertex_bb), project_vertex(vertex_bc), red);
    draw_line(renderer, project_vertex(vertex_bc), project_vertex(vertex_bd), red);
    draw_line(renderer, project_vertex(vertex_bd), project_vertex(vertex_ba), red);

    // "front to back" edges
    draw_line(renderer, project_vertex(vertex_fa), project_vertex(vertex_ba), green);
    draw_line(renderer, project_vertex(vertex_fb), project_vertex(vertex_bb), green);
    draw_line(renderer, project_vertex(vertex_fc), project_vertex(vertex_bc), green);
    draw_line(renderer, project_vertex(vertex_fd), project_vertex(vertex_bd), green);

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
