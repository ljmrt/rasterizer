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
    point_3d vertex_fa(-1, 1, 1);
    point_3d vertex_fb(1, 1, 1);
    point_3d vertex_fc(1, -1, 1);
    point_3d vertex_fd(-1, -1, 1);

    // four "back" vertices of the cube
    point_3d vertex_ba(-1, 1, 2);
    point_3d vertex_bb(1, 1, 2);
    point_3d vertex_bc(1, -1, 2);
    point_3d vertex_bd(-1, -1, 2);

    rgb_color black(0, 0, 0);

    // TODO: implement wrapper function
    // "front" face
    draw_line(renderer, project_vertex(vertex_fa), project_vertex(vertex_fb), black);
    draw_line(renderer, project_vertex(vertex_fb), project_vertex(vertex_fc), black);
    draw_line(renderer, project_vertex(vertex_fc), project_vertex(vertex_fd), black);
    draw_line(renderer, project_vertex(vertex_fd), project_vertex(vertex_fa), black);

    // "back" face
    draw_line(renderer, project_vertex(vertex_ba), project_vertex(vertex_bb), black);
    draw_line(renderer, project_vertex(vertex_bb), project_vertex(vertex_bc), black);
    draw_line(renderer, project_vertex(vertex_bc), project_vertex(vertex_bd), black);
    draw_line(renderer, project_vertex(vertex_bd), project_vertex(vertex_ba), black);

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
