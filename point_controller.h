#ifndef POINT_CONTROLLER_H
#define POINT_CONTROLLER_H

class point_2d
{
    private:
        int x;
        int y;
    public:
        point_2d();  // constructor
        point_2d(int source_x, int source_y);  // constructor
        // TODO point_2d(const point_2d& source_point);  // copy constructor
        // accessor functions
        int get_x();
        int get_y();
        void set_x(int source_x);
        void set_y(int source_y);
};

class point_3d
{
    private:
        float x;
        float y;
        float z;
    public:
        point_3d();  // constructor
        point_3d(float source_x, float source_y, float source_z);  // constructor
        // accessor functions
        float get_x();
        float get_y();
        float get_z();
        void set_x(float source_x);
        void set_y(float source_y);
        void set_z(float source_z);
};

// get the sum of two point_3d's
//
// @param point_0 point to add
// @param point_1 point to add
// @return sum of points
point_3d sum_3d(point_3d point_0, point_3d point_1);

#endif  // POINT_CONTROLLER_H
