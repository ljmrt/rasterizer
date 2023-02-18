#ifndef LINE_RENDERER_H
#define LINE_RENDERER_H

#include "point_controller.h"
#include "common.h"

// draw a line between the given points
//
// @param renderer renderer to use
// @param point_0 point to draw from
// @param point_1 point to draw to
void draw_line(SDL_Renderer* renderer, point_2d point_0, point_2d point_1);  // TODO: add color option

// draw a (black) wireframe triangle using the given points
//
// @param point_0 point to start/finish at
// @param point_1 point to draw to from point_0
// @param point_2 point to draw to from point_1, draws to point_0
void draw_wireframe_triangle(SDL_Renderer* renderer, point_2d point_0, point_2d point_1, point_2d point_2);

// draw a filled triangle using the given points
//
// @param point_0 point to start/finish at
// @param point_1 point to draw to from point_0
// @param point_2 point to draw to from point_1, draws to point_0
void draw_filled_triangle(SDL_renderer* renderer, point_2d point_0, point_2d point_1, point_2d point_2);

#endif  // LINE_RENDERER_H
