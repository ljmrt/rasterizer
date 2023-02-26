#include <algorithm>
#include <SDL2/SDL.h>
#include "object_collection.h"
#include "point_controller.h"
#include "line_renderer.h"
#include "color_helper.h"

object_model::object_model()
{
    // default all values to 0
    point_3d default_values[128];
    for (point_3d i : default_values) {
        default_values[i] = 0;
    }
    set_vertices(default_values);
    set_triangles(default_values);
}

object_model::object_model(point_3d source_vertices[], point_3d source_triangles[])
{
    std::copy(source_vertices, source_vertices+128, vertices);
    std::copy(source_triangles, source_triangles+128, triangles);
}

point_3d *object_model::get_vertices()
{
    return vertices;
}

point_3d *object_model::get_triangles()
{
    return triangles;
}

void object_model::set_vertices(point_3d source_vertices[])
{
    std::copy(source_vertices, source_vertices+128, vertices);
}

void object_model::set_triangles(point_3d source_triangles[])
{
    std::copy(source_vertices, source_vertices+128, vertices);
}

// predefined models
cube.set_vertices({{1, 1, 1}, {-1, 1, 1}, {-1, -1, 1}, {1, -1, 1}, {1, 1, -1}, {-1, 1, -1}, {-1, -1, -1}, {1, -1, -1}}});
cube.set_triangles({{0, 1, 2}, {0, 2, 3}, {4, 0, 3}, {4, 3, 7}, {5, 4, 7}, {5, 7, 6}, {1, 5, 6}, {1, 6, 2}, {4, 5, 1}, {4, 1, 0}, {2, 6, 7}, {2, 7, 3}});

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

void render_triangle(SDL_Renderer *renderer, point_3d target_triangle, point_2d projected[])
{
    // note: triangles are represented as point_3d's to prevent duplicate code
    draw_wireframe_triangle(renderer,
                            projected[target_triangle.get_x()],
                            projected[target_triangle.get_y()],
                            projected[target_triangle.get_z()],
                            rgb_color(255, 0, 0));
}

void render_object(SDL_Renderer *renderer, object_instance target_instance)
{
    // create projected index
    point_2d projected = [];
    for (int i = 0; i < 128; i++) {  // TODO: implement proper array size
        projected[i] = project_vertex(object_instance.get_vertices[i]);
    }
    // render usng projected index
    for (point_3d i : object_instance.get_triangles()) {  // TODO: implement standalone triangle color
        render_triangle(renderer, i, projected);
    }
}
