#include <math.h>
#include <cstring>
#include "matrix_handler.h"
#include "point_controller.h"

float *multiply_matrix(float matrix[4][4], float vector[4])
{
    float product_matrix[4] = {0};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            product_matrix[i] += matrix[i][j] * vector[j];
        }
    }

    // preserve array after function going out of scope
    float *return_matrix = new float[4];
    std::memcpy(return_matrix, product_matrix, sizeof(product_matrix));
    return return_matrix;
}

float *transpose_matrix(float matrix[4][4])
{
    float transposed_matrix[4][4];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            transposed_matrix[i][j] = matrix[j][i];
        }
    }

    float *return_matrix = new float[16];
    std::memcpy(return_matrix, transposed_matrix, sizeof(transposed_matrix));
    return return_matrix;
}

float *multiply_matrices(float matrix_0[4][4], float matrix_1[4][4])
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

    float *return_matrix = new float[16];
    std::memcpy(return_matrix, product_matrix, sizeof(product_matrix));
    return return_matrix;
};

float *generate_rotation_matrix(float degrees)
{
    float cosine = cos(degrees * M_PI / 180);
    float sine = sin(degrees * M_PI / 180);
    float rotation_matrix[4][4] = {
        {cosine,0,     -sine, 0},
        {0,     1,     0,     0},
        {sine,  0,     cosine,0},
        {0,     0,     0,     1},
    };

    float *return_matrix = new float[16];
    std::memcpy(return_matrix, rotation_matrix, sizeof(rotation_matrix));
    return return_matrix;
}

float *generate_scaling_matrix(float scale)
{
    float scaling_matrix[4][4] = {
        {scale, 0,     0,     0},
        {0,     scale, 0,     0},
        {0,     0,     scale, 0},
        {0,     0,     0,     1},
    };

    float *return_matrix = new float[16];
    std::memcpy(return_matrix, scaling_matrix, sizeof(scaling_matrix));
    return return_matrix;
}

float *generate_translation_matrix(point_3d translation)
{
    float translation_matrix[4][4] = {
        {1,     0,     0,     translation.get_x()},
        {0,     1,     0,     translation.get_y()},
        {0,     0,     1,     translation.get_z()},
        {0,     0,     0,     1},
    };

    float *return_matrix = new float[16];
    std::memcpy(return_matrix, translation_matrix, sizeof(translation_matrix));
    return return_matrix;
}
