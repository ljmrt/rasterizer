#ifndef LINE_RENDERER_H
#define LINE_RENDERER_H

#include "point_controller.h"
#include "common.h"
#include "color_helper.h"

// draw a line between the given points
//
// @param renderer renderer to use
// @param point_0 point to draw from
// @param point_1 point to draw to
// @param color color to use when drawing
void draw_line(SDL_Renderer* renderer, point_2d point_0, point_2d point_1, rgb_color color);

// draw a (black) wireframe triangle using the given points
//
// @param point_0 point to start/finish at
// @param point_1 point to draw to from point_0
// @param point_2 point to draw to from point_1, draws to point_0
// @param color color to use when drawing
void draw_wireframe_triangle(SDL_Renderer* renderer, point_2d point_0, point_2d point_1, point_2d point_2, rgb_color color);

// draw a filled triangle using the given points
//
// @param point_0 point to start/finish at
// @param point_1 point to draw to from point_0
// @param point_2 point to draw to from point_1, draws to point_0
// @param color color to use when filling
// @param h0 intensity of point_0
// @param h1 intensity of point_1
// @param h2 intensity of point_2
void draw_filled_triangle(SDL_Renderer* renderer, point_2d point_0, point_2d point_1, point_2d point_2, rgb_color color, float h0, float h1, float h2);

#endif  // LINE_RENDERER_H
