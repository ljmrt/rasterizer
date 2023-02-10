#include <SDL2/SDL.h>
#include <iostream>

int main()
{
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    
    int init_result = SDL_Init(SDL_INIT_VIDEO);
    if (init_result < 0) {
        std::cout << "sdl initialization error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow(
            "rasterizer",
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            480, 480,
            SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cout << "window creation error: " << SDL_GetError() << std::endl;
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
    if (renderer == nullptr) {
        std::cout << "renderer creation error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // fill window with white
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer);
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
