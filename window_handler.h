#include <iostream>
#include <SDL2/SDL.h>

// initialize a blank(white) window with the given arguments
//
// @param window_name name of the window
// @param window_x x of the window
// @param window_y y of the window
// @param window_width width of the window
// @param window_height height of the window
// @param window reference to the window
// @param renderer reference to the renderer
// @return success
int initialize_window(std::string window_name, int window_x, int window_y, int window_width, int window_height, SDL_Window*& window, SDL_Renderer*& renderer);
