#include "projection_handler.h"
#include "point_controller.h"

point_2d viewport_to_canvas(float x, float y)
{
    // TODO: implement global canvas/window and viewport size
    return point_2d(x * (480/1), y*(480/1));
}

point_2d project_vertex(point_3d vertex)
{
    // TODO: implement global viewport distance
    return viewport_to_canvas((vertex.get_x() * 1) / vertex.get_z(), (vertex.get_y() * 1) / vertex.get_z());
}
