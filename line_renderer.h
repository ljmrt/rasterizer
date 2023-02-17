#ifndef LINE_RENDERER_H
#define LINE_RENDERER_H

#include "point_controller.h"
#include "common.h"

// draw a line between the given points
//
// @param renderer renderer to use
// @param point_0 point to draw from
// @param point_1 point to draw to
void draw_line(SDL_Renderer* renderer, point_2d point_0, point_2d point_1);  // TODO: add color option and make param a line

#endif  // LINE_RENDERER_H
