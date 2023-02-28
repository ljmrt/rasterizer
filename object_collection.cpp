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
    // default all position values to 1337
    point_3d default_vertices[128];
    triangle_3d default_triangles[128];
    for (int i = 0; i < 128; i++) {
        default_vertices[i].set_x(1337);
        default_vertices[i].set_y(1337);
        default_vertices[i].set_z(1337);

        default_triangles[i].set_points(default_vertices[i]);
        default_triangles[i].set_color(rgb_color(0, 0, 0));
    }
    set_vertices(default_vertices, 128);
    set_triangles(default_triangles, 128);
}

object_model::object_model(point_3d source_vertices[], triangle_3d source_triangles[])
{
    std::copy(source_vertices, source_vertices+128, vertices);
    std::copy(source_triangles, source_triangles+128, triangles);
}

point_3d *object_model::get_vertices()
{
    return vertices;
}

triangle_3d *object_model::get_triangles()
{
    return triangles;
}

void object_model::set_vertices(point_3d source_vertices[], int vertices_length)
{
    std::copy(source_vertices, source_vertices + vertices_length, vertices);
}

void object_model::set_triangles(triangle_3d source_triangles[], int triangles_length)
{
    std::copy(source_triangles, source_triangles + triangles_length, triangles);
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

point_3d object_instance::get_position()
{
    return position;
}

void object_instance::set_model(object_model source_model)
{
    model = source_model;
}

void object_instance::set_position(point_3d source_position)
{
    position = source_position;
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

void render_object(SDL_Renderer *renderer, object_instance target_instance)
{
    // create projected index
    point_2d projected[128];
    object_model instance_model = target_instance.get_model();
    for (int i = 0; i < 128; i++) {  // TODO: implement proper array size
        if (instance_model.get_vertices()[i].get_x() == 1337) {
            break;
        }
        point_3d index_vertice = sum_3d(instance_model.get_vertices()[i], target_instance.get_position());
        projected[i] = project_vertex(index_vertice);
    }
    // render using projected index
    for (int i = 0; i < 128; i++) {  // TODO: implement standalone triangle color
        if (instance_model.get_triangles()[i].get_points().get_x() == 1337) {
            break;
        }
        render_triangle(renderer, instance_model.get_triangles()[i], projected);
    }
}
