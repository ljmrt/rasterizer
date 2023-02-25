#ifndef OBJECT_COLLECTION_H
#define OBJECT_COLLECTION_H

#include <SDL2/SDL.h>
#include "point_controller.h"

class object_model  // TODO: effectively implement vertices(if needed)
{
    private:
        point_3d triangles[128];  // note: keep in mind this limitation
    public:
        object_model();
        object_model(point_3d source_triangles[]);
        point_3d get_triangle(int index);
};

class object_instance
{
    private:
        object_model model;
        point_3d position;
    public:
        object_instance(object_model source_model, point_3d source_position);
        object_model get_model();
        point_3d get_position();
        void set_model(object_model source_model);
        void set_position(point_3d source_position);
};

// render a 3D triangle on the screen
//
// @param renderer SDL renderer to use when drawing
// @param triangle_3d projection of 3-dimensional triangle
void render_triangle(SDL_Renderer *renderer, point_3d projected_triangle);

// render a 3D object instance
//
// @param renderer SDL renderer to use when drawing
// @param target_instance instance to render
void render_object(SDL_Renderer *renderer, object_instance target_instance);

// TODO
// void render_scene();

#endif  // OBJECT_COLLECTION_H
