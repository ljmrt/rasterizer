#include <math.h>
#include "matrix_handler.h"
#include "point_controller.h"

float *multiply_matrix(float *matrix, float *vector)
{
    float product_matrix[4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            product_matrix[i] += matrix[i][j] * vector[j];
        }
    }

    return product_matrix;
}

float *transpose_matrix(float *matrix)
{
    float transposed_matrix[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transposed_matrix[i][j] = matrix[j][i];
        }
    }

    return transposed_matrix;
}

float *multiply_matrices(float *matrix_0, float *matrix_1)
{
    float product_matrix[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            float result = 0;
            for (int k = 0; k < 4; k++) {
                result += matrix_0[i][k] * matrix_1[k][j];
            }
            product_matrix[i][j] = result;
        }
    }

    return product_matrix;
};

float *generate_rotation_matrix(float degrees)
{
    float cos = cos(degrees * PI / 180);
    float sin = sin(degrees * PI / 180);
    return float[4][4] {
        {cos,   0,     -sin,  0},
        {0,     1,     0,     0},
        {sin,   0,     cos,   0},
        {0,     0,     0,     1},
    };
}

float *generate_scaling_matrix(float scale)
{
    return float[4][4] {
        {scale, 0,     0,     0},
        {0,     scale, 0,     0},
        {0,     0,     scale, 0},
        {0,     0,     0,     1},
    };
}

float *generate_translation_matrix(point_3d translation)
{
    return float[4][4] {
        {1,     0,     0,     translation.get_x()},
        {0,     1,     0,     translation.get_y()},
        {0,     0,     1,     translation.get_z()},
        {0,     0,     0,     1},
    };
}

float *generate_camera_matrix(float *orientation, point_3d position)
{
    float orientation_matrix[4][4] = transpose_matrix(orientation);
    float position_matrix[4][4] = generate_translation_matrix(multiply_3d(position, -1));
    
    return multiply_matrices(orientation_matrix, position_matrix);
}
