#include <algorithm>
#include <SDL2/SDL.h>
#include "object_collection.h"
#include "point_controller.h"

object_model::object_model()
{
    // initialize to 0
    for (point_3d i : triangles) {
        i.set_x(0);
        i.set_y(0);
    }
}

object_model::object_model(point_3d source_triangles[])
{
    std::copy(source_triangles, source_triangles+128, triangles);
}

point_3d object_model::get_triangle(int index)
{
    return triangles[index];
}

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

void render_triangle(SDL_Renderer *renderer, point_3d projected_triangle)
{

}

void render_object(SDL_Renderer *renderer, object_instance target_instance)
{

}
