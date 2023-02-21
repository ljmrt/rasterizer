#ifndef COMMON_H
#define COMMON_H

#include <vector>
#include <SDL2/SDL.h>

// get the intermediate values of two numbers
// d = f(i)
//
// @param i0 first i in equation
// @param d0 first d in equation
// @param i1 second i in equation
// @param d1 second d in equation
std::vector<int> interpolate(int i0, float d0, int i1, float d1);

// wrapper function for drawing functions(translates the pixels)
// uses the logical coordinate system(-screen_width/2 to screen_width/2, etc.)
// translates logical coordinate system to screen coordinate system for drawing
// necessary to set color using SDL_SetRenderDrawColor before usage
//
// @param renderer renderer to use in drawing
// @param x x position of the pixel to draw
// @param y y position of the pixel to draw
// @return success
int canvas_draw_pixel(SDL_Renderer *renderer, int x, int y);

#endif  // COMMON_H
