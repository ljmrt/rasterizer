#include "point_controller.h"

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

// TODO: implement line_2d functions

point_3d::point_3d(int source_x, int source_y, int source_z)
{
    x = source_x;
    y = source_y;
    z = source_z;
}

int point_3d::get_x()
{
    return x;
}

int point_3d::get_y()
{
    return y;
}

int point_3d::get_z()
{
    return z;
}

void point_3d::set_x(int source_x)
{
    x = source_x;
}

void point_3d::set_y(int source_y)
{
    y = source_y;
}

void point_3d::set_z(int source_z)
{
    z = source_z;
}
