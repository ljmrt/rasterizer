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

object_model::object_model()
{
    vertices.push_back(point_3d(0, 0, 0));
    triangles.push_back(triangle_3d(point_3d(0, 0, 0), rgb_color(0, 0, 0)));
}

object_model::object_model(std::vector<point_3d> source_vertices, std::vector<triangle_3d> source_triangles)
{
    vertices = source_vertices;
    triangles = source_triangles;
}

std::vector<point_3d> object_model::get_vertices()
{
    return vertices;
}

std::vector<triangle_3d> object_model::get_triangles()
{
    return triangles;
}

void object_model::set_vertices(std::vector<point_3d> source_vertices)
{
    vertices = source_vertices;
}

void object_model::set_triangles(std::vector<triangle_3d> source_triangles)
{
    triangles = source_triangles;
}

// predefined models
// copy over from main.cpp

object_instance::object_instance(object_model source_model, struct transform source_transformation)
{
    model = source_model;
    transformation = source_transformation;
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
    transformation = source_transformation;
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
    int target_vertices_size = target_model.get_vertices().size();
    int target_triangles_size = target_model.get_triangles().size();
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
    render_model(renderer, target_instance.get_model(), target_instance.get_transformation());
}
