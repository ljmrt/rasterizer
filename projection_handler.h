#include "point_controller.h"

// translate viewport coordinates to canvas coordinates
//
// @param x x position to translate
// @param y y position to translate
// @return translated coordinates
point_2d viewport_to_canvas(float x, float y);

// get the projection of a vertex(point_3d)
//
// @param vertex vertex to get the projection of
// @return projection
point_2d project_vertex(point_3d vertex);
