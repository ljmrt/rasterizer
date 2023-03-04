#ifndef MATRIX_HANDLER_H
#define MATRIX_HANDLER_H

#include "point_controller.h"

// note: functions not generic, specific implementation doesn't require it to be
// note: generates 4x4 matrices to maintain homogeneous coordinates

// get the product of a matrix and a vector
//
// @param matrix matrix to multiply by
// @param vector vector to multiply by
// @return product matrix of matrix and vector
float *multiply_matrix(float matrix[4][4], float vector[4]);

// transpose a matrix("swap" columns and rows)
//
// @param matrix matrix to transpose
// @return transposed matrix
float *transpose_matrix(float matrix[4][4]);

// get the product of two matrices
//
// @param matrix_0 first matrix to multiply by
// @param matrix_0 second matrix to multiply by
// @return product matrix of matrix and matrix
float *multiply_matrices(float matrix_0[4][4], float matrix_1[4][4]);

// generate a 4x4 uniform rotation matrix using the given degrees
//
// @param degrees degrees to rotate around the y-axis
// @return 4x4 matrix utilized in rotations
float *generate_rotation_matrix(float degrees);

// generate a 4x4 uniform scaling matrix using the given scale
//
// @param scale factor to scale by uniformly
// @return 4x4 matrix utilized in scaling
float *generate_scaling_matrix(float scale);

// generate a 4x4 translation matrix using the given translation
//
// @param translation amount to translate by
// @return 4x4 matrix utilized in translations
float *generate_translation_matrix(point_3d translation);

#endif  // MATRIX_HANDLER_H
