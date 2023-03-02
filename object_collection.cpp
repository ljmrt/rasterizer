#include <algorithm>
#include <iterator>
#include <SDL2/SDL.h>
#include "object_collection.h"
#include "point_controller.h"
#include "line_renderer.h"
#include "color_helper.h"
#include "projection_handler.h"
#include <iostream>

triangle_3d::triangle_3d()
{
    // default all position values to 1337 and color to (0, 0, 0)
    points = point_3d(1337, 1337, 1337);
    color = rgb_color(0, 0, 0);
}

triangle_3d::triangle_3d(point_3d source_points, rgb_color source_color)
{
    points = source_points;
    color = source_color;
}

point_3d triangle_3d::get_points()
{
    return points;
}

rgb_color triangle_3d::get_color()
{
    return color;
}

void triangle_3d::set_points(point_3d source_points)
{
    points = source_points;
}

void triangle_3d::set_color(rgb_color source_color)
{
    color = source_color;
}

object_model::object_model(point_3d source_vertices[], triangle_3d source_triangles[])
{
    std::copy(source_vertices, source_vertices + this.get_vertices_size(), vertices);
    std::copy(source_triangles, source_triangles + this.get_triangles_size(), triangles);
}

point_3d *object_model::get_vertices()
{
    return vertices;
}

int object_model::get_vertices_size()
{
    return Tvertices_size;
}

triangle_3d *object_model::get_triangles()
{
    return triangles;
}

int object_model::get_triangles_size()
{
    return Ttriangles_size;
}

void object_model::set_vertices(point_3d source_vertices[])
{
    std::copy(source_vertices, source_vertices + this.get_vertices_size(), vertices);
}

void object_model::set_triangles(triangle_3d source_triangles[])
{
    std::copy(source_triangles, source_triangles + this.get_triangles_size(), triangles);
}

// predefined models
// copy over from main.cpp

object_instance::object_instance(object_model source_model, point_3d source_position)
{
    model = source_model;
    position = source_position;
}

object_model object_instance::get_model()
{
    return model;
}

struct transform object_instance::get_transformation()
{
    return transformation;
}

void object_instance::set_model(object_model source_model)
{
    model = source_model;
}

void object_instance::set_transformation(struct transform source_transformation)
{
    tranformation = source_transformation;
}

void render_triangle(SDL_Renderer *renderer, triangle_3d target_triangle, point_2d projected[])
{
    // note: triangles are represented as point_3d's to prevent duplicate code
    draw_wireframe_triangle(renderer,
                            projected[(int)(target_triangle.get_points().get_x())],
                            projected[(int)(target_triangle.get_points().get_y())],
                            projected[(int)(target_triangle.get_points().get_z())],
                            target_triangle.get_color());
}

void render_model(SDL_Renderer *renderer, object_model target_model, struct transform target_transformation)
{
    int target_vertices_size = target_model.get_vertices_size();
    int target_triangles_size = target_model.get_triangles_size();
    // create projected index
    point_2d projected[target_vertices_size];
    for (int i = 0; i < target_vertices_size; i++) {
        point_3d index_vertice = sum_3d(target_model.get_vertices()[i], target_transformation.position);
        projected[i] = project_vertex(index_vertice);
    }
    // render using projected index
    for (int i = 0; i < target_triangles_size; i++) {        
        render_triangle(renderer, target_model.get_triangles()[i], projected);
    }
}

void render_scene(SDL_Renderer *renderer, object_instance target_instance)  // TODO: scene linked list or vector
{
    struct transform camera_matrix =;
    struct transform instance_transformation =;

    render_model(renderer, target_instance.get_model(), instance_transformation);
}
