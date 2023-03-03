#ifndef OBJECT_COLLECTION_H
#define OBJECT_COLLECTION_H

#include <SDL2/SDL.h>
#include "point_controller.h"
#include "color_helper.h"

class triangle_3d
{
private:
    point_3d points;
    rgb_color color;
public:
    triangle_3d();
    triangle_3d(point_3d source_points, rgb_color source_color);
    point_3d get_points();
    rgb_color get_color();
    void set_points(point_3d source_points);
    void set_color(rgb_color source_color);
};

class object_model
{
    private:
        std::vector<point_3d> vertices;
        std::vector<triangle_3d> triangles;  // triangles are stored with indexes of vertices
    public:
        object_model();
        object_model(std::vector<point_3d> source_vertices, std::vector<triangle_3d> source_triangles);
        std::vector<point_3d> get_vertices();
        std::vector<triangle_3d> get_triangles();
        void set_vertices(std::vector<point_3d> source_vertices);
        void set_triangles(std::vector<triangle_3d> source_triangles);
};

struct transform {
    float scale;
    float rotation;  // rotation around the Y axis
    point_3d position;
};

class object_instance
{
    private:
        object_model model;
        struct transform transformation;
    public:
        object_instance(object_model source_model, struct transform source_transformation);
        object_model get_model();
        struct transform get_transformation();
        void set_model(object_model source_model);
        void set_transformation(struct transform source_transformation);
};

// object_model cube();

// render a 3D triangle using a index of projected vertices
//
// @param renderer SDL renderer to use when drawing
// @param target_triangle 3-dimensional triangle to render
// @param projected index of projected vertices
void render_triangle(SDL_Renderer *renderer, point_3d target_triangle, point_2d projected[]);

// render a 3D model
//
// @param renderer SDL renderer to use when drawing
// @param target_model model to render
// @param target_transformation transformation of the model's instance
void render_model(SDL_Renderer *renderer, object_model target_model, float* target_transformation);

// render a 3D scene
// note: scene linked list not yet implemented: renders object_instances
//
// @param renderer SDL renderer to use when drawing
// @param target_instance instance to render
void render_scene(SDL_Renderer *renderer, object_instance target_instance);

#endif  // OBJECT_COLLECTION_H
