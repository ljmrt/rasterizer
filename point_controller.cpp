#include "point_controller.h"

point_2d::point_2d()
{
    // default to 0
    x = 0;
    y = 0;
}

point_2d::point_2d(int source_x, int source_y)
{
    x = source_x;
    y = source_y;
}

int point_2d::get_x()
{
    return x;
}

int point_2d::get_y()
{
    return y;
}

void point_2d::set_x(int source_x)
{
    x = source_x;
}

void point_2d::set_y(int source_y)
{
    y = source_y;
}

point_3d::point_3d()
{
    x = 0;
    y = 0;
    z = 0;
}

point_3d::point_3d(float source_x, float source_y, float source_z)
{
    x = source_x;
    y = source_y;
    z = source_z;
}

float point_3d::get_x()
{
    return x;
}

float point_3d::get_y()
{
    return y;
}

float point_3d::get_z()
{
    return z;
}

void point_3d::set_x(float source_x)
{
    x = source_x;
}

void point_3d::set_y(float source_y)
{
    y = source_y;
}

void point_3d::set_z(float source_z)
{
    z = source_z;
}

point_3d sum_3d(point_3d point_0, point_3d point_1)
{
    return point_3d(point_0.get_x() + point_1.get_x(),
                    point_0.get_y() + point_1.get_y(),
                    point_0.get_z() + point_1.get_z());
}

point_3d multiply_3d(point_3d point_0, float constant)
{
    return point_3d(point_0.get_x() * constant,
                    point_0.get_y() * constant,
                    point_0.get_z() * constant);
}
