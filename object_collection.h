#ifndef OBJECT_COLLECTION_H
#define OBJECT_COLLECTION_H

#include <SDL2/SDL.h>
#include "point_controller.h"

class object_model
{
    private:
        point_3d vertices[128];
        point_3d triangles[128];  // triangles are stored with indexes of vertices
    public:
        object_model();
        object_model(point_3d source_vertices[], point_3d source_triangles[]);
        point_3d *get_vertices();
        point_3d *get_triangles();
        void set_vertices(point_3d source_vertices);
        void set_triangles(point_3d source_triangles);
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

object_model cube();

// render a 3D triangle using a index of projected vertices
//
// @param renderer SDL renderer to use when drawing
// @param target_triangle 3-dimensional triangle to render
// @param projected index of projected vertices
void render_triangle(SDL_Renderer *renderer, point_3d target_triangle, point_2d projected[]);

// render a 3D object instance
//
// @param renderer SDL renderer to use when drawing
// @param target_instance instance to render
void render_object(SDL_Renderer *renderer, object_instance target_instance);

// TODO
// void render_scene();

#endif  // OBJECT_COLLECTION_H
