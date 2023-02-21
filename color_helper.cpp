#include "color_helper.h"

rgb_color::rgb_color(float source_r, float source_g, float source_b)
{
    r = source_r;
    g = source_g;
    b = source_b;
}

float rgb_color::get_r()
{
    return r;
}

float rgb_color::get_g()
{
    return g;
}

float rgb_color::get_b()
{
    return b;
}

void rgb_color::set_r(float source_r)
{
    r = source_r;
}

void rgb_color::set_g(float source_g)
{
    g = source_g;
}

void rgb_color::set_b(float source_b)
{
    b = source_b;
}
