#include <algorithm>
#include <iterator>
#include <cstring>
#include <SDL2/SDL.h>
#include "object_collection.h"
#include "point_controller.h"
#include "line_renderer.h"
#include "color_helper.h"
#include "projection_handler.h"
#include <iostream>
#include "matrix_handler.h"

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

void render_model(SDL_Renderer *renderer, object_model target_model, float target_transformation[4][4])
{
    int target_vertices_size = target_model.get_vertices().size();
    int target_triangles_size = target_model.get_triangles().size();
    // create projected index
    point_2d projected[target_vertices_size];
    for (int i = 0; i < target_vertices_size; i++) {
        point_3d vertex = target_model.get_vertices()[i];
        float vertex_4d[4] = {vertex.get_x(), vertex.get_y(), vertex.get_z(), 1};
        std::memcpy(vertex_4d, multiply_matrix(target_transformation, vertex_4d), 16);
        point_3d transformed_vertex(vertex_4d[0], vertex_4d[1], vertex_4d[2]);
        
        projected[i] = project_vertex(transformed_vertex);
    }
    // render using projected index
    for (int i = 0; i < target_triangles_size; i++) {        
        render_triangle(renderer, target_model.get_triangles()[i], projected);
    }
}

void render_scene(SDL_Renderer *renderer, object_instance target_instance)  // TODO: scene linked list or vector
{
    struct transform target_transformation = target_instance.get_transformation();

    // excessive std::memcpy's due to bad matrix implementation
    // I thought simply using arrays instead of a dedicated matrix implementation for my use would be easier...
    float camera_orientation[4][4]; std::memcpy(camera_orientation, generate_rotation_matrix(0.0), 64);
    point_3d camera_position(0, 0, 0);

    float transposed_orientation[4][4]; std::memcpy(transposed_orientation, transpose_matrix(camera_orientation), 64);
    float translated_position[4][4]; std::memcpy(translated_position, generate_translation_matrix(multiply_3d(camera_position, -1)), 64);
    float camera_matrix[4][4]; std::memcpy(camera_matrix,
                                           multiply_matrices(transposed_orientation, translated_position),
                                           64);
    
    float rotation_matrix[4][4]; std::memcpy(rotation_matrix, generate_rotation_matrix(target_transformation.rotation), 64);
    float scaling_matrix[4][4]; std::memcpy(scaling_matrix, generate_scaling_matrix(target_transformation.scale), 64);
    float translation_matrix[4][4]; std::memcpy(translation_matrix, generate_translation_matrix(target_transformation.translation), 64);
    float rotation_scaling_matrix[4][4]; std::memcpy(rotation_scaling_matrix, multiply_matrices(rotation_matrix, scaling_matrix), 64);
    float transformation_matrix[4][4]; std::memcpy(transformation_matrix, multiply_matrices(rotation_scaling_matrix, translation_matrix), 64);

    float camera_transformation_matrix[4][4]; std::memcpy(camera_transformation_matrix, multiply_matrices(camera_matrix, transformation_matrix), 64);
    
    render_model(renderer, target_instance.get_model(), camera_transformation_matrix);
}
