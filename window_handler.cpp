#include <iostream>
#include <SDL2/SDL.h>
#include "window_handler.h"

int initialize_window(std::string window_name, int window_x, int window_y, int window_width, int window_height, SDL_Window*& window, SDL_Renderer*& renderer)
{
    int init_result = SDL_Init(SDL_INIT_VIDEO);
    if (init_result < 0) {
        std::cout << "sdl initialization error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow(
            window_name.c_str(),
            window_x, window_y,
            window_width, window_height,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "window creation error: " << SDL_GetError() << std::endl;
        return 2;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == nullptr) {
        std::cout << "renderer initialization error: " << SDL_GetError() << std::endl;
        return 3;
    }

    // fill window with white
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    return 0;
}
